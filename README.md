# Smart Home Automation System

A console-based home automation system to control and monitor devices like AC, Fan, Fridge, Light, Geyser, and TV using an interactive C++ interface. Demonstrates object-oriented programming concepts, encapsulation, operator overloading, and per-user customization.

---

## Features

- Unified control center for all major home appliances  
- Per-device customization (temperature, speed, brightness, etc.)  
- Operator overloading for easier information display  
- Secure user authentication and persistent per-user storage  
- Power usage tracking  
- Real-time status and remote configuration  
- Object-oriented design for easy extension

---

## System Overview

Each device type is an object derived from a base `Device` class. Devices support specific actions and states (e.g., for AC: temperature and swing; Light: brightness and color). Device and user data are saved to separate files, ensuring session continuity.

---

## Class Structure

- `Device`: Base class for all devices.
- `AC`: Controls temperature, swing, fan speed.
- `Fan`: Controls fan speed and timer.
- `Fridge`: Controls cooling, inner light.
- `Light`: Controls brightness, color shade.
- `Geyser`: Controls temperature.
- `TV`: Controls channel, volume, brightness.

---

## How to Run

1. Compile the source code in any standard C++ environment.
2. Run the executable.  
3. Log in with an existing user ID or create a new account (credentials stored in CSV).
4. On first login, set up the number and type of devices in your smart home.
5. Use the intuitive menu to:
    - Turn devices on/off
    - Adjust device-specific settings
    - Set device timers
    - View real-time power consumption
6. Logout to securely save all states.

---

## Requirements

- C++ compiler (GCC, Clang, etc.)
- Basic CSV file handling support
- Runs in console/terminal environment

---

## Limitations and Future Enhancements

- Console UI; no graphical interface yet  
- Pre-set timer/input validation limits  
- Planned improvements:
    - Graphical User Interface (GUI)
    - Remote/wireless access via the internet  
    - Advanced device simulation

---

## Authors

- Nithin Ch
- Sanshrey G 
- Varshith B 
- Raviteja B
- Susan B

(IIITDM Kancheepuram)

---

## License

This project is for educational purposes.

