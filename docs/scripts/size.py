import os
import subprocess

ROOT_USER = os.path.expanduser('~')
PROJECT_ROOT = '../..'
BUILD_ARTIFACTS = f'{PROJECT_ROOT}/build-artifacts'

PRINTED_COMPONENT_SIZE = False

for build in os.scandir(BUILD_ARTIFACTS):
    if build.name == 'featherM0':
        SIZE_UTIL_EXECS = f'{ROOT_USER}/.arduino15/packages/adafruit/tools/arm-none-eabi-gcc/9-2019q4/bin/arm-none-eabi'
    elif build.name == 'teensy41':
        SIZE_UTIL_EXECS = f'{ROOT_USER}/.arduino15/packages/teensy/tools/teensy-compile/11.3.1/arm/bin/arm-none-eabi'
    else:
        print('!!!-----------------------------------------!!!')
        print(f'   Size check for {build.name} not yet supported   ')
        print('!!!-----------------------------------------!!!')
        continue

    BIN = f'{BUILD_ARTIFACTS}/{build.name}/BaremetalReference/bin/BaremetalReference'

    # Size of BaremetalReference Components
    if not PRINTED_COMPONENT_SIZE:
        print('------------------------------')
        print(f'    Size for F\' Components   ')
        print('------------------------------')
        p1 = subprocess.Popen([f'{SIZE_UTIL_EXECS}-nm', BIN, '-CStd'], stdout=subprocess.PIPE)
        p2 = subprocess.Popen(['grep', 'BaremetalReference::'], stdin=p1.stdout, stdout=subprocess.PIPE)
        p3 = subprocess.Popen(['sort', '-k2'], stdin=p2.stdout, stdout=subprocess.PIPE)
        output = subprocess.check_output(['grep', ' B '], stdin=p3.stdout)
        print(output.decode('utf-8').strip())
        PRINTED_COMPONENT_SIZE = True

    print('------------------------------')
    print(f'    Size for {build.name}    ')
    print('------------------------------')

    # Size of BaremetalReference
    subprocess.run([f'{SIZE_UTIL_EXECS}-size', BIN])
