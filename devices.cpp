#include<iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include "devices.h"
using namespace std;

tm parseTimestamp(const string& timestamp) {
    tm timeStruct = {};
    istringstream ss(timestamp);
    ss >> get_time(&timeStruct, "%Y-%m-%d %H:%M:%S"); // Parse timestamp format
    if (ss.fail()) {
        throw runtime_error("Failed to parse timestamp: " + timestamp);
    }
    return timeStruct;
}

// Function to calculate total ON time from the CSV file
tuple<long long, long long, long long> calculateTotalOnTime(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return make_tuple(0, 0, 0); // Return zeroes if file can't be opened
    }

    string line, lastOnTimestamp;
    bool isOn = false;
    long long totalOnSeconds = 0;

    // Read the CSV file line by line
    while (getline(file, line)) {
        istringstream ss(line);
        string timestamp, status;

        // Split line into timestamp and status
        if (getline(ss, timestamp, ',') && getline(ss, status)) {
            if (status == "ON") {
                // Record the ON timestamp
                lastOnTimestamp = timestamp;
                isOn = true;
            } else if (status == "OFF" && isOn) {
                // Calculate duration between ON and OFF
                tm onTime = parseTimestamp(lastOnTimestamp);
                tm offTime = parseTimestamp(timestamp);

                time_t onTimeT = mktime(&onTime);
                time_t offTimeT = mktime(&offTime);

                if (onTimeT != -1 && offTimeT != -1) {
                    totalOnSeconds += difftime(offTimeT, onTimeT);
                }
                isOn = false; // Reset ON state
            }
        }
    }

    file.close();

    // Convert total seconds to hours, minutes, and seconds
    long long hours = totalOnSeconds / 3600;
    long long minutes = (totalOnSeconds % 3600) / 60;
    long long seconds = totalOnSeconds % 60;

    return make_tuple(hours, minutes, seconds); // Return as a tuple
}


string getCurrentTimestamp() {
    auto now = chrono::system_clock::now();
    time_t timeNow = chrono::system_clock::to_time_t(now);

    // Convert to human-readable format
    char buffer[100];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&timeNow));
    return string(buffer);
}

// Function to log the status change to a CSV file
void logDeviceStatus(const string& status,string filenametouse) {
    ofstream file(filenametouse, ios::app); // Open in append mode
    if (file.is_open()) {
        file << getCurrentTimestamp() << "," << status << endl;
        file.close();
        cout << "Logged: " << status << endl;
    } else {
        cerr << "Error opening file!" << endl;
    }
}


// Constructor to initialize the device status (default is false)
Device::Device(bool a): status(a) {}

// Destructor (currently not needed, but may be useful for resource management)
Device::~Device() {}

// Method to get and display the current status of the device (ON/OFF)
bool Device::getstatus() 
{
    // Switch statement to check device status and print corresponding message
    switch (status)
    {
    case true:
        cout << "The device is ON....." << endl;
        break;
    
    default:
        cout << "The device is OFF......" << endl;
        break;
    }
    return status;  // Returning the status for external checks (optional)
}

// Method to turn the device ON
void Device::ON(string filenametouse) 
{
    // Check if device is already ON
    if(status == true)
    {
        cout << "It's already ON....." << endl;
    }
    else
    {
          tuple<long long, long long, long long> onTime = calculateTotalOnTime(filenametouse);

         long long hours = get<0>(onTime);
         long long minutes = get<1>(onTime);
         long long seconds = get<2>(onTime);

       if(hours<3) {status = true;  // Change status to ON
        logDeviceStatus("ON",filenametouse);
        cout << "The device is switched ON....." << endl;}

       else{
        cout<<"Time limit exceeding the parental limit. Sorry I cant turn it on"<<endl;
       } 
    }
}

// Method to turn the device OFF
void Device::OFF(string filenametouse) 
{
    // Check if device is already OFF
    if(status == false)
    {
        cout << "It's already OFF....." << endl;
    }
    else
    {
        status = false;  // Change status to OFF
        logDeviceStatus("OFF",filenametouse);
        cout << "The device is switched OFF....." << endl;
    }
}

// Method to simulate signal strength and print status
void Device::signal() 
{
    int x = rand() % 6;  // Generate a random signal strength value between 0 and 5

    switch(x)
    {
        case 0:
            cout << "The signal strength is " << x << endl;
            cout << "The device is disconnected from the WiFi, please try to reconnect to access further applications....." << endl;
            break;

        case 1:
        case 2:
            cout << "The signal strength is " << x << " - Try to increase the strength" << endl;
            break;

        case 3:
            cout << "The signal strength is " << x << " - Better strength" << endl;
            break;

        case 4:
            cout << "The signal strength is " << x << " - Good strength" << endl;
            break;

        case 5:
            cout << "The signal strength is " << x << " - Best strength" << endl;
            break;
    }
}

// Method to check the power supply status (simulated as always ON)
void Device::check_power_supply() 
{
    int x = 1;  // Simulating power supply being ON

    switch (x)
    {
    case 1:
        cout << "The power supply is ON....." << endl;
        break;
    
    default:
        cout << "The power supply is OFF......" << endl;
        break;
    }
}
