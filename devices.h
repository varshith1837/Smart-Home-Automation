#ifndef DEVICE_H
#define DEVICE_H
#include<iostream>
using namespace std;

class Device 
{
protected:
    bool status;  // Indicates whether the device is on or off

public:

    virtual string toCSV(int h) =0;
    // Constructor that initializes the device status (default is off)
    Device(bool stat = false);  
    
    // Destructor to clean up any resources (if needed)
    ~Device();  
    
    // Function to get the current status of the device
    bool getstatus();  
    
    // Function to turn the device ON
    void ON(string);  
    
    // Function to turn the device OFF
    void OFF(string);  
    
    // Function to send a signal (could be used for device-specific functionality)
    void signal();  
    
    // Function to check the power supply of the device (implementation needed)
    void check_power_supply();  
};

#endif
