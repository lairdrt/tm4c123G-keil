# Programming the TI Tiva C TM4C123G LaunchPad
This repository supports programming the Texas Instruments Tiva C Series [TM4C123GH6PMI](https://www.ti.com/tool/EK-TM4C123GXL) LaunchPad microcontroller using the [Keil uVision IDE](https://developer.arm.com/documentation/101407/0538/About-uVision) running under Windows 10.

Adapted from:

[Introduction to TM4C123 Tiva C Series LaunchPad](https://microcontrollerslab.com/introduction-tiva-tm4c123g-launchpad/)

[How to download and install Keil uVision for ARM and 8051](https://microcontrollerslab.com/download-install-keil-uvision/)

[Getting started with Keil uVision: Write your first Program for Tiva LaunchPad](https://microcontrollerslab.com/keil-uvision-first-program/)

[How to use GPIO pins of TM4C123G Tiva launchPad](https://microcontrollerslab.com/use-gpio-pins-tm4c123g-tiva-launchpad/)

## Versions
Microsoft Windows 10 Pro version 10.0.19045 Build 19045

Keil uVision V5.38.0.0

Texas Instruments Interface DLL (lmidk-agdi.dll) build 211.0.0.0

Stellaris USB ICDI DFU Device version 2.0.7922.0 (12/31/2015)

Stellaris ICDI JTAG/SWD Interface version 2.0.7922.0 (12/31/2015)

## Install Keil uVision IDE
The [Keil uVision IDE](https://developer.arm.com/documentation/101407/0538/About-uVision) allows you to create a project that targets your microcontroller, and configure support packages that provide startup and application-specific functionality to your system. Keil uVision is part of the [Keil Microcontroller Development Kit (MDK)](https://developer.arm.com/Tools%20and%20Software/Keil%20MDK). To install the product under Windows 10, follow these steps:

### Download the Keil ARM MDK
You basically have to register to download the ARM MDK, but it's free. When you go to submit the registration form, enter `TM4C123GH6PMI` for the device that you are using.

![Screenshot 2023-05-20 at 13-19-31 MDK-ARM Version 4 74 Evaluation Software Request](https://github.com/lairdrt/tm4c123G-keil/assets/31704471/23f9346f-4282-46b1-acd4-6745ba2be239)

Normal installation process:
1. [Download the MDK-ARM.](https://www.keil.com/demo/eval/armv4.htm)
2. Find the downloaded file.
3. Install by double clicking the downloaded file.
4. Follow the installation instructions (accept the default installation directory).

### Install Windows 10 USB Drivers
You'll need the correct Windows 10 USB drivers to download your compiled binary code to the LaunchPad. The LaunchPad does not support plug-and-play device driver installation under Windows 10. Finding the USB drivers that allow you to flash the LaunchPad is not easy. Fortunatley, this link helps:

[How to install windows drivers for the LaunchPad on Windows 10](https://edx-org-utaustinx.s3.amazonaws.com/UT601x/InstallDrivers10.htm)

First:
1. Plug in your LaunchPad to an available USB port on your development computer.
2. If you're really lucky, the appropriate device drivers will be loaded, but probably not.
3. Successful driver installation looks like this:

![usbdrivers](https://github.com/lairdrt/tm4c123G-keil/assets/31704471/004925c3-d735-4c47-82b4-b249196616c1)

Then, if the drivers are not installed automatically:
1. Download the UT Austin [Test EXecute And Simulate software](http://edx-org-utaustinx.s3.amazonaws.com/UT601x/TExaS_Install.exe).
2. Find the downloaded file.
3. Install by double clicking the downloaded file.
4. Follow the installation instructions (install the software in the same directory as Keil uVision).

## Start Your First Project

## Write Your First Program

## Test Your First Program
