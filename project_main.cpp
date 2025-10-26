// Include standard and custom headers
#include <iostream>
// Include standard and custom headers
#include <fstream>
// Include standard and custom headers
#include <sstream>
// Include standard and custom headers
#include <vector>
// Include standard and custom headers
#include <string>
// Include standard and custom headers
#include <iomanip>
// Include standard and custom headers
#include <chrono>
// Include standard and custom headers
#include <ctime>
// Include standard and custom headers
#include "devices.h"
// Include standard and custom headers
#include "fan.h"
// Include standard and custom headers
#include "tv.h"
// Include standard and custom headers
#include "ac.h"
// Include standard and custom headers
#include "geyser.h"
// Include standard and custom headers
#include "fridge.h"
// Include standard and custom headers
#include "light.h"

using namespace std;

// User structure to store user credentials and device counts
struct User {
    string id;
    string password;
    int values[6];
};

 int fan_x,light_x,ac_x,fridge_x,geyser_x,tv_x;
  int n_fan,n_light,n_fridge,n_ac,n_geyser,n_tv;
  string id;
 
Fan fan_arr[50];                              // creating Fans
Light light_arr[50];                        // Creating Lights
Tv tv_arr[50];                                 // Creating Tv's
Geyser geyser_arr[50];                     // Creating geysers
AC ac_arr[50];                                 // Creating AC's
Fridge fridge_arr[50]; 


// Function to load user data from a file
vector<User> loadUsers(const string &filename) {
    vector<User> users;
    ifstream file(filename);
    string line;
    
    while (getline(file, line)) {
        stringstream ss(line);
        User user;
        string temp;
        getline(ss, user.id, ',');
        getline(ss, user.password, ',');
        for (int i = 0; i < 6; i++) {
            getline(ss, temp, ',');
            user.values[i] = stoi(temp);
        }
        users.push_back(user);
    }
    file.close();
    return users;
}

// Save all device states to a CSV file

// Function to save device states to a CSV file
void saveDeviceStates(const string &filename, Fan fan[], int n_fan, Light light[], int n_light, 
                      Tv tv[], int n_tv, Geyser geyser[], int n_geyser, AC ac[], int n_ac, Fridge fridge[], int n_fridge) {
    ofstream file(filename, ios::trunc);

    file<<n_fan<<","<<n_light<<","<<n_tv<<","<<n_geyser<<","<<n_ac<<","<<n_fridge<<"\n";

    for (int i = 0; i < n_fan; ++i) {
        file << "fan," << fan[i].toCSV(i) << "\n";
    }
    for (int i = 0; i < n_light; ++i) {
        file << "light," << light[i].toCSV(i) << "\n";
    }
    for (int i = 0; i < n_tv; ++i) {
        file << "tv," << tv[i].toCSV(i) << "\n";
    }
    for (int i = 0; i < n_geyser; ++i) {
        file << "geyser," << geyser[i].toCSV(i) << "\n";
    }
    for (int i = 0; i < n_ac; ++i) {
        file << "ac," << ac[i].toCSV(i) << "\n";
    }
    for (int i = 0; i < n_fridge; ++i) {
        file << "fridge," << fridge[i].toCSV(i) << "\n";
    }
    file.close();
}


// Function to load device states from a CSV file
void loadDeviceStates(const string &filename, int &n_fan, int &n_light, int &n_tv, 
                      int &n_geyser, int &n_ac, int &n_fridge, 
                      Fan fan[], Light light[], Tv tv[], 
                      Geyser geyser[], AC ac[], Fridge fridge[]) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    string line;

    // Read the first line to initialize counts
    if (getline(file, line)) {
        stringstream ss(line);
        string temp;
        try {
            getline(ss, temp, ','); n_fan = stoi(temp);
            getline(ss, temp, ','); n_light = stoi(temp);
            getline(ss, temp, ','); n_tv = stoi(temp);
            getline(ss, temp, ','); n_geyser = stoi(temp);
            getline(ss, temp, ','); n_ac = stoi(temp);
            getline(ss, temp, ','); n_fridge = stoi(temp);
        } catch (const invalid_argument &e) {
            cerr << "Error: Invalid count in first line: " << line << endl;
            return;
        }
    }

    // Read device states and map them to respective arrays based on index
    while (getline(file, line)) {
        stringstream ss(line);
        string type, temp;
        int index;

        getline(ss, type, ',');
        getline(ss, temp, ',');
        try {
            index = stoi(temp);
        } catch (const invalid_argument &e) {
            cerr << "Error: Invalid index in line: " << line << endl;
            continue;
        }

        if (type == "fan") {
            bool state;
            int speed;
            getline(ss, temp, ','); state = (temp == "ON");
            getline(ss, temp, ','); speed = stoi(temp);

            if (index < 0 || index >= n_fan) {
                cerr << "Error: Fan index out of bounds: " << index << endl;
                continue;
            }
            fan[index].set_device_status(state);
            fan[index].set_speed(speed);
        } 
        else if (type == "light") {
            bool state;
            int brightness, color;
            getline(ss, temp, ','); state = (temp == "ON");
            getline(ss, temp, ','); brightness = stoi(temp);
            getline(ss, temp, ','); color = stoi(temp);

            if (index < 0 || index >= n_light) {
                cerr << "Error: Light index out of bounds: " << index << endl;
                continue;
            }
            light[index].set_device_status(state);
            light[index].set_brightness(brightness);
            light[index].set_color(color);
        } 

        else if (type == "tv") {
            bool state;
            int chan,vol,brightness;
            getline(ss, temp, ','); state = (temp == "ON");
            getline(ss, temp, ','); chan = stoi(temp);
            getline(ss, temp, ','); vol = stoi(temp);
            getline(ss, temp, ','); brightness = stoi(temp);

            if (index < 0 || index >= n_light) {
                cerr << "Error: Light index out of bounds: " << index << endl;
                continue;
            }
            tv[index].set_device_status(state);
            tv[index].set_brightness(brightness);
            tv[index].set_volume(vol);
            tv[index].set_channel(chan);
            
        } 

        else if (type == "fridge") {
            bool state;
            int cl;
            getline(ss, temp, ','); state = (temp == "ON");
            getline(ss, temp, ','); cl = stoi(temp);
          

            if (index < 0 || index >= n_light) {
                cerr << "Error: Light index out of bounds: " << index << endl;
                continue;
            }
            fridge[index].set_device_status(state);
            fridge[index].set_cooling_level(cl);
           
            
        } 

        else if (type == "geyser") {
            bool state;
            int temper;
            getline(ss, temp, ','); state = (temp == "ON");
            getline(ss, temp, ','); temper = stoi(temp);
        

            if (index < 0 || index >= n_light) {
                cerr << "Error: Light index out of bounds: " << index << endl;
                continue;
            }
            geyser[index].set_device_status(state);
            geyser[index].set_temperature(temper);
           
            
        } 

        else if (type == "ac") {
            bool state;
            int temper,swing,fs;
            getline(ss, temp, ','); state = (temp == "ON");
            getline(ss, temp, ','); temper = stoi(temp);
            getline(ss, temp, ','); swing = stoi(temp);
            getline(ss, temp, ','); fs = stoi(temp);

            if (index < 0 || index >= n_light) {
                cerr << "Error: Light index out of bounds: " << index << endl;
                continue;
            }
            ac[index].set_device_status(state);
            ac[index].set_fanspeed(fs);
            ac[index].set_temp(temper);
            ac[index].set_swing(swing);
            
        } 
        
    }

    file.close();
}

// Function to save users back to file
void saveUsers(const vector<User> &users, const string &filename) {
    ofstream file(filename, ios::trunc);
    for (const auto &user : users) {
        file << user.id << "," << user.password;
        for (int i = 0; i < 6; i++) {
            file << "," << user.values[i];
        }
        file << "\n";
    }
    file.close();
}

// Function to find a user by ID
int findUser(const vector<User> &users, const string &id) {
    for (size_t i = 0; i < users.size(); i++) {
        if (users[i].id == id)
            return i;
    }
    return -1;
}



// Function to display the main menu options
void displayMenu() {
    cout << "\nSmart Home Device Controller by IIITDM\n";
    cout << "1. Turn ON a device\n";
    cout << "2. Turn OFF a device\n";
    cout << "3. Adjust device settings\n";
    cout << "4. Set timer for a device\n";
    cout << "5. Show device status\n";
    cout << "6. Show device complete info\n";
    cout << "7. Power Bill estimtion\n";
    cout << "0. Exit\n";
    cout << "Choose an option: ";
}



void adjustSettings(Fan fan[], Light light[], AC ac[], Fridge fridge[], Geyser geyser[],Tv Tv[],int choice) {

    if (choice == 1) {
        cout << "1. Increase speed\n2. Decrease speed\n";
        cin >> choice;
        if (choice == 1) ++fan[fan_x];
        else if (choice == 2) --fan[fan_x];
    } else if (choice == 2) {
        cout << "1. Increase brightness\n2. Decrease brightness\n3. Change colour\n";
        cin >> choice;
        if (choice == 1) ++light[light_x];
        else if (choice == 2) --light[light_x];
        else if (choice == 3) light[light_x].change_color();
    } else if (choice == 3) { int x;
        cout << "1. Increase temperature\n2. Decrease temperature\n3.increase fanspeed\n4.decrease fanspeed\n5.on_swing\n6.off_swing\n";
        cin >> choice;
        if (choice == 1) ac[ac_x].increase_temp();
        else if (choice == 2) ac[ac_x].decrease_temp();
        else if (choice == 3) ac[ac_x].increase_fanspeed();
        else if (choice == 4) ac[ac_x].decrease_fanspeed();
        else if (choice == 5) ac[ac_x].on_swing();
        else if (choice == 6) ac[ac_x].off_swing();

    } else if (choice == 4) {
        cout << "1. Increase cooling level\n2. Decrease cooling level\n";
        cin >> choice;
        if (choice == 1) fridge[fridge_x].increase_cooling();
        else if (choice == 2) fridge[fridge_x].decrease_cooling();
    } else if (choice == 5) {
        cout << "1. Increase temperature\n2. Decrease temperature\n";
        cin >> choice;
        if (choice == 1) geyser[geyser_x].increase_temp();
        else if (choice == 2) geyser[geyser_x].decrease_temp();
    }else if (choice == 6) {
        cout << "1.Next channel\n2. previous channel\n3. to a channel\n4.increase volume\n5.decrease volume\n6.increase brightness\n7.decrease brightness\n";
        cin >> choice;
        if (choice == 1)Tv[tv_x].next() ;
        else if (choice == 2) Tv[tv_x].prev();
        else if (choice == 3)Tv[tv_x].to_chan();
        else if (choice == 4)Tv[tv_x].inc_vol();
        else if (choice == 5)Tv[tv_x].dec_vol();
        else if (choice == 6)Tv[tv_x].inc_bri();
        else if (choice == 7)Tv[tv_x].dec_bri();
    }  
    else {
        cout << "Invalid option.\n";
    }
}


void setTimer(Device& device) {
    int duration;
    cout << "Enter timer duration (seconds): ";
    cin >> duration;
    cout<<"the timer has been set...."<<endl;
}


bool get_status()
{
    int x;
    cin>>x;
    while (1)
    {
    if(x!=0 && x!=1)
    {
        cout<<"Enter valid input:"<<endl;
        cin>>x;
    }
    else 
    break;
    }
    if (x==0)
    {
        return false;
    }
    else 
    {
        return true;
    }
}

void assign_light(Light *light,int i)      
{
    cout<<"Info for the light number "<<i<<endl;
    bool device_status;
    int brightness;
    int color;
    cout << "Enter the status of the light (1 for ON, 0 for OFF): ";
    device_status=get_status();
    if (device_status==true)
    {
        cout << "Enter the brightness (1-100): ";
        cin >> brightness;
        cout << "Enter the light color (1-5): ";
        cin >> color;
        light->set_device_status(device_status);
        light->set_brightness(brightness);
        light->set_color(color);
    }
    else
    {
        light->set_device_status(false);
        light->set_brightness(0);
        light->set_color(0);
    }
}

void assign_fan(Fan *fan,int i)            
{
    
    cout<<"Info for the fan number "<<i<<endl;
    bool device_status;
    int fanspeed;
    cout << "Enter the status of the fan (1 for ON, 0 for OFF): ";
    device_status=get_status();
    if (device_status==true)
    {
        cout << "Enter the initial fan speed (0-5): ";
        cin >> fanspeed;
    while (1)
    {
        if (fanspeed>5 || fanspeed<0)
        {
            cout<<"enter correct input:"<<endl;
            cin>>fanspeed;
        }
        else
        break;
    }
        fan->set_device_status(device_status);
        fan->set_speed(fanspeed);
    }
    else
    {
        fan->set_device_status(false);
        fan->set_speed(0);
    }

}

void assign_tv( Tv *tv,int i)               
{ 
    cout<<"Info for the tv number "<<i<<endl;
    bool device_status;
    int channel,volume,brightness;
    cout << "Enter the status of the TV (1 for ON, 0 for OFF): ";
    device_status=get_status();
    if (device_status==true)
    {
        cout << "Enter the initial channel number (0-1000): ";
        cin >> channel;
        cout << "Enter the initial volume (0-100): ";
        cin >> volume;
        cout << "Enter the initial brightness (0-100): ";
        cin >> brightness;
        tv->set_channel(channel);
        tv->set_volume(volume);
        tv->set_brightness(brightness);
        tv->set_device_status(device_status);
    }
    else
    {
        tv->set_channel(0);
        tv->set_volume(0);
        tv->set_brightness(0);
        tv->set_device_status(false);
    }

}

void assign_ac(AC *ac,int i)               
{
    cout<<"Info for the AC number "<<i<<endl;
    bool device_status,swing_status;
    int fanspeed,temp;
    cout << "Enter the status of the AC (1 for ON, 0 for OFF): ";
    device_status=get_status();
    if (device_status==true)
    {
        cout << "Enter the initial temperature (17-30): ";
        cin >> temp;
    while(1)
    {
        if (temp<17 || temp>30)
        {
            cout<<"Enter valid input:"<<endl;
            cin>>temp;
        }
        else 
        break;
    }
        cout << "Enter the initial fan speed (0-5): ";
        cin >> fanspeed;
    while(1)
    {
        if (fanspeed<0 || fanspeed>5)
        {
            cout<<"Enter valid input:"<<endl;
            cin>>fanspeed;
        }
        else 
        break;
    }
    
        cout << "Enter the swing status (1 for ON, 0 for OFF): ";
        swing_status=get_status();
        ac->set_device_status(device_status);
        ac->set_fanspeed(fanspeed);
        ac->set_temp(temp);
        ac->set_swing(swing_status);
    }
    else
    {
        ac->set_device_status(false);
        ac->set_fanspeed(0);
        ac->set_temp(0);
        ac->set_swing(false);
    }
}

void assign_geyser(Geyser *geyser,int i)   
{
    cout<<"Info for the geyser number "<<i<<endl;
    cout << "Enter the status of the geyser (1 for ON, 0 for OFF): ";
    bool device_status = get_status();
    if (device_status==true)
    {
        int temp;
        cout << "Enter the temperature of the geyser (10-100): ";
        cin >> temp;
    while(1)
    {
        if (temp<10 || temp>100)
        {
            cout<<"Enter valid input:"<<endl;
            cin>>temp;
        }
        else 
        break;
    }
        geyser->set_device_status(device_status);
        geyser->set_temperature(temp);
    }
    else
    {
        geyser->set_device_status(false);
        geyser->set_temperature(0);
    }

}

void assign_fridge(Fridge *fridge,int i)
{
    cout<<"Info for the Fridge number "<<i<<endl;
    int cooling_level;
    cout << "Enter the status of the fridge (1 for ON, 0 for OFF): "<<endl;
    bool device_status =get_status();
    if (device_status==true)
    {
        cout << "Enter the cooling level (5 to -20): "<<endl;
        cin >> cooling_level;
    while(1)
    {
        if (cooling_level<-20|| cooling_level>5)
        {
            cout<<"Enter valid input:"<<endl;
            cin>>cooling_level;
        }
        else 
        break;
    }
        fridge->set_device_status(device_status);
        fridge->set_cooling_level(cooling_level);
    }
    else
    {
        fridge->set_device_status(false);
        fridge->set_cooling_level(0);
    }

}

void setTimer()
{
    int x;
    cin>>x;
    cout<<"the timer is set for "<<x<<" seconds .....\n";

}

tm parseTimestamp1(const string& timestamp) {
    tm timeStruct = {};
    istringstream ss(timestamp);
    ss >> get_time(&timeStruct, "%Y-%m-%d %H:%M:%S"); // Parse timestamp format
    if (ss.fail()) {
        throw runtime_error("Failed to parse timestamp: " + timestamp);
    }
    return timeStruct;
}

tuple<long long, long long, long long> calculateTotalOnTime1(const string& filename) {
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
                tm onTime = parseTimestamp1(lastOnTimestamp);
                tm offTime = parseTimestamp1(timestamp);

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



int powerbill() {
    int cost = 0;

    // Get power rates from the user
    int fan_rate, light_rate, ac_rate, fridge_rate, geyser_rate, tv_rate;

    cout << "Enter power rate (in watts per hour) for the following devices:\n";
    cout << "Fan: ";
    cin >> fan_rate;
    cout << "Light: ";
    cin >> light_rate;
    cout << "AC: ";
    cin >> ac_rate;
    cout << "Fridge: ";
    cin >> fridge_rate;
    cout << "Geyser: ";
    cin >> geyser_rate;
    cout << "TV: ";
    cin >> tv_rate;
    cout<<endl;
    // Fan calculations
    int fan_hr = 0, fan_mn = 0, fan_sec = 0;
    for (int i = 0; i < n_fan; i++) {
        string filename = id + "fan" + to_string(i) + ".csv";
        tuple<long long, long long, long long> onTime = calculateTotalOnTime1(filename);
        long long hours = get<0>(onTime);
        long long minutes = get<1>(onTime);
        long long seconds = get<2>(onTime);

        cout << "The Fan " << i + 1 << " is ON for " << hours << " hours, " << minutes << " minutes, and " << seconds << " seconds.\n";

        fan_hr += hours;
        fan_mn += minutes;
        fan_sec += seconds;
    }
    double total_fan_time = fan_hr + fan_mn / 60.0 + fan_sec / 3600.0;
    cost += total_fan_time * fan_rate;
    cout<<endl;
    // Light calculations
    int li_hr = 0, li_mn = 0, li_sec = 0;
    for (int i = 0; i < n_light; i++) {
        string filename = id + "light" + to_string(i) + ".csv";
        tuple<long long, long long, long long> onTime = calculateTotalOnTime1(filename);
        long long hours = get<0>(onTime);
        long long minutes = get<1>(onTime);
        long long seconds = get<2>(onTime);

        cout << "The Light " << i + 1 << " is ON for " << hours << " hours, " << minutes << " minutes, and " << seconds << " seconds.\n";

        li_hr += hours;
        li_mn += minutes;
        li_sec += seconds;
    }
    double total_light_time = li_hr + li_mn / 60.0 + li_sec / 3600.0;
    cost += total_light_time * light_rate;
    cout<<endl;
    // AC calculations
    int ac_hr = 0, ac_mn = 0, ac_sec = 0;
    for (int i = 0; i < n_ac; i++) {
        string filename = id + "ac" + to_string(i) + ".csv";
        tuple<long long, long long, long long> onTime = calculateTotalOnTime1(filename);
        long long hours = get<0>(onTime);
        long long minutes = get<1>(onTime);
        long long seconds = get<2>(onTime);

        cout << "The AC " << i + 1 << " is ON for " << hours << " hours, " << minutes << " minutes, and " << seconds << " seconds.\n";

        ac_hr += hours;
        ac_mn += minutes;
        ac_sec += seconds;
    }
    double total_ac_time = ac_hr + ac_mn / 60.0 + ac_sec / 3600.0;
    cost += total_ac_time * ac_rate;
    cout<<endl;
    // Fridge calculations
    int fri_hr = 0, fri_mn = 0, fri_sec = 0;
    for (int i = 0; i < n_fridge; i++) {
        string filename = id + "fridge" + to_string(i) + ".csv";
        tuple<long long, long long, long long> onTime = calculateTotalOnTime1(filename);
        long long hours = get<0>(onTime);
        long long minutes = get<1>(onTime);
        long long seconds = get<2>(onTime);

        cout << "The Fridge " << i + 1 << " is ON for " << hours << " hours, " << minutes << " minutes, and " << seconds << " seconds.\n";

        fri_hr += hours;
        fri_mn += minutes;
        fri_sec += seconds;
    }
    double total_fridge_time = fri_hr + fri_mn / 60.0 + fri_sec / 3600.0;
    cost += total_fridge_time * fridge_rate;
    cout<<endl;
    // Geyser calculations
    int gey_hr = 0, gey_mn = 0, gey_sec = 0;
    for (int i = 0; i < n_geyser; i++) {
        string filename = id + "geyser" + to_string(i) + ".csv";
        tuple<long long, long long, long long> onTime = calculateTotalOnTime1(filename);
        long long hours = get<0>(onTime);
        long long minutes = get<1>(onTime);
        long long seconds = get<2>(onTime);

        cout << "The Geyser " << i + 1 << " is ON for " << hours << " hours, " << minutes << " minutes, and " << seconds << " seconds.\n";

        gey_hr += hours;
        gey_mn += minutes;
        gey_sec += seconds;
    }
    double total_geyser_time = gey_hr + gey_mn / 60.0 + gey_sec / 3600.0;
    cost += total_geyser_time * geyser_rate;
    cout<<endl;
    // TV calculations
    int tv_hr = 0, tv_mn = 0, tv_sec = 0;
    for (int i = 0; i < n_tv; i++) {
        string filename = id + "tv" + to_string(i) + ".csv";
        tuple<long long, long long, long long> onTime = calculateTotalOnTime1(filename);
        long long hours = get<0>(onTime);
        long long minutes = get<1>(onTime);
        long long seconds = get<2>(onTime);

        cout << "The TV " << i + 1 << " is ON for " << hours << " hours, " << minutes << " minutes, and " << seconds << " seconds.\n";

        tv_hr += hours;
        tv_mn += minutes;
        tv_sec += seconds;
    }
    double total_tv_time = tv_hr + tv_mn / 60.0 + tv_sec / 3600.0;
    cost += total_tv_time * tv_rate;

    cout<<endl;
    cout<<endl;

    cout << "Total power consumption cost by user "<<id<<" : " << cost << " watts." << endl;
    return cost;
}



// Main function: Entry point of the program
int main() 
{
   
    const string filename = "user_data.csv";

// Function to load user data from a file
     vector<User> users = loadUsers(filename);
     string  password;
    
    
    cout << "Welcome! Please log in or create an account.\n";
    cout << "Enter ID: ";
    cin >> id;

    int userIndex = findUser(users, id);
    
    if (userIndex != -1) {
        // Existing user: Prompt for password
        cout << "Enter Password: ";
        cin >> password;

        if (users[userIndex].password == password) {
            cout << "Login successful!\n";
             n_fan=users[userIndex].values[0];
            n_light=users[userIndex].values[1];
            n_tv=users[userIndex].values[2];
            n_geyser=users[userIndex].values[3];
            n_ac=users[userIndex].values[4];
            n_fridge=users[userIndex].values[5];
  
        string filenametoload=id+".csv";

// Function to load device states from a CSV file
          loadDeviceStates(filenametoload, n_fan, n_light, n_tv, n_geyser, n_ac, n_fridge,
                     fan_arr, light_arr, tv_arr, geyser_arr, ac_arr, fridge_arr);
          
            cout << "\n";
            // Proceed with main functionality
        } else {
            cout << "Incorrect password. Access denied.\n";
            exit(-1);
        }
    } else {
        // New user: Create an account
        cout << "\nID not found. Create a new account.......\n";
        User newUser;
        newUser.id = id;

        cout << "Set Password: ";
        cin >> newUser.password;

         cout<<"enter the new component values please to your account ........\n";
         cout<<"Enter the number of fans:"<<endl;
         cin>>n_fan;                                      // Taking number of Fans input
         cout<<"Enter the number of lights:"<<endl;
         cin>>n_light;                                    // Taking number of Ligths input
         cout<<"Enter the number of tvs:"<<endl;
         cin>>n_tv;                                       // Taking number of Tv's input
         cout<<"Enter the number of geysers:"<<endl;
         cin>>n_geyser;                                   // Taking number of Geysers input
         cout<<"Enter the number of ac's:"<<endl; 
         cin>>n_ac;                                       // Taking number of Ac's input
         cout<<"Enter the number of fridges:"<<endl;
         cin>>n_fridge; 

        newUser.values[0]=n_fan;
        newUser.values[1]=n_light;
        newUser.values[2]=n_tv;
        newUser.values[3]=n_geyser;
        newUser.values[4]=n_ac;
        newUser.values[5]=n_fridge;

        users.push_back(newUser);
        saveUsers(users, filename);
        cout << "Account created successfully!\n";

        ofstream filename(id+".csv");

    for (size_t i = 0; i < n_fan; i++)
    {
        string comp= "fan";
        string filenametouse=comp+ to_string(i);
        comp=id+comp+ to_string(i) + ".csv";

        ofstream filename(comp);
    }
      for (size_t i = 0; i < n_light; i++)
    {
        string comp= "light";
        string filenametouse=comp+ to_string(i+1);
        comp=id+comp+ to_string(i) + ".csv";

        ofstream filename(comp);
    }
      for (size_t i = 0; i < n_tv; i++)
    {
        string comp= "tv";
        string filenametouse=comp+ to_string(i+1);
        comp=id+comp+ to_string(i) + ".csv";

        ofstream filename(comp);
    }
  for (size_t i = 0; i < n_ac; i++)
    {
        string comp= "ac";
        string filenametouse=comp+ to_string(i+1);
        comp=id+comp+ to_string(i) + ".csv";

        ofstream filename(comp);
    }

      for (size_t i = 0; i < n_fridge; i++)
    {
        string comp= "fridge";
        string filenametouse=comp+ to_string(i+1);
        comp=id+comp+ to_string(i) + ".csv";

        ofstream filename(comp);
    }

  for (size_t i = 0; i < n_geyser; i++)
    {
        string comp= "geyser";
        string filenametouse=comp+ to_string(i+1);
        comp=id+comp+ to_string(i) + ".csv";

        ofstream filename(comp);
    }
    int v;
    cout<<"Can you please enter 1 if you are able to assist some time for  initializing the input values ? If not, I will go ahead and initialize them to their default values. Thank you!"<<endl;
    cout<<endl<<"1- if you can spare time \n 2- intialze to default values  : ";
    cin>>v;

   if(v==1) 
    {for (int i=0;i<n_light;i++)
    assign_light(&light_arr[i],i);                     // Light assignments
                                                   
    for (int i=0;i<n_fan;i++)
    assign_fan(&fan_arr[i],i);                         // Fan assignments
    
    for(int i=0;i<n_tv;i++)
    assign_tv(&tv_arr[i],i);                           // TV assignments
    
    for (int i=0;i<n_ac;i++)
    assign_ac(&ac_arr[i],i);                           // AC assignments

    for (int i=0;i<n_geyser;i++)
    assign_geyser(&geyser_arr[i],i);                   // Geyser assignments
    
    for (int i=0;i<n_fridge;i++)
    assign_fridge(&fridge_arr[i],i);}                   // Fridge assignments
   
    }

    

   

 cout<<"*************************************************************************************************************************************************************************************";
    int option;

 
    cout<<"\nNow you are ready to use the smart home automation model.........-\n";


    while (true) 
    {
        displayMenu();
        cin >> option;

        if (option == 0) break;
        int deviceChoice;

        if(option<7 && option>0)
        {
             cout << "Select a device:\n";
        cout << "1. Fan\n2. Light\n3. AC\n4. Fridge\n5. Geyser\n6. Tv\n";
        cin >> deviceChoice;


                 if (deviceChoice == 1) 
                 {
                    cout<<"enter the index of fan to be updated :  ";
                    cin>>fan_x;
                    while (n_fan!=0)
                    {
                        if(fan_x>=0 && fan_x<n_fan)
                        break;
                        else
                        {
                            cout<<"enter valid index : ";
                            cin>>fan_x;
                        }
                    }
                    
                    }
            else if (deviceChoice == 2) 
            {
                cout<<"enter the index of light to be updated :  ";
                cin>>light_x;
                while (n_light!=0)
                    {
                        if(light_x>=0 && light_x<n_light)
                        break;
                        else
                        {
                            cout<<"enter valid index : ";
                            cin>>light_x;
                        }
                    }}
            else if (deviceChoice == 3) 
            {
                cout<<"enter the index of AC to be updated :  ";
                cin>>ac_x;
                while (n_ac!=0)
                    {
                        if(ac_x>=0 && ac_x<n_ac)
                        break;
                        else
                        {
                            cout<<"enter valid index : ";
                            cin>>ac_x;
                        }
                    }}
            else if (deviceChoice == 4) 
            {
                cout<<"enter the index of Fridge to be updated :  ";
                cin>>fridge_x;
                while (n_fridge!=0)
                    {
                        if(fridge_x>=0 && fridge_x<n_fridge)
                        break;
                        else
                        {
                            cout<<"enter valid index : ";
                            cin>>fridge_x;
                        }
                    }}
            else if (deviceChoice == 5)  
            {
                cout<<"enter the index of Geyser to be updated :  ";
                cin>>geyser_x;
                while (n_geyser!=0)
                    {
                        if(geyser_x>=0 && geyser_x<n_geyser)
                        break;
                        else
                        {
                            cout<<"enter valid index : ";
                            cin>>geyser_x;
                        }
                    }}
            else if (deviceChoice == 6)  
            {
                cout<<"enter the index of TV to be updated :  ";
                cin>>tv_x;
                while (n_tv!=0)
                    {
                        if(tv_x>=0 && tv_x<n_tv)
                        break;
                        else
                        {
                            cout<<"enter valid index : ";
                            cin>>tv_x;
                        }
                    }};

        }

        if (option == 1 ) 
        {
            if (deviceChoice == 1){ 
                string filename = id+"fan" + to_string(fan_x)+".csv";
                fan_arr[fan_x].ON(filename);
                }
            else if (deviceChoice == 2) {
                string filename = id+"light" + to_string(light_x)+".csv";
                light_arr[light_x].ON(filename);
                }
            else if (deviceChoice == 3) {
                string filename = id+"ac" + to_string(ac_x)+".csv";
                ac_arr[ac_x].ON(filename);
                }
            else if (deviceChoice == 4) {
                string filename = id+"fridge" + to_string(fridge_x)+".csv";
                fridge_arr[fridge_x].ON(filename);
                }
            else if (deviceChoice == 5) {
                string filename = id+"geyser" + to_string(geyser_x)+".csv";
                geyser_arr[geyser_x].ON(filename);
                }
            else if (deviceChoice == 6) {
                string filename = id+"tv" + to_string(tv_x)+".csv";
                tv_arr[tv_x].ON(filename);
                }
        }
         else if (option == 2 ) 
         {
           if (deviceChoice == 1){ 
                string filename = id+"fan" + to_string(fan_x)+".csv";
                fan_arr[fan_x].OFF(filename);
                }
            else if (deviceChoice == 2) {
                string filename = id+"light" + to_string(light_x)+".csv";
                light_arr[light_x].OFF(filename);
                }
            else if (deviceChoice == 3) {
                string filename = id+"ac" + to_string(ac_x)+".csv";
                ac_arr[ac_x].OFF(filename);
                }
            else if (deviceChoice == 4) {
                string filename = id+"fridge" + to_string(fridge_x)+".csv";
                fridge_arr[fridge_x].OFF(filename);
                }
            else if (deviceChoice == 5) {
                string filename = id+"geyser" + to_string(geyser_x)+".csv";
                geyser_arr[geyser_x].OFF(filename);
                }
            else if (deviceChoice == 6) {
                string filename = id+"tv" + to_string(tv_x)+".csv";
                tv_arr[tv_x].OFF(filename);
                };}
         else if (option == 3) 
         {
            adjustSettings(fan_arr, light_arr, ac_arr, fridge_arr, geyser_arr,tv_arr,deviceChoice);
        } else if (option == 4) 
        {
            if (deviceChoice == 1) setTimer();
            else if (deviceChoice == 2) setTimer();
            else if (deviceChoice == 3) setTimer();
            else if (deviceChoice == 4) setTimer();
            else if (deviceChoice == 5) setTimer();
            else if (deviceChoice == 6) setTimer();
            
        } else if (option == 5) 
        {
            if (deviceChoice == 1) fan_arr[fan_x].getstatus();
            else if (deviceChoice == 2) light_arr[light_x].getstatus();
            else if (deviceChoice == 3) ac_arr[ac_x].getstatus();
            else if (deviceChoice == 4) fridge_arr[fridge_x].getstatus();
            else if (deviceChoice == 5) geyser_arr[geyser_x].getstatus();
            else if (deviceChoice == 6) tv_arr[tv_x].getstatus();
            
        } 
        else if (option == 6) 
        {
            if (deviceChoice == 1) cout<<fan_arr[fan_x]<<endl;
            else if (deviceChoice == 2) cout<<light_arr[light_x]<<endl;
            else if (deviceChoice == 3) cout<<ac_arr[ac_x]<<endl;
            else if (deviceChoice == 4) cout<<fridge_arr[fridge_x]<<endl;
            else if (deviceChoice == 5) cout<<geyser_arr[geyser_x]<<endl;
            else if (deviceChoice == 6) cout<<tv_arr[tv_x]<<endl;
            
        } 

        else if(option==7)
        {
            powerbill();
        }
        else {
            cout << "Invalid option.\n";
        }
         cout<<"*************************************************************************************************************************************************************************************";
    }

// Function to save device states to a CSV file
    saveDeviceStates(id+".csv", fan_arr, n_fan, light_arr, n_light, tv_arr, n_tv, geyser_arr, n_geyser, ac_arr, n_ac, fridge_arr, n_fridge);
    cout << "Logging out user..."<<endl;
    cout << "Exiting Smart Home Controller.\n";
    return 0;

}  
