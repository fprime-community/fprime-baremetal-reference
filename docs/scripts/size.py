import sys
import os
import subprocess

ROOT_USER = os.path.expanduser('~')
PROJECT_ROOT = os.path.abspath(f'{os.path.dirname(__file__)}/../..')
BUILD_ARTIFACTS = f'{PROJECT_ROOT}/build-artifacts'

def main(argc, argv):

    # Check arguments for build name
    if argc != 2:
        print('Specify build. (i.e. $ python3 size.py teensy41)')
        return
    build = argv[1]

    # Check if build is supported for size checking
    if build == 'featherM0':
        SIZE_UTIL_EXECS = f'{ROOT_USER}/.arduino15/packages/adafruit/tools/arm-none-eabi-gcc/9-2019q4/bin/arm-none-eabi'
    elif build == 'teensy41':
        SIZE_UTIL_EXECS = f'{ROOT_USER}/.arduino15/packages/teensy/tools/teensy-compile/11.3.1/arm/bin/arm-none-eabi'
    else:
        print(f'ERROR: Size check for {build} not yet supported! Exiting...')
        return

    BIN = f'{BUILD_ARTIFACTS}/{build}/BaremetalReference/bin/BaremetalReference'

    # Check if build exists
    if not os.path.exists(BIN):
        print('Build not found. Maybe try running:')
        print(f'  fprime-util build {build}')
        return

    print_component_size(SIZE_UTIL_EXECS, BIN)
    print_channel_size(f'{BUILD_ARTIFACTS}/{build}/BaremetalReference/dict/BaremetalReferenceTopologyAppDictionary.xml')
    print_command_size(f'{BUILD_ARTIFACTS}/{build}/BaremetalReference/dict/BaremetalReferenceTopologyAppDictionary.xml')
    print_build_size(build, SIZE_UTIL_EXECS, BIN)

# Print Size of BaremetalReference Components
def print_component_size(util_path, bin_path):
    print('------------------------------')
    print(f'    Size for F\' Components   ')
    print('------------------------------')
    p1 = subprocess.Popen([f'{util_path}-nm', bin_path, '-CStd'], stdout=subprocess.PIPE)
    p2 = subprocess.Popen(['grep', 'BaremetalReference::'], stdin=p1.stdout, stdout=subprocess.PIPE)
    p3 = subprocess.Popen(['sort', '-k2'], stdin=p2.stdout, stdout=subprocess.PIPE)
    output = subprocess.check_output(['grep', ' B '], stdin=p3.stdout)
    print(output.decode('utf-8').strip())

# Print Size of Telemetry Channels
def print_channel_size(xml_path):
    p1 = subprocess.Popen(['cat', xml_path], stdout=subprocess.PIPE)
    p2 = subprocess.Popen(['grep', '<channel '], stdin=p1.stdout, stdout=subprocess.PIPE)
    output = subprocess.check_output(['wc', '-l'], stdin=p2.stdout)

    # Ignore 15 - CPU Cores
    # Ignore 2  - commQueue
    print(f'=== Number of Telemetry Channels ({PROJECT_ROOT}/config/TlmChanImplCfg.hpp:50)')
    print(f'\t- TLMCHAN_HASH_BUCKETS = {int(output.decode("utf-8").strip()) - 15 - 2}')

# Print Size of Commands
def print_command_size(xml_path):
    p1 = subprocess.Popen(['cat', xml_path], stdout=subprocess.PIPE)
    p2 = subprocess.Popen(['grep', '<command '], stdin=p1.stdout, stdout=subprocess.PIPE)
    output = subprocess.check_output(['wc', '-l'], stdin=p2.stdout)

    print(f'=== Number of Commands ({PROJECT_ROOT}/config/CommandDispatcherImplCfg.hpp:14)')
    print(f'\t- CMD_DISPATCHER_DISPATCH_TABLE_SIZE = {output.decode("utf-8").strip()}')

# Print Size of Entire BaremetalReference Build
def print_build_size(build, util_path, bin_path):
    print('------------------------------')
    print(f'    Size for {build}')
    print('------------------------------')

    subprocess.run([f'{util_path}-size', bin_path])

if __name__ == '__main__':
    main(len(sys.argv), sys.argv)
    