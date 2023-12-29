# QMedia
Personal project to demonstrate pation for coding.

## About Project

**QMedia** is a free and open-source software and utility developed for a number of multimedia purposes. The software enables the capture and manipulation of images, playing audio and video files, and last but not least the ability to record and save audio and video. The project takes advantage of the Qt Multimedia library as the back-end to accomplish the task of handling media files and recording. The Qt Widgets library is what powers the front-end and the visuals of the application. The general language that was used to develop the application is C++.

### Qt Multimedia

This is the **core** of the project. The library is composed of many helper classes and functions that enable the capture, play, and recording of multimedia files and codecs on the native platform. The library takes build upon the famous **ffmpeg** library and takes advantage of its' incredible power.

Those are the features offered by the library:

- Record **Screen Video** without  **microphone audio**
- Record **Screen Video** with **microphone audio**
- Allows the user to specify the screen recording's **fps**, by a value chosen by the user.
- Allows the user to specify an **audio input device** *(if library doesn't find the available devices, then no audio will be recorded)*.
- Allows the user to specify the **output file name and location** *(the user can select the file extention, but the program will make changes if codecs does not match)*.
- In case of **internal errors** throws an **exception** with a **description of the error** and gracefully **stop the registration**.

### Qt Widgets

Allow to use the **Qt Multimedia** library, offering a **GUI** to set the **parameters** and to give **commands**. It uses **Qt Multimedia** library to find the available **audio devices** and *video screens* on the native platform.

### Installation (Windows)

- Download the latest binary from this [link](https://github.com/cheina97/PDS_Project/releases/latest/download/ScreenRecorderQT_linux_amd64)
- Install the application by following the instructions on the installer.
- Run the program.

### How to compile, edit, and run in Qt Creator

- Download and install the **Qt tools** on their website along with the required **Qt libraries**: [link]([https://github.com/cheina97/PDS_Project/releases/latest/download/ScreenRecorderQT_linux_amd64](https://www.qt.io/download))
- Clone the repository.
- Open the project using Qt Creator and start editing and testing.

#### Recommended Qt version and compiler settings
- Download **Qt 6.6.1** or higher version.
- Use **C++** version **17**. 
- Compiler C++: **MinGW**
