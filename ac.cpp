#include<iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <string>
#include "ac.h"
#include "devices.h"

using namespace std;


// Constructor with parameters to initialize status, swing, temperature, and fanspeed
AC::AC(bool stat, bool swin, int temp, int fs) : Device(stat), temperature(temp), swing(swin), fanspeed(fs) {}

// Default constructor, initializes AC with default values
AC::AC() {
    status = false;   // AC is initially OFF
    temperature = 17;  // Default temperature (minimum value)
    swing = false;     // Swing is OFF by default
    fanspeed = 0;      // Minimum fanspeed by default
}

// Destructor (currently doesn't clean up any resources, but can be expanded in future)
AC::~AC() {}

// Method to increase the temperature of the AC, ensuring it doesn't exceed 30°C
void AC::increase_temp() {
    if (status) {
        if (temperature == 30) {
            cout << "It's already at the maximum temperature.\n";
        } else {
            temperature++;
            cout << "Temperature increased to: " << temperature << "C" << endl;
        }
    } else {
        cout << "Please turn on the AC first." << endl;
    }
}

// Method to decrease the temperature of the AC, ensuring it doesn't go below 17°C
void AC::decrease_temp() {
    if (status) {
        if (temperature == 17) {
            cout << "It's already at the minimum temperature.\n";
        } else {
            temperature--;
            cout << "Temperature decreased to: " << temperature << "C" << endl;
        }
    } else {
        cout << "Please turn on the AC first." << endl;
    }
}

// Method to increase the fanspeed of the AC, ensuring it doesn't exceed level 5
void AC::increase_fanspeed() {
    if (status) {
        if (fanspeed == 5) {
            cout << "It's already at the maximum fanspeed.\n";
        } else {
            fanspeed++;
            cout << "Fanspeed increased to: " << fanspeed << endl;
        }
    } else {
        cout << "Please turn on the AC first." << endl;
    }
}

// Method to decrease the fanspeed of the AC, ensuring it doesn't go below 0
void AC::decrease_fanspeed() {
    if (status) {
        if (fanspeed == 0) {
            cout << "It's already at the minimum fanspeed.\n";
        } else {
            fanspeed--;
            cout << "Fanspeed decreased to: " << fanspeed << endl;
        }
    } else {
        cout << "Please turn on the AC first." << endl;
    }
}

// Method to turn the swing function ON, if the AC is already on
void AC::on_swing() {
    if (status) {
        if (swing) {
            cout << "Swing is already ON.\n";
        } else {
            swing = true;
            cout << "Swing turned ON.\n";
        }
    } else {
        cout << "Please turn on the AC first.\n";
    }
}

// Method to turn the swing function OFF, if the AC is already on
void AC::off_swing() {
    if (status) {
        if (!swing) {
            cout << "Swing is already OFF.\n";
        } else {
            swing = false;
            cout << "Swing turned OFF.\n";
        }
    } else {
        cout << "Please turn on the AC first.\n";
    }
}

// Method to set a timer for the AC (currently just outputs the time for simulation purposes)
void AC::set_timer(int time) {
    cout << "AC timer set for " << time << " seconds." << endl;
    // Implement additional timer functionality if required
}

// Overloaded output operator to print the AC's status, temperature, fanspeed, swing, and power supply
ostream& operator <<(ostream& out, AC& ac) {
    ac.getstatus();
    cout << "Current temperature: " << ac.temperature << "C" << endl;
    cout << "Current fanspeed: " << ac.fanspeed << endl;
    cout << "Current swing status: " << (ac.swing ? "ON" : "OFF") << endl;
    ac.check_power_supply();
    ac.signal();
    return out;  // return the output stream for chaining
}

// Setters for the AC class (optional, but useful for modifying AC properties)
void AC::set_temp(int temp) {
    temperature = temp;
}

void AC::set_swing(bool swin) {
    swing = swin;
}

void AC::set_fanspeed(int fs) {
    fanspeed = fs;
}

void AC::set_device_status(bool stat) {
    status = stat;
}

string AC::toCSV(int h)
{
    return to_string(h) + "," + (status? "ON" : "OFF") + "," + to_string(temperature)+","+to_string(swing)+","+to_string(fanspeed);
}
