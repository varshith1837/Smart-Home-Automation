mart Home Automation System
This project is a console-based Smart Home Device Control System that enables users to manage and control household devices through a unified interface. It is a demonstration of object-oriented programming concepts using C++ classes, encapsulation, and operator overloading. Users can monitor and adjust appliances such as AC, Fan, Fridge, Light, Geyser, and TV, manage device settings, automate device behavior with timers, and track power consumption.​

Features
Centralized control of household appliances (AC, Fan, Fridge, Light, Geyser, TV)

Individual device settings: temperature, fan speed, brightness, channel, etc.

Modular class hierarchy with a base class (Device) and specialized subclasses

Data encapsulation for secure state management

Operator overloading for intuitive display of device states

User authentication with account creation and per-user state persistence

Power consumption tracking and calculation

Real-time status monitoring and unified device management

Console-based, menu-driven interface​

System Overview
Each device type is represented as a distinct object and inherits from a base class.

Flexible and scalable design to support more device types.

User-specific storage ensures device and usage state is retained between application runs.

Device on/off timings and state updates are persistently tracked for each user.​

Class Structure
Device: Base class for all devices with universal on/off and status-related methods.

AC: Controls temperature, fan speed, swing, and power state.

Fan: Controls speed and power, includes timer functionality.

Fridge: Controls cooling level and power, includes timer.

Light: Controls brightness, color, and power with color cycling.

Geyser: Controls heating temperature, includes timer.

TV: Channel selection, volume, brightness, and on/off.​

How to Run
Compile and launch the program using your preferred C++ development environment.

Login with your credentials or create a new account if you are a new user.

Setup your smart home by specifying the number and type of devices you wish to control.

Use the menu-driven interface to:

Turn devices on/off

Adjust device-specific settings

Set timers for automation

View real-time device statuses and total power consumption

Logout to securely save your device configurations and usage state.​

Requirements
C++ compiler (e.g., GCC, Clang)

CSV file handling for user and device data persistence

Runs on any standard console environment​

Limitations & Possible Enhancements
User interface is currently console-based and may not suit non-technical users.

Timer and input validation have pre-set constraints.

Planned enhancements:

Graphical User Interface (GUI) for improved usability

Remote access and control over the internet

More advanced device simulation for realistic controls​

Authors
Nithin Ch (CS23B1102)

Sanshrey G (CS23B2014)

Varshith B (CS23B2015)

Raviteja B (CS23B2011)

Susan B (CS23B2026)


License
This project is intended for educational use.
