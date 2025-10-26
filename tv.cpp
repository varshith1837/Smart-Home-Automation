#include "tv.h"
#include <fstream>
#include <chrono>
#include <ctime>
#include <string>



// Default constructor initializing TV attributes to default values
Tv::Tv() {
    status = false;
    chan = 0;
    vol = 0;
    brightness = 0;
}

// Parameterized constructor with validation checks for channel, volume, and brightness
Tv::Tv(bool stat, int cha, int vl, int br) : Device(stat) {
    if (cha >= 0 && cha <= 1000) {
        chan = cha;
    } else {
        chan = 0;
        cout << "Invalid channel number, assigned as zero....\n";
    }

    if (vl >= 0 && vl <= 100) {
        vol = vl;
    } else {
        vol = 0;
        cout << "Invalid volume, assigned as zero....\n";
    }

    if (br >= 0 && br <= 100) {
        brightness = br;
    } else {
        brightness = 0;
        cout << "Invalid brightness, assigned as zero....\n";
    }
}

// Destructor
Tv::~Tv() {}

// Change to the next channel (wraps around to 0 if channel is at max)
void Tv::next() {
    if (chan == 1000) {
        chan = 0;
    } else {
        chan++;
    }
    cout << "The channel is changed to " << chan << endl;
}

// Change to the previous channel (wraps around to max if channel is at 0)
void Tv::prev() {
    if (chan == 0) {
        chan = 1000;
    } else {
        chan--;
    }
    cout << "The channel is changed to " << chan << endl;
}

// Change to a specific channel input by the user
void Tv::to_chan() {
    int x;
    cout << "Enter the channel number to change (0-1000 only): ";
    cin >> x;
    chan = x;
    cout << "The channel is changed to " << chan << endl;
}

// Increase volume, if below max level
void Tv::inc_vol() {
    if (vol >= 0 && vol < 100) {
        vol++;
        cout << "The volume is changed to " << vol << endl;
    } else if (vol == 100) {
        cout << "The volume is already at max...." << endl;
    }
}

// Decrease volume, if above minimum level
void Tv::dec_vol() {
    if (vol > 0 && vol <= 100) {
        vol--;
        cout << "The volume is changed to " << vol << endl;
    } else if (vol == 0) {
        cout << "The volume is already at zero...." << endl;
    }
}

// Increase brightness, if below max level
void Tv::inc_bri() {
    if (brightness >= 0 && brightness < 100) {
        brightness++;
        cout << "The brightness is changed to " << brightness << endl;
    } else if (brightness == 100) {
        cout << "The brightness is already at max...." << endl;
    }
}

// Decrease brightness, if above minimum level
void Tv::dec_bri() {
    if (brightness > 0 && brightness <= 100) {
        brightness--;
        cout << "The brightness is changed to " << brightness << endl;
    } else if (brightness == 0) {
        cout << "The brightness is already at zero...." << endl;
    }
}

// Set a timer for the TV (to be implemented later)
void Tv::set_timer(int time) {
    // Placeholder for future implementation
}

// Overloaded output operator to display TV's status, channel, volume, and brightness
ostream& operator<<(ostream& out, Tv& tv) {
    tv.getstatus();
    cout << "The present channel is: " << tv.chan << endl;
    cout << "The present volume is: " << tv.vol << endl;
    cout << "The present brightness is: " << tv.brightness << endl;
    tv.check_power_supply();
    tv.signal();
    return out;
}

// Set channel to a specified value
void Tv::set_channel(int channel) {
    chan = channel;
}

// Set brightness to a specified value
void Tv::set_brightness(int brigh) {
    brightness = brigh;
}

// Set volume to a specified value
void Tv::set_volume(int volume) {
    vol = volume;
}

// Set the device's power status (on/off)
void Tv::set_device_status(bool stat) {
    status = stat;
}

string Tv::toCSV(int h)
{
    return to_string(h) + "," + (status? "ON" : "OFF") + "," + to_string(chan)+","+ to_string(vol)+","+ to_string(brightness);
}
