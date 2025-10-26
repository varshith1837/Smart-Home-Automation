#ifndef FAN_H
#define FAN_H

#include<iostream>
#include"devices.h"

using namespace std;

// Fan class inherits from the Device class
class Fan : public Device {
protected:
    int speed;  // Fan speed level

public:
    // Constructor that initializes the fan with a status (on/off) and a speed level
    Fan(bool stat, int sp);

    // Default constructor, initializes the fan as off with a speed of 0
    Fan();

    // Destructor (currently doesn't clean up any resources, but can be expanded in the future)
    ~Fan();

    // Method to set the speed of the fan
    void set_speed(int sp);

    // Overloaded increment operator (to increase the speed)
    void operator++();

    // Overloaded decrement operator (to decrease the speed)
    void operator--();

    // Method to set a timer for the fan (currently just outputs the time for simulation purposes)
    void set_timer(int time);

    // Setter method for the fan's status (turns the fan on or off)
    void set_device_status(bool stat);

    // Setter method to set the fan's speed
    void setspeed(int sp);

    string toCSV(int h) ;
    // Friend function to overload the output stream operator for displaying fan information
    friend ostream& operator<<(ostream& out, Fan& fn);
};

#endif
