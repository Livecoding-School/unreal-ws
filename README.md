# Live Coding School
## March 3-8. 2020, Budapest

This is the public repository for the workshop material of the event regarding Unreal Engine 4 (abbreviated to UE4 or just Unreal) in 2 parts.

During part one of this workshop you will learn:

* The general usage of the user interface of UE4
* A general overview of the phylosophy behind most components
* Interacting with the UE4 ecosystem
* The architecture of the authoring tools and an average application made in UE4
* Basics of programming application behavior in Blueprints
* Overvioew of Object-Oriented Programming (OOP)

During part two of this workshop you will learn:

* Jump to C++ to make UE4 do your bidding
* Bare-bones basics of the C++ programming language
* Using the UE4 specific standard library
* Using the C++ LiveCoding feature to make iterative changes to our application
* Possibly automate engine tasks in your favorite/available shell environments

The workshop will be kept from a Windows PC. UE4 supports other desktop OS's (many Linux distros and macOS) however I'm only familiar with Windows workflows, therefore I can only give accurate support on installing UE4 on Windows. If you have problems installing on Linux or macOS, we can still try to solve it but in order to keep efficiency please try to fix those first yourself before the workshop.

## Installing UE4

First create an account for UE4 and in turn Epic games at https://www.unrealengine.com/id/register , it's free and no strings attached (depending on your cyber paranoia threshold), and also required to download UE4 and optionally have access to its source code.

**The easy way for Windows and MacOS:**

Go to https://www.unrealengine.com/en-US/download/ue_non_games and download Epic Games Launcher. In there go to the Unreal Engine section and add an engine version. Click install under the "version slot". It will ask you for location, and you can select installed components under the advanced section. Depending on your configuration download can be between 3 and 10 Gb and it might take up 10 to 50 Gb of hard drive space.

**The 1337 and possibly only way for Linux**

Go to https://www.unrealengine.com/en-US/ue4-on-github and follow instructions to get access to the source code of UE4 on github. Once you have access to the repository go to https://github.com/EpicGames/UnrealEngine and follow the Linux section of "Getting up and running" https://github.com/EpicGames/UnrealEngine#linux and build it following the instructions here: https://github.com/EpicGames/UnrealEngine/blob/release/Engine/Build/BatchFiles/Linux/README.md

For the second workshop section:

## Installing Visual Studio for Windows

Download Visual Studio **Community** from https://visualstudio.microsoft.com/ and during installation check "Game Development with C++" workload. This can also take up 3-15 Gb storage on your hard drive.

## Installing XCode for macOS

Install XCode from the App Store https://apps.apple.com/us/app/xcode/id497799835

On Linux you gotta use your favorite text editor. In fact you can use your favorite text editor on any OS, however UE4 might not support generating project files for them.

## Assumptions about Participants of the Workshop

* Laptop/computer which can run UE4 editor smoothly (Windows recommended, MacOS is fine, Linux is possible but harder)
* Latest official UE4 installed (4.24 as of time of writing)
* Basic knowledge about minimal programming concepts (like type of numbers (float, int... ), strings, structures etc)

Part one assumes that participants have

* Minimal practice in any 3D editing environment
* We will cover some basic OOP (Object-Oriented Programming) concepts, but the workshops will be easier for the participant if they have minimal preliminary knowledge about it

Part two assumes that participants have

* written code in their life at least once
* the courage/willpower to install and use C++ developer tools.
