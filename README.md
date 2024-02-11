# Labplot Serial Examples <!-- omit in toc -->

[![License: GPLv3](https://img.shields.io/badge/license-GPLv3-red?style=flat-square)](https://www.gnu.org/licenses/gpl-3.0.html)
[![Shop: Tindie](https://img.shields.io/badge/shop-Tindie-blue?style=flat-square)](https://www.tindie.com/stores/binary-6/?ref=offsite_badges&utm_source=sellers_Chrismettal&utm_medium=badges&utm_campaign=badge_medium)
[![Donations: Coffee](https://img.shields.io/badge/donations-Coffee-brown?style=flat-square)](https://github.com/Chrismettal#donations)

This is a collection of examples using a [Raspberry Pi Pico](https://www.raspberrypi.com/products/raspberry-pi-pico/) as a live-data-source in [Labplot](https://labplot.kde.org/) via Serial.

While created in collaboration with the core LabPlot developer team, this Repo does not reflect in any way the thoughts or intentions of any of the LabPlot developers.

**If you like my work please consider [supporting me](https://github.com/Chrismettal#donations)!**

**If you enjoy using LabPlot please consider [supporting LabPlots developers](https://labplot.kde.org/donate/)!**

## Table of contents <!-- omit in toc -->

- [Prerequisites](#prerequisites)
- [Code Parameters](#code-parameters)
- [Uploading code](#uploading-code)
- [Observing via Terminal](#observing-via-terminal)
- [Examples](#examples)
    - [Single Value ASCII](#single-value-ascii)
    - [Multi Value ASCII](#multi-value-ascii)
- [Donations](#donations)
- [License](#license)

## Prerequisites

These examples were done using a regular low-cost [Raspberry Pi Pico](https://www.raspberrypi.com/products/raspberry-pi-pico/) board connected to a Linux computer via USB.

The Code running on the Pico was created with [PlatformIO](https://platformio.org/), using the Arduino framework. Opening up this repo with PlatformIO should auto-install all required dependencies. Compiled binaries will also be provided.

> [!NOTE]
>On Linux systems, make sure to follow [PlatformIO's documentation](https://docs.platformio.org/en/latest/core/installation/udev-rules.html) to install the appropriate **udev rules** so your Pico shows up as a tty later

## Code Parameters

TODO

## Uploading code

The very first time you insert the Pico into your PC, it will show up as a mass storage drive and will not accept serial uploads through PlatformIO. The first upload needs to be executed as follows:

1. Execute the `Build` Project Task in PlatformIO

![Build](/img/Pio_build.png)

2. Find the generated `firmware.uf2` file in PlatformIO's build directory

![firmware](/img/firmware.png)

3. Copy `firmware.uf2` over to your Pico like an USB flash drive

4. Restart your Pico by power cycling it


> [!TIP]
> Subsequent code uploads are much easier, as PlatformIO should be able to find your Pico automatically when executing the "upload" tasks. Only the first upload might need to be done manually

## Observing via Terminal

When your Pico runningthe example code is plugged into an USB port on your PC, it should show up as a `COM-Port` or `tty` depending on your OS. On Linux, you can execute `sudo dmesg` to observe at which port your Pico hooked up at, or `ls /dev/tty*` to look at all `tty`s and look for a new one. Usually it will be something like `/dev/ttyACM0`.

Output of `sudo dmesg` right after plugging in the Pico (Which has previously been flashed with the example sending code)

![tty](/img/tty.png)

Output of `ls /dev/tty*`

![lstty](/img/lstty.png)

On a Linux system, using [Picocom](https://github.com/npat-efault/picocom) as a lightweight terminal emulator, we can connect to our Pico with:

`picocom -b 9600 /dev/ttyACM0`

In this example, the baudrate is kept at `9600` as is default in the example code, and the port connected to is `/dev/ttyACM0` which was found earlier with `dmesg`.

On Windows systems, you would probably use [PuTTY](https://putty.org/) to connect.

For MacOS, please send guides to set up Virtualbox VMs that actually work.

## Examples

### Single Value ASCII

In this example, a single ASCII value is sent every `INTERVAL`, ending with `\r\n`. This is what the serial port sends out when observed through the terminal with default settings:

```
1.000000000
0.951056540
0.809017003
0.587785244
0.309017003
0.000000000
-0.309017003
-0.587785244
-0.809017003
-0.951056540
-1.000000000
```

### Multi Value ASCII

In this example, a 4 ASCII values are sent every `INTERVAL`, ending with `\r\n`, split by `SEPERATOR`. This is what the serial port sends out when observed through the terminal with default settings:

![MultiASCII](/img/MultiASCII.gif)

## Donations

**If you like my work please consider [supporting me](https://github.com/Chrismettal#donations)!**

**If you enjoy using LabPlot please consider [supporting LabPlots developers](https://labplot.kde.org/donate/)!**

## License

 <a rel="GPLlicense" href="https://www.gnu.org/licenses/gpl-3.0.html"><img alt="GPLv3" style="border-width:0" src="https://www.gnu.org/graphics/gplv3-or-later.png" /></a><br />This work is licensed under a <a rel="GPLlicense" href="https://www.gnu.org/licenses/gpl-3.0.html">GNU GPLv3 License</a>.
