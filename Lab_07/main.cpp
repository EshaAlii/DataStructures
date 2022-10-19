#include<iostream>
#include<string>
#include <iomanip>
#include "Time.h"

using namespace std;

// getTimeFromUser function
bool getTimeFromUser(Time& time, string check){

    // Intiailize string variables for struct
    string hours;
    string minutes;
    string seconds;

    // Initialize the variable to find the colons and the length of our check string
    int C1;
    int C2;
    int length;
    
    // Get input from the user
    getline(cin,check);

    // Identify where the first colon is and save location in a new int
    C1 = check.find(":");
    
    // Identify where the second colon is and saves location in a new int
    C2 = check.find_last_of(":");

    // Finds the length of the string
    length = check.size();

    // Find the strings of hours, mins, and secs, in the location they would be
    hours = check.substr(0, C1);
    minutes = check.substr(C1+1, length - C2 - 1);
    seconds = check.substr(C2+1, length);

    // Convert the previously found strings to ints
    time.changeHours(atoi(hours.c_str()));
    time.changeMinutes(atoi(minutes.c_str()));
    time.changeSeconds(atoi(seconds.c_str()));
    
    // If the following conditions are met + colon isn't in the input
    if ((time.getHours() >= 0 && time.getHours() <= 23) && (time.getMinutes() >= 0 && time.getMinutes() <= 59) && (time.getSeconds() >= 0 && time.getSeconds() <= 59) && (C1 != -1) && (C2 != -1)){
        return true;
    }
    
    return false;
}

// print24Hour function
void print24Hour(Time& time){
    // Fills the statments with 0 if it isn't accounted for
    cout << setfill('0') << setw(2);
    cout << time.getHours() << ":";
    cout << setfill('0') << setw(2);
    cout << time.getMinutes() << ":";
    cout << setfill('0') << setw(2);
    cout << time.getSeconds();
}

// main function
int main(){
    
    // Initialize variables
    Time startTime;
    Time endTime;
    string check;


    // Ask for start time
    cout << "Enter the start time for the lecture (format is HH:MM:SS): " << endl;

    // If it isn't we say its invalid and end program
    if (!getTimeFromUser(startTime, check)){
        cout << "The start time is invalid!" << endl;
        return 0;
    }

    // Ask for the end time
    cout << "Enter the end time for the lecture (format is HH:MM:SS): " << endl;
    
    // If it isn't we say its invalid and end program
    if(!getTimeFromUser(endTime,check)){
        cout << "The end time is invalid!" << endl;
        return 0;
    }
    
    // Otherwise we print it out
    cout << "The lecture starts at" << " ";
    print24Hour(startTime);
    cout << " and ends at ";
    print24Hour(endTime);
    cout << endl;
    
    // Ends program
    return 0;
}