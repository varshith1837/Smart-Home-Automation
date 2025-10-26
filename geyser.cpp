#include<iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <string>
#include<thread>  // Include thread for sleep functionality
#include "geyser.h"
#include "devices.h"

using namespace std;




// Constructor to initialize geyser with given status and temperature
Geyser::Geyser(bool stat, int temp) : Device(stat), temperature(temp) {}

// Destructor to clean up resources when the object is destroyed
Geyser::~Geyser() {}

// Default constructor to initialize geyser with default values (status = false, temperature = 10)
Geyser::Geyser()
{
    status = false;    // Geyser is initially off
    temperature = 10;  // Default temperature is set to 10°C
}

// Method to increase the temperature by 5 degrees if the geyser is on
void Geyser::increase_temp() {
    if (status) {
        temperature += 5;  // Increase temperature by 5 degrees
        cout << "Geyser temperature increased to: " << temperature << "C" << endl;
    } else {
        cout << "Please turn on the geyser first." << endl;  // Prompt if the geyser is off
    }
}

// Method to decrease the temperature by 5 degrees if the geyser is on
void Geyser::decrease_temp() {
    if (status) {
        temperature -= 5;  // Decrease temperature by 5 degrees
        cout << "Geyser temperature decreased to: " << temperature << "C" << endl;
    } else {
        cout << "Please turn on the geyser first." << endl;  // Prompt if the geyser is off
    }
}

// Method to set the timer for the geyser. After the timer, it will reverse the geyser's status.
void Geyser::set_timer(int time) 
{
    cout << "Geyser timer set for " << time << " seconds." << endl;
    
    // Sleep for the specified time (in seconds)
    //this_thread::sleep_for(chrono::seconds(time));
    
    // After the timer duration, reverse the geyser's status (turn it off if on, or on if off)
    status = !status;
    
    // Print the new status of the geyser
    if (status) {
        cout << "The geyser has been turned ON after " << time << " seconds." << endl;
    } else {
        cout << "The geyser has been turned OFF after " << time << " seconds." << endl;
    }
}

// Overloaded output stream operator to print the current state of the geyser
ostream& operator <<(ostream& out, Geyser& gy)
{
    gy.getstatus();  // Display the status (on/off)
    cout << "The present temperature is: " << gy.temperature << "C" << endl;  // Print the current temperature
    gy.check_power_supply();  // Check the power supply
    gy.signal();  // Signal (additional feature, could represent an alert or indication)
    return out;
}

// Method to set the device's status (on/off)
void Geyser::set_device_status(bool stat)
{
    status = stat;  // Update the geyser's status
}

// Method to set the temperature to a specific value
void Geyser::set_temperature(int temp)
{
    temperature = temp;  // Update the geyser's temperature
}

string Geyser::toCSV(int h)
{
    return to_string(h) + "," + (status? "ON" : "OFF") + "," + to_string(temperature);
}
