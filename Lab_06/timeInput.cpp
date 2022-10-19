#include<iostream>
#include<string>
#include <iomanip>

using namespace std;

// Time Struct
struct Time{

    // Initialize the variables within the struct
    int hours;
    int minutes;
    int seconds;

    // Default Constructor
    Time(){
        hours = 0;
        minutes = 0;
        seconds = 0;
    }


    // Empty Destructor
    ~Time(){
        // Empty
    }
};

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
    time.hours = atoi(hours.c_str());
    time.minutes = atoi(minutes.c_str());
    time.seconds = atoi(seconds.c_str());
    
    // if the following conditions are met + colon isn't in the input
    if ((time.hours >= 0 && time.hours <= 23) && (time.minutes >= 0 && time.minutes <= 59) && (time.seconds >= 0 && time.seconds <= 59) && (C1 != -1) && (C2 != -1)){
        return true;
    }
    
    return false;
}

// print24Hour function
void print24Hour(Time& time){
    // Fills the statments with 0 if it isn't accounted for
    cout << setfill('0') << setw(2);
    cout << time.hours << ":";
    cout << setfill('0') << setw(2);
    cout << time.minutes << ":";
    cout << setfill('0') << setw(2);
    cout << time.seconds;
}

// main function
int main(){
    
    // Initialize variables
    Time startTime;
    Time endTime;
    string check;
    bool choice;


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