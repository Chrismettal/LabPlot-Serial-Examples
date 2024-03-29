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

At the top of the example Pico code you'll find some parameters that you need to set for different types of live data source examples. The default settings will send a single float value every `1000 ms` on a terminal with `9600` baudrate. 

```C
// ----------------------------------------------------------------------------
//  Parameters
// ----------------------------------------------------------------------------
#define BAUDRATE  9600   // Serial baudrate
#define SEPERATOR ","    // Seperator between multiple ASCII values in multiASCII mode
#define INTERVAL  1000.0 // Send interval in milliseconds

// Mode, choose one.
enum mode {
  singleASCII,  // --> One ASCII value every INTERVAL. No Newline or seperator. 9 decimals.
  multiASCII,   // --> ASCII CSV of several values every INTERVAL. separated by SEPERATOR. 9 decimals.
  singleBinay,  // --> One binary value every INTERVAL. Formatted TODO
  multiBinary   // --> Several binary values every INTERVAL. Formatted TODO
};
const uint8_t mode = singleASCII;
```


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

In LabPlot, add a new live data source:

![AddLDS](/img/AddLDS.png)

Apply the following settings to your live data source. Make sure to choose the serial port you found earlier (`ttyACM0` for me), the baudrate chosen in the code parameters (`9600` by default) and apply a custom filter as shown.

Since we are only sending a single value, column seperator won't matter.

Update interval needs to be set exactly the same as the interval your device sends at as of `Labtplot 2.10.0-1982-gb1a964f82` but this is subject to change.

![LDSettings](/img/LDSettings.png)

After accepting, you should see your live data source update every `INTERVAL` with the new data received, along with a timestamp and index created by LabPlot as chosen in the LDS settings:

![SingleLDSspread](/img/SingleLDSspread.png)

Plotting that value with default settings should show you a live updating sine wave:

![SingleValuePlot](/img/SingleValuePlot.png)

### Multi Value ASCII

In this example, a 4 ASCII values are sent every `INTERVAL`, ending with `\r\n`, split by `SEPERATOR`. This is what the serial port sends out when observed through the terminal with default settings:

![MultiASCII](/img/MultiASCII.gif)

## Donations

**If you like my work please consider [supporting me](https://github.com/Chrismettal#donations)!**

**If you enjoy using LabPlot please consider [supporting LabPlots developers](https://labplot.kde.org/donate/)!**

## License

 <a rel="GPLlicense" href="https://www.gnu.org/licenses/gpl-3.0.html"><img alt="GPLv3" style="border-width:0" src="https://www.gnu.org/graphics/gplv3-or-later.png" /></a><br />This work is licensed under a <a rel="GPLlicense" href="https://www.gnu.org/licenses/gpl-3.0.html">GNU GPLv3 License</a>.
