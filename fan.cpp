#include<iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <ctime>
#include <string>
#include <thread> // For std::this_thread::sleep_for
#include"fan.h"
#include"devices.h"

using namespace std;



// Constructor initializes the fan status (on/off) and speed level
Fan::Fan(bool x, int y) : Device(x), speed(y) {}

// Destructor (currently doesn't clean up any resources, but can be expanded in the future)
Fan::~Fan() {}

// Default constructor initializes the fan as off with a speed of 0
Fan::Fan() {
    status = false;
    speed = 0;
}

// Overloaded increment operator to increase the speed of the fan
void Fan::operator++() {
    if (status == true) {
        if (speed < 5 && speed >= 0) {
            speed++;  // Increase speed by 1
            cout << "The speed is increased to: " << speed << endl;
        } else if (speed == 5) {
            cout << "It's already max...., Sorry can't increase..." << endl;
        } else {
            cout << "Something is going wrong, please reinitialize the device..." << endl;
        }
    } else {
        cout << "Please turn on the device first...." << endl;
    }
}

// Overloaded decrement operator to decrease the speed of the fan
void Fan::operator--() {
    if (status == true) {
        if (speed <= 5 && speed > 0) {
            speed--;  // Decrease speed by 1
            cout << "The speed is decreased to: " << speed << endl;
        } else if (speed == 0) {
            cout << "It's already zero...., Sorry can't decrease..." << endl;
        } else {
            cout << "Something is going wrong, please reinitialize the device..." << endl;
        }
    } else {
        cout << "Please turn on the device first...." << endl;
    }
}

// Set timer to reverse the status of the fan after the specified time
void Fan::set_timer(int duration) {
    // Check if the fan is on, if not, we can't proceed with reversing the status
    if (status == true) {
        cout << "Timer set for " << duration << " seconds." << endl;

        // Sleep for the given duration (in seconds)
        //this_thread::sleep_for(chrono::seconds(duration));

        // Reverse the status of the fan after the time has passed
        status = !status;  // Toggle the status (true to false or false to true)
        if (status) {
            cout << "Fan is now ON." << endl;
        } else {
            cout << "Fan is now OFF." << endl;
        }
    } else {
        cout << "Fan is off. Please turn it on before setting the timer." << endl;
    }
}

// Overloaded output stream operator for displaying fan information
ostream& operator <<(ostream& out, Fan& fn) {
    fn.getstatus();  // Print fan status (on/off)
    cout << "The present speed of fan is: " << fn.speed << endl;  // Print the current speed of the fan
    fn.check_power_supply();  // Print the power supply status
    fn.signal();  // Print signal strength
    return out;
}

// Method to set the fan's speed directly
void Fan::set_speed(int sp) {
    speed = sp;  // Set speed to the specified value
}

// Method to set the fan's device status (on/off)
void Fan::set_device_status(bool stat) {
    status = stat;  // Set the fan's status to the specified value
}

void Fan::setspeed(int sp)
{
    speed=sp;
}

string Fan::toCSV(int h)
{
   return to_string(h) + "," + (status? "ON" : "OFF") + "," + to_string(speed);
}

