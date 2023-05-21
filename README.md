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

You basically have to register to download the ARM MDK, but it's free. When you go to submit the registration form, enter `TM4C123G` for the device that you are using. The registration screen looks like this:

![Screenshot 2023-05-20 at 17-52-46 MDK-ARM Version 4 74 Evaluation Software Request](https://github.com/lairdrt/tm4c123G-keil/assets/31704471/6cfb2d4a-b27d-4134-adbb-db64340ebfb5)

Installation process:
1. [Register to download the MDK-ARM.](https://www.keil.com/demo/eval/armv4.htm)
2. After you've registered, click on the file **MDKxxx.exe** to download it.
3. Find the downloaded file.
4. Install by double clicking the downloaded file.
5. Follow the installation instructions (accept the default installation directory).

![mdkarm](https://github.com/lairdrt/tm4c123G-keil/assets/31704471/f4d02d97-bc21-4776-b3af-458162a62811)

You should now have a desktop icon for the Keil uVision IDE, and the Keil Pack Installer should launch.

![packinstall](https://github.com/lairdrt/tm4c123G-keil/assets/31704471/e45d983d-6ad3-44b3-834f-c9780411f5d0)

## Customize Keil Installation with the Pack Installer

After the initial installation of the Keil software, you should be presented with Keil Pack Installer. It takes a bit of time for the installer to populate all the devices that it supports, so wait until that process finishes.

Then, you'll want to verify that the packages for the TM4C123GH6PM are installed. See below for where to look for them:

![packcheck](https://github.com/lairdrt/tm4c123G-keil/assets/31704471/65fab739-794d-4250-aa91-93d5aacd91b3)

If the highlighted packages above do not display **Up to date** adjacent to them on the right hand panel, then select the button for each component and install it.

Close the Pack Installer.

## Install MDK Stellaris ICDI Debug Adapter Fix
From the Keil website:

**In MDK v5.29 as well as newer versions of MDK the support for the Stellaris ICDI debug adapter has been removed, which will cause such a debugger DLL error.
There is an add-on Stellaris ICDI installer that supports MDK v5.29. Just download and install the MDK_Stellaris_ICDI_AddOn.exe file attached in this article.**

So, please follow these instructions to install the fix:
1. Navigate to this page: [UVISION: Stellaris ICDI Debug Adapter Support](https://developer.arm.com/documentation/ka002280/latest)
2. Download the **MDK_Stellaris_ICDI_AddOn.exe** attachment at the bottom of the page by clicking on it.
3. Navigate to where the file was downloaded.
4. Double click on the file to install the fix.
5. Follow the installation instructione (accept the default installation directory).

This makes it so that the USB drivers installed below will work.

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

![uvblank](https://github.com/lairdrt/tm4c123G-keil/assets/31704471/59b091b0-336c-4dd9-8c42-4eb3e3c601f1)

### Open the Test Project

From within the uVision IDE:
1. Select **Project > Open Project...**
2. Navigate to the directory where you cloned the project (e.g., **C:\Keil_v5\Projects\tm4c123G-keil**).
3. Double click on the name of the project (e.g., **blinkleds.uvprojx**).
4. You should see something like this:

![uvopen](https://github.com/lairdrt/tm4c123G-keil/assets/31704471/f1f0de40-98f0-404f-b70b-70990fc969ba)

Verify that the target is using the **Stellaris ICDI** USB driver for programming the device.

1. Select **Project > Options for Target 'TM4C123G'...**
2. Select the **Debug** tab.
3. On the right hand side (top) of the tab, select the **Use** radio button.
4. Scroll down in the list and make sure that **Stellaris ICDI** is selected.
5. Select **Ok** to save the changes.

This will ensure that the correct USB driver is used when programming the target device.

### Clean, Build, and Download

Follow these steps to perform a clean build of the software:
1. Select **Project > Clean Targets**
2. Select **Project > Build Target**

Should see something like this:

![uvbuild](https://github.com/lairdrt/tm4c123G-keil/assets/31704471/baf8954e-b206-4f1c-bcb7-cd6d676aa47d)

1. Select **Flash > Download**
2. If the USB drivers were installed correcly, then you should see something like this:

![uvflash](https://github.com/lairdrt/tm4c123G-keil/assets/31704471/4cf052bf-14dd-418b-bdab-aad5893fa5f9)

### Run the Software

If the build and download were successful:
1. Press and release the **RESET** button on the LaunchPad board.
2. You should see the RGB LEDs cycle = success.

https://github.com/lairdrt/tm4c123G-keil/assets/31704471/21f07256-186b-4ef5-8d91-f6239bdd78b5

Now you can use this as a starting point for building out your application software.
