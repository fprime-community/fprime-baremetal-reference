# Deployment Setup

If you wish to create a new F´ deployment with minimal components that can run on Arduino microcontrollers, edit the `settings.ini` in the project root and add the following line:

```
deployment_cookiecutter: https://github.com/ethancheez/fprime-arduino-deployment-cookiecutter.git
```

Now you are able to run

```shell
fprime-util new --deployment
```

## Generate/Build Application

In order to generate and build any other F´ application, run the following commands in the project root directory:

```sh
fprime-util generate
fprime-util build
```

To generate/build for a specific device, append the device name to the end of the above commands.

These devices have been tested:
  - teensy41
  - featherM0

To set a specific build as the default, append this line to the end of the `settings.ini` file, where `<build name>` is the default build (i.e. `teensy41`):

```
default_toolchain: <build name>
```