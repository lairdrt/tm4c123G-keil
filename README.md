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
The [Keil uVision IDE](https://developer.arm.com/documentation/101407/0538/About-uVision) allows you to create a project that targets your microcontroller, and configure support packages that provide startup and application-specific functionality to your system. Keil uVision is part of the [Keil Microcontroller Development Kit (MDK)](https://developer.arm.com/Tools%20and%20Software/Keil%20MDK). To install the product under Windows 10, follow the steps below.

You basically have to register to download the ARM MDK, but it's free. When you go to submit the registration form, enter `TM4C123GH6PMI` for the device that you are using. The registration screen looks like this:

![Screenshot 2023-05-20 at 13-19-31 MDK-ARM Version 4 74 Evaluation Software Request](https://github.com/lairdrt/tm4c123G-keil/assets/31704471/23f9346f-4282-46b1-acd4-6745ba2be239)

Normal installation process:
1. [Download the MDK-ARM.](https://www.keil.com/demo/eval/armv4.htm)
2. You should see a screen where you can click to doanload the **MDKxx.exe** application file.
3. Find the downloaded file.
4. Install by double clicking the downloaded file.
5. Follow the installation instructions (accept the default installation directory).

You should now have a desktop icon for the Keil uVision IDE.

## Install Windows 10 USB Drivers
You'll need the correct Windows 10 USB drivers to download your compiled binary code to the LaunchPad. The LaunchPad does not support plug-and-play device driver installation under Windows 10. Finding the USB drivers that allow you to flash the LaunchPad is not easy. Fortunatley, this link helps:

[How to install windows drivers for the LaunchPad on Windows 10](https://edx-org-utaustinx.s3.amazonaws.com/UT601x/InstallDrivers10.htm)

First:
1. Plug in your LaunchPad to an available USB port on your development computer.
2. If you're really lucky, the appropriate device drivers will be loaded, but probably not.
3. Successful driver installation looks like this:

![usbdrivers](https://github.com/lairdrt/tm4c123G-keil/assets/31704471/004925c3-d735-4c47-82b4-b249196616c1)

Then, if the drivers are **not** installed automatically:
1. Download the UT Austin [Test EXecute And Simulate software](http://edx-org-utaustinx.s3.amazonaws.com/UT601x/TExaS_Install.exe).
2. Find the downloaded file.
3. Install by double clicking the downloaded file.
4. Follow the installation instructions (install the software in the **same directory** as Keil uVision).

The above will result in the Windows 10 drivers being installed in your Keil uVision directory. Remember where that is.

Next, you'll update the Windows 10 drivers for the LaunchPad using the Windows Device Manager:
1. [Follow these instructions starting at step 9.](https://edx-org-utaustinx.s3.amazonaws.com/UT601x/InstallDrivers10.htm)
2. You should end up with the device drivers installed as shown above (under Windows 10, there was no additional COM port).

You should now be able to select the Stellaris ICDI interface within Keil uVision under **Options for Target** dialog box on the **Debug** tab. Note that you must have the LaunchPad plugged into a USB port on your development system for the device drivers to become available. You don't need to verify this just yet, but toward the end of these instructions, take a look.

![targetoptions](https://github.com/lairdrt/tm4c123G-keil/assets/31704471/bf497924-5a0d-47d4-b086-d56d58c525ef)

## Programming the Device

We're assuming that you have experience with **git** so that you can clone this repository.

Programming the device for the purposes of testing your system involves:

1. Cloning this repository into a directory of your choice.
2. Plugging in the LaunchPad evaluation board to your development system.
3. Launching the Keil uVision IDE.
4. Opening the project that you cloned.
5. Cleaning the target.
6. Building the target.
7. Downloading the binary file to the target.
8. Running the software on the target.

In more detail...

### Cloning the Repository

We're assuming that you've installed the Keil uVision software into: `C:\Keil_v5`

Within a command prompt on your development system:

`cd c:\Keil_v5`<br>
`mkdir Projects`<br>
`cd Projects`<br>
`git clone git@github.com:lairdrt/tm4c123G-keil.git`<br>

Should end up with the directory: `C:\Keil_v5\Projects\tm4c123G-keil`

### Connect the LaunchPad Board

With the LaunchPad board:

1. Make sure that the **PWR SELECT** switch is set to **DEBUG**.
2. Plug in the board to an avalable USB port on your development system.
3. The green **PWR** LED on the board should illuminate.
4. You should see some indication on Windows that the board is plugged in (e.g., sound, system tray icon).
5. You can double check under the Windows Device Manaager that the Stellaris devices are active.

### Launch Keil uVision

You want a clean start, so launch the IDE software anew. The screen should look something like this:

![uvision](https://github.com/lairdrt/tm4c123G-keil/assets/31704471/9c57c2b7-02a5-4a3c-8263-fd2aec3149b4)

### Open the Test Project

From within the uVision IDE:

1. Select **Project > Open Project...**
2. Navigate to the directory where you cloned the project (e.g., **C:\Keil_v5\Projects\tm4c123G-keil**).
3. Double click on the name of the project (e.g., **wtf.uvprojx**).
4. You should see something like this:

![project](https://github.com/lairdrt/tm4c123G-keil/assets/31704471/ece5d7ec-dbc5-4356-983d-1fb4db881776)

### Clean, Build, and Download

Follow these steps to perform a clean build of the software:

1. Select **Project > Clean Targets**
2. Select **Project > Build Target**

Should see something like this:

![projectbuild](https://github.com/lairdrt/tm4c123G-keil/assets/31704471/39b6f7b7-7c05-4d62-9e11-b3e0f1e85849)

1. Select **Flash > Download**
2. If the USB drivers were installed correcly, then you should see something like this:

![projectdownload](https://github.com/lairdrt/tm4c123G-keil/assets/31704471/a8f471e2-4ab2-49ad-aa17-a0ad50d11bd6)

### Run the Software

If the build and download were successful:

1. Press and release the **RESET** button on the LaunchPad board.
2. You should see the RGB LEDs cycle = success.

Take a look at the settings for the target device by selecting **Project > Options for Target 'TM4C123G'...** (as shown above). This is where you can verify that the Stellaris drivers are available for use when debugging.

Now you can use this as a starting point for building out your application software.
