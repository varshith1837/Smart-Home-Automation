# 🏡 Smart Home Automation System

[cite_start]This project is a console-based application for controlling and managing various household devices through a **unified interface** [cite: 16][cite_start], demonstrating **Object-Oriented Programming (OOP) principles** [cite: 17] [cite_start]using **C++ classes**[cite: 17].

[cite_start]The system simulates controls for devices like an **AC, Fan, Fridge, Light, Geyser, and TV** [cite: 18][cite_start], allowing users to monitor and manage these smart home appliances and adjust settings like temperature, speed, and brightness[cite: 18]. [cite_start]The project was developed by a team from **IIITD&M Kancheepuram**[cite: 1].

---

## ⚙️ System Overview

[cite_start]The application centralizes control of all household appliances [cite: 20] [cite_start]by representing each device as an **object**[cite: 20]. [cite_start]The system is designed for easy **customization and scalability**[cite: 21].

### Object-Oriented Design: Class Structure

[cite_start]The core of the system is built on a hierarchical class structure that leverages OOP concepts[cite: 37]:

* [cite_start]**Base Class (`Device`):** Serves as the foundation for all devices[cite: 34, 261]. [cite_start]It contains common attributes such as **status (on/off)** and basic methods to turn the device on or off, check its status, and perform universal functions[cite: 34].
* [cite_start]**Derived Classes:** Each specific device type (AC, Fan, Fridge, Light, Geyser, TV) is represented by a class that **inherits from `Device`**[cite: 35]. [cite_start]These classes include **specialized methods** to handle settings unique to each device[cite: 35]:
    * [cite_start]**AC:** Methods for temperature control, swing setting, and fan speed adjustment[cite: 36].
    * [cite_start]**Fan:** Methods for speed adjustment[cite: 44].
    * [cite_start]**Light:** Methods for brightness and color shade control[cite: 47].
    * [cite_start]**TV:** Methods for channel, volume, and brightness control[cite: 43].
    * [cite_start]**Geyser:** Methods for temperature control[cite: 46].
    * [cite_start]**Fridge:** Methods for cooling level and inner light status control[cite: 45].

### Key Implementation Features (Fixed Table)

| Feature | Description | OOP Principle |
| :--- | :--- | :--- |
| **Data Encapsulation** | [cite_start]Internal data for each device (e.g., AC temperature, TV channel) is **encapsulated as protected data members** [cite: 39, 42][cite_start], ensuring data integrity and security by limiting access to designated class methods[cite: 39, 40]. | [cite_start]**Encapsulation** [cite: 38] |
| **Operator Overloading** | [cite_start]The `<<` operator (`operator<<`) is overloaded for the `ostream` class (**COUT**) to allow easy, readable display of device information like status and settings directly to the console[cite: 49, 50, 52]. | [cite_start]**Operator Overloading** [cite: 48] |
| **User Management** | [cite_start]Includes a **Login System** and **Account Creation**[cite: 55, 60]. [cite_start]New users set up an account by providing an ID and password, which are stored in a **CSV file** for future authentication[cite: 61, 62]. | |
| **Persistent State** | [cite_start]Each user has a **dedicated file** to store component data and configuration[cite: 90]. [cite_start]When logging in, the system **loads the previous state** of all components[cite: 92]. [cite_start]The file is updated in **real-time** whenever component states change[cite: 112]. | |
| **Power Tracking** | [cite_start]The device's **ON and OFF timings are recorded in a CSV file** [cite: 172][cite_start], which is used to **calculate energy usage** [cite: 202] [cite_start]and estimate the electricity bill[cite: 172, 141]. | |

---

## 🚀 Getting Started

### Login and Setup

1.  [cite_start]**Launch the Program:** Run the program and you will be prompted to log in or create an account[cite: 71, 94].
2.  **Login/Account Creation:**
    * [cite_start]If your ID is found, the system checks credentials and grants access[cite: 57, 58, 97].
    * [cite_start]If your ID is not found, you are prompted to create a new account by setting an ID and password[cite: 59, 61].
3.  [cite_start]**Component Configuration:** New users specify the **number of smart home components** they own (Fans, Lights, ACs, etc.)[cite: 64, 75, 78, 80]. [cite_start]You may optionally initialize the status and settings (e.g., brightness, temperature) for all your components[cite: 212, 224].

### User Control Interface

[cite_start]After a successful login, the main control menu is displayed[cite: 100, 101]:

| Menu Option | Action | Example Device Settings |
| :--- | :--- | :--- |
| **1. Turn ON a device** | [cite_start]Changes the device's power status to ON[cite: 102]. | |
| **2. Turn OFF a device** | [cite_start]Changes the device's power status to OFF[cite: 103]. | |
| **3. Adjust device settings** | [cite_start]Allows modification of device-specific attributes[cite: 104]. | [cite_start]Increase/Decrease **Temperature** (AC, Geyser) [cite: 287, 343][cite_start], **Speed** (Fan) [cite: 289, 391][cite_start], **Volume/Brightness** (TV, Light)[cite: 355, 356, 331]. |
| **4. Set timer for a device** | [cite_start]Automates the device to turn off after a specified duration[cite: 105, 386]. | |
| **5. Show device status** | [cite_start]View the current ON/OFF state[cite: 106]. | |
| **6. Show device complete info** | [cite_start]View the complete current configuration (e.g., channel, temperature)[cite: 107]. | |
| **7. Power Bill estimation** | [cite_start]Calculates the energy usage and cost based on logged ON/OFF times[cite: 108, 202]. | |
| **0/9. Exit** | [cite_start]Logs out the user, ensuring the current state of all devices is saved securely[cite: 109, 173, 174]. | |

---

## 🛠️ Limitations and Error Handling

### Current Limitations

* [cite_start]**Limited UI:** The application is **console-based**, which may not be user-friendly for non-technical users[cite: 368].
* [cite_start]**Timer Range:** Timer settings have a set range, which limits some device automation options[cite: 369].

### Error Handling

* [cite_start]**Input Validation:** The system ensures correct data types and values are entered[cite: 371].
* [cite_start]**Device Status Check:** Methods check device status before performing actions (e.g., settings cannot be adjusted if a device is OFF)[cite: 372, 431, 446, 464, 480, 494].

---

## 🔮 Future Enhancements

1.  [cite_start]**Graphical User Interface (GUI):** Improve usability by replacing the console interface with a GUI[cite: 375].
2.  [cite_start]**Advanced Device Simulation:** Expand functionalities to simulate real-time device responses[cite: 376].
3.  [cite_start]**Remote Access:** Enable remote access to control devices via the internet[cite: 377].

---

## 👥 Project Team

[cite_start]This project was developed by students of **IIITD&M Kancheepuram**[cite: 1].

| Name | Roll Number |
| :--- | :--- |
| Nithin Ch | [cite_start]CS23B1102 [cite: 6, 9] |
| Sanshrey G | [cite_start]CS23B2014 [cite: 7, 9] |
| Varshith B | [cite_start]CS23B2015 [cite: 8, 9] |
| Raviteja B | [cite_start]CS23B2011 [cite: 10, 12] |
| Susan B | [cite_start]CS23B2026 [cite: 11, 12] |

[cite_start]*Project Date: November 11, 2024* [cite: 13]
