#include<iostream>
#include "fridge.h"
#include "devices.h"
#include <fstream>
#include <chrono>
#include <ctime>
#include <string>
#include <thread>  // For sleep_for

using namespace std;



Fridge::Fridge(bool stat, int level) : Device(stat), cooling_level(level) {}
Fridge::~Fridge() {}

Fridge::Fridge()
{
    status = false;
    cooling_level = 0;
}

void Fridge::increase_cooling() {
    if (status) {
        if (cooling_level < 5) {
            cooling_level++;
            cout << "Cooling level increased to: " << cooling_level << endl;
        } else {
            cout << "Cooling level is already at maximum." << endl;
        }
    } else {
        cout << "Please turn on the fridge first." << endl;
    }
}

void Fridge::decrease_cooling() {
    if (status) {
        if (cooling_level > 1) {
            cooling_level--;
            cout << "Cooling level decreased to: " << cooling_level << endl;
        } else {
            cout << "Cooling level is already at minimum." << endl;
        }
    } else {
        cout << "Please turn on the fridge first." << endl;
    }
}

void Fridge::set_timer(int time) {
    cout << "Fridge timer set for " << time << " seconds." << endl;
    
    // Simulate timer using chrono to wait for the specified time
   // this_thread::sleep_for(chrono::seconds(time));  // Sleep for the time duration
    
    // After timer, reverse the status of the fridge (turn off if on, or vice versa)
    status = !status;  // Reverse the fridge status
    if (status) {
        cout << "Fridge turned ON after timer." << endl;
    } else {
        cout << "Fridge turned OFF after timer." << endl;
    }
}

ostream& operator <<(ostream& out, Fridge& fr) {
    fr.getstatus();
    cout << "The present cooling level is: " << fr.cooling_level << endl;
    fr.check_power_supply();
    fr.signal();
    return out;
}

void Fridge::set_device_status(bool stat) {
    status = stat;
}

void Fridge::set_cooling_level(int cool) {
    cooling_level = cool;
}

string Fridge::toCSV(int h)
{
    return to_string(h) + "," + (status? "ON" : "OFF") + "," + to_string(cooling_level);
}
