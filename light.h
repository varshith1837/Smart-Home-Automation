#ifndef LIGHT_H
#define LIGHT_H

#include <iostream>
#include "devices.h"

using namespace std;

// Light class inheriting from Device, representing a smart light with brightness and color control
class Light : public Device 
{
protected:
    int brightness;  // Brightness level of the light (0 to 10)
    int color;       // Color of the light, represented by an integer

public:
    // Constructor to initialize light status, brightness, and color
    Light(bool stat, int brt, int color);

    // Destructor for Light class
    ~Light();

    // Default constructor, initializes light with default values
    Light();

    // Overloaded operators to control brightness
    void operator++(); // Increase brightness
    void operator--(); // Decrease brightness

    // Method to change the light color
    void change_color();

    // Timer function to turn off the light after a specified time
    void set_timer(int time);

    // Setter for device status
    void set_device_status(bool);

    // Setter for brightness level
    void set_brightness(int);

    // Setter for color
    void set_color(int);

    // Friend function to enable output of light status and properties
    friend ostream& operator<<(ostream& out, Light& lt);

    string toCSV(int h) ;
};

#endif // LIGHT_H
