#ifndef GEYSER_H
#define GEYSER_H

#include<iostream>
#include "devices.h"  // Include the base class header for Device class

using namespace std;

// Geyser class inherits from the Device class
class Geyser : public Device {
protected:
    int temperature; // Holds the current temperature of the geyser

public:
    // Constructor with parameters to initialize the geyser's status and temperature
    Geyser(bool stat, int temp);

    // Default constructor to initialize default values for status and temperature
    Geyser();

    // Destructor
    ~Geyser();

    // Method to increase the temperature of the geyser
    void increase_temp();

    // Method to decrease the temperature of the geyser
    void decrease_temp();

    // Method to set a timer for the geyser (to be implemented)
    void set_timer(int time);

    // Setter method to update the status of the geyser
    void set_device_status(bool stat);

    // Setter method to update the temperature of the geyser
    void set_temperature(int temp);

    // Friend function to overload the stream insertion operator for Geyser class
    friend ostream& operator <<(ostream& out, Geyser& gy); 

    string toCSV(int h) ;
};

#endif
