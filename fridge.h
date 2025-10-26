
#ifndef FRIDGE_H
#define FRIDGE_H

#include<iostream>
#include "devices.h"

using namespace std;

class Fridge : public Device {
protected:
    int cooling_level; // Cooling level of the fridge (e.g., 0-5)

public:
    // Constructors
    Fridge(bool stat, int level);  // Parameterized constructor
    Fridge();  // Default constructor
    ~Fridge(); // Destructor

    // Methods for adjusting cooling level
    void increase_cooling();  // Increase cooling level
    void decrease_cooling();  // Decrease cooling level

    // Timer functionality (perhaps for automatic turn-off)
    void set_timer(int time);  

    // Set device status (turn fridge on/off)
    void set_device_status(bool stat);  

    // Set the cooling level directly
    void set_cooling_level(int level);  

    // Overloading the << operator for displaying fridge status
    friend ostream& operator <<(ostream& out, Fridge& fr); 

    string toCSV(int h) ; 
};

#endif
