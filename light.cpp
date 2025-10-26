#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <string>
#include "light.h"
#include "devices.h"

using namespace std;




// Parameterized constructor for initializing Light with status, brightness, and color
Light::Light(bool stat, int brt, int colr) : Device(stat), brightness(brt), color(colr) {}

// Destructor for Light class
Light::~Light() {}

// Default constructor initializing Light with default off status, no color, and zero brightness
Light::Light() {
    status = false;
    color = 0;
    brightness = 0;
}

// Overloaded operator++ to increase brightness if the light is on
void Light::operator++() {
    if (status) {
        if (brightness < 10) {
            brightness++;
            cout << "Brightness increased to: " << brightness << endl;
        } else {
            cout << "Brightness is already at maximum." << endl;
        }
    } else {
        cout << "Please turn on the light first." << endl;
    }
}

// Overloaded operator-- to decrease brightness if the light is on
void Light::operator--() {
    if (status) {
        if (brightness > 0) {
            brightness--;
            cout << "Brightness decreased to: " << brightness << endl;
        } else {
            cout << "Brightness is already at minimum." << endl;
        }
    } else {
        cout << "Please turn on the light first." << endl;
    }
}

// Function to change the light's color based on user input
void Light::change_color() {
    cout << "Select a color:\n1. White\n2. Red\n3. Blue\n4. Green\n5. Multi-color\n";
    cin >> color;
    while (true) {
        if (color >= 1 && color <= 5) break;
        cout << "Enter a valid input:" << endl;
        cin >> color;
    }

    // Display the chosen color
    switch (color) {
        case 1: cout << "Color changed to white...\n"; break;
        case 2: cout << "Color changed to red...\n"; break;
        case 3: cout << "Color changed to blue...\n"; break;
        case 4: cout << "Color changed to green...\n"; break;
        case 5: cout << "Color changed to multi-color...\n"; break;
        default: cout << "Incorrect input...\n"; break;
    }
}

// Function to set a timer for the light to automatically turn off after a certain time
void Light::set_timer(int time) {
    cout << "Light timer set for " << time << " seconds." << endl;
    // Timer functionality to be implemented
}

// Overloaded output operator to display the light's status, brightness, and color
ostream& operator<<(ostream& out, Light& lt) {
    lt.getstatus(); // Display power status
    cout << "The current brightness level is: " << lt.brightness << endl;

    // Display the current color based on the color code
    switch (lt.color) {
        case 1: cout << "The color is white.\n"; break;
        case 2: cout << "The color is red.\n"; break;
        case 3: cout << "The color is blue.\n"; break;
        case 4: cout << "The color is green.\n"; break;
        case 5: cout << "The color is multi-color.\n"; break;
        default: cout << "Incorrect color input.\n"; break;
    }

    lt.check_power_supply(); // Display power supply status
    lt.signal(); // Additional status signal if needed
    return out;
}

// Setter function to manually set brightness level
void Light::set_brightness(int brigh) {
    brightness = brigh;
}

// Setter function to manually set color
void Light::set_color(int col) {
    color = col;
}

string Light::toCSV(int h)
{
    return to_string(h) + "," + (status? "ON" : "OFF") + "," + to_string(brightness)+","+to_string(color);
}

// Setter function to turn the light on or off
void Light::set_device_status(bool stat) {
    status = stat;
}
