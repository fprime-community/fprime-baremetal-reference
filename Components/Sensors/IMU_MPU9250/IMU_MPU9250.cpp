// ======================================================================
// \title  IMU_MPU9250.cpp
// \author ethanchee
// \brief  cpp file for IMU_MPU9250 component implementation class
// ======================================================================


#include <Components/Sensors/IMU_MPU9250/IMU_MPU9250.hpp>
#include <FpConfig.hpp>

namespace Sensors {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  IMU_MPU9250 ::
    IMU_MPU9250(
        const char *const compName
    ) : IMU_MPU9250ComponentBase(compName)
  {

  }

  IMU_MPU9250 ::
    ~IMU_MPU9250()
  {

  }

  void IMU_MPU9250 ::
    setup(I2cDevAddr::T devAddress) 
  {
    m_i2cDevAddress = devAddress;
  }

  void IMU_MPU9250 ::
    config()
  {
    U8 data[IMU_REG_SIZE_BYTES * 2];
    Fw::Buffer buffer(data, sizeof data);

    // Set gyro range to +-250 deg/s
    data[0] = GYRO_CONFIG_ADDR;
    data[1] = 0;

    Drv::I2cStatus status = write_out(0, m_i2cDevAddress, buffer);
    if (status != Drv::I2cStatus::I2C_OK) {
        // this->log_WARNING_HI_SetUpConfigError(status);
    }

    // Set accel range to +- 2g
    data[0] = ACCEL_CONFIG_ADDR;
    data[1] = 0;
    status =this-> write_out(0, m_i2cDevAddress, buffer);

    if (status != Drv::I2cStatus::I2C_OK) {
        // this->log_WARNING_HI_SetUpConfigError(status);
    }
  }

  Drv::I2cStatus IMU_MPU9250 ::
    setupReadRegister(U8 reg)
  {
    Fw::Buffer buffer(&reg, sizeof reg);
    return this->write_out(0, m_i2cDevAddress, buffer);
  }

  Drv::I2cStatus IMU_MPU9250 ::
    readRegisterBlock(U8 startRegister, Fw::Buffer& buffer)
  {
      Drv::I2cStatus status;
      status = this->setupReadRegister(startRegister);
      if (status == Drv::I2cStatus::I2C_OK) {
          status = this->read_out(0, m_i2cDevAddress, buffer);
      }
      return status;
  }

  Sensors::imuTlm IMU_MPU9250 ::
    deserializeVector(Fw::Buffer& buffer, F32 scaleFactor)
  {
    Sensors::imuTlm vector;
    I16 value;
    FW_ASSERT(buffer.getSize() >= 6, buffer.getSize());
    FW_ASSERT(buffer.getData() != nullptr);
    // Data is big-endian as is fprime internal storage so we can use the built-in buffer deserialization
    Fw::SerializeBufferBase& deserializeHelper = buffer.getSerializeRepr();
    deserializeHelper.setBuffLen(buffer.getSize()); // Inform the helper what size we have available
    FW_ASSERT(deserializeHelper.deserialize(value) == Fw::FW_SERIALIZE_OK);
    vector[0] = static_cast<F32>(value) / scaleFactor;

    FW_ASSERT(deserializeHelper.deserialize(value) == Fw::FW_SERIALIZE_OK);
    vector[1] = static_cast<F32>(value) / scaleFactor;

    FW_ASSERT(deserializeHelper.deserialize(value) == Fw::FW_SERIALIZE_OK);
    vector[2] = static_cast<F32>(value) / scaleFactor;
    return vector;
  }

  void IMU_MPU9250 ::
    updateAccel()
  {
    U8 data[IMU_MAX_DATA_SIZE_BYTES];
    Fw::Buffer buffer(data, sizeof data);

    // Read a block of registers from the IMU at the accelerometer's address
    Drv::I2cStatus status = this->readRegisterBlock(IMU_RAW_ACCEL_ADDR, buffer);

    // Check a successful read of 6 bytes before processing data
    if ((status == Drv::I2cStatus::I2C_OK) && (buffer.getSize() == 6) && (buffer.getData() != nullptr)) {
        Sensors::imuTlm vector = deserializeVector(buffer, accelScaleFactor);
        this->tlmWrite_accelerometer(vector);
    } else {
        // this->log_WARNING_HI_TelemetryError(status);
    }
  }

  void IMU_MPU9250 ::
    updateGyro()
  {
      U8 data[IMU_MAX_DATA_SIZE_BYTES];
      Fw::Buffer buffer(data, sizeof data);

      // Read a block of registers from the IMU at the gyroscope's address
      Drv::I2cStatus status = this->readRegisterBlock(IMU_RAW_GYRO_ADDR, buffer);

      // Check a successful read of 6 bytes before processing data
      if ((status == Drv::I2cStatus::I2C_OK) && (buffer.getSize() == 6) && (buffer.getData() != nullptr)) {
          Sensors::imuTlm vector = deserializeVector(buffer, gyroScaleFactor);
          this->tlmWrite_gyroscope(vector);
      } else {
          // this->log_WARNING_HI_TelemetryError(status);
      }
  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void IMU_MPU9250 ::
    run_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    if(m_power == PowerState::ON)
    {
      updateAccel();
      updateGyro();
    }
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void IMU_MPU9250 ::
    PowerSwitch_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        Sensors::PowerState powerState
    )
  {
    U8 data[IMU_REG_SIZE_BYTES * 2];
    Fw::Buffer buffer(data, sizeof data);

    // Check if already on/off
    if (powerState.e == m_power) {
        return;
    }

    data[0] = POWER_MGMT_ADDR;
    data[1] = (powerState.e == PowerState::ON) ? POWER_ON_VALUE : POWER_OFF_VALUE;

    Drv::I2cStatus status = this->write_out(0, m_i2cDevAddress, buffer);
    if (status == Drv::I2cStatus::I2C_OK) {
        m_power = powerState.e;
        // Must configure at power on
        if (m_power == PowerState::ON) {
            config();
        }
    }

    this->cmdResponse_out(opCode,cmdSeq,Fw::CmdResponse::OK);
  }

} // end namespace Sensors
