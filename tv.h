#ifndef TV_H
#define TV_H

#include <iostream>
#include "devices.h"

using namespace std;

class Tv : public Device 
{
protected:
    int chan;       // Current channel number
    int vol;        // Volume level
    int brightness; // Brightness level

public:
    // Parameterized constructor to initialize TV status, channel, volume, and brightness
    Tv(bool stat, int chan, int vol, int bri);
    
    // Destructor for the Tv class
    ~Tv();
    
    // Default constructor to initialize TV with default values
    Tv();

    // Function to go to the next channel
    void next();

    // Function to go to the previous channel
    void prev();

    // Function to change to a specific channel
    void to_chan();

    // Function to increase the volume level
    void inc_vol();

    // Function to decrease the volume level
    void dec_vol();

    // Function to increase the brightness level
    void inc_bri();

    // Function to decrease the brightness level
    void dec_bri();

    // Function to set a timer for the TV to automatically turn off after a specified time
    void set_timer(int time);

    // Setter for the channel
    void set_channel(int);

    // Setter for the volume level
    void set_volume(int);

    // Setter for the brightness level
    void set_brightness(int);

    // Setter for the device status (on/off)
    void set_device_status(bool);

    // Overloaded output operator to display TV's current status, channel, volume, and brightness
    friend ostream& operator<<(ostream& out, Tv& tv);

    string toCSV(int h) ;
};

#endif
