#ifndef AC_H
#define AC_H

#include<iostream>
#include "devices.h"

using namespace std;

class AC : public Device 
{
protected:
    int temperature;   // Temperature of the AC in Celsius
    bool swing;        // Indicates if the swing function is on/off
    int fanspeed;      // Fanspeed level of the AC

public:
    // Constructor to initialize the AC device with given status, swing, temperature, and fanspeed
    AC(bool stat, bool swin, int temp, int fanspeed);  
    
    // Default constructor with default values for the AC device
    AC();  
    
    // Destructor (could be useful for cleaning up resources if needed)
    ~AC();  

    // Method to increase the temperature of the AC
    void increase_temp();  
    
    // Method to decrease the temperature of the AC
    void decrease_temp();  
    
    // Method to increase the fanspeed of the AC
    void increase_fanspeed();  
    
    // Method to decrease the fanspeed of the AC
    void decrease_fanspeed();  
    
    // Method to turn the swing function ON
    void on_swing();  
    
    // Method to turn the swing function OFF
    void off_swing();  
    
    // Method to set the timer for the AC (in minutes)
    void set_timer(int time);  
    
    // Method to set the temperature of the AC
    void set_temp(int temp);  
    
    // Method to set the swing function ON/OFF
    void set_swing(bool swin);  
    
    // Method to set the fanspeed of the AC
    void set_fanspeed(int speed);  
    
    // Method to set the device status (ON/OFF)
    void set_device_status(bool stat);  
    
    // Overloading the << operator to print the AC's status in a user-friendly format
    friend ostream& operator <<(ostream& out, AC& ac);  

    string toCSV(int h) ;
};

#endif
