#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// Time Struct
struct Time{

    // Initialize the variables within the struct
    int hours;
    int minutes;
    int seconds;

    // Default constructor
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

struct Course{

    // Initialize the variables within the struct
    string name;
    int credits;
    bool majorRequirement;
    double avgGrade;
    string days;
    struct Time startTime;
    struct Time endTime;

    // Default constructor
    Course(){
        name = " ";
        credits = 0;
        majorRequirement = false;
        avgGrade = 0;
        days = " ";
    }


    // Empty Destructor
    ~Course(){
        // Empty
    }
    
};

// getTimeFromUser function
void getTimeFromUser(Time& time, string check){

    // Intiailize string variables for struct
    string hours;
    string minutes;
    string seconds;

    // Initialize the variable to find the colons and the length of our check string
    int C1;
    int C2;
    int length;
    
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
}

// print24Hour function
void print24Hour(Time& time){

    // If hours is less than 12 we output as is
    if (time.hours <= 12){
        // Fills the statments with 0 if it isn't accounted for
        cout << setfill('0') << setw(2);
        cout << time.hours << ":";
        cout << setfill('0') << setw(2);
        cout << time.minutes << ":";
        cout << setfill('0') << setw(2);
        cout << time.seconds;
    }

    // Otherwise we adjust it to 12 hour time
    else if(time.hours > 12){
        // Fills the statments with 0 if it isn't accounted for
        cout << setfill('0') << setw(2);
        cout << time.hours-12 << ":";
        cout << setfill('0') << setw(2);
        cout << time.minutes << ":";
        cout << setfill('0') << setw(2);
        cout << time.seconds;
    }
}

// Choice function that determines AM vs PM
void choice(Time& time){
    
    // If the hours is less than 12, we assume AM
    if (time.hours < 12){
        cout << " " << "AM";
    }
    else{
        cout <<  " " << "PM";
    }

}

// main function

int main()
{
    // This string will be used as a buffer for every single thing that is not a integer
    string str;

    // This will be the main course that will be storing data
    Course course;

    // This will just be counting the course we are currently on
    int count = 1;
    
    // Beginning of Student Schedule
    cout << "-------------------" << endl;
    cout << "SCHEDULE OF STUDENT" << endl;
    cout << "-------------------" << endl;

    // Read input file
    ifstream input;
    
    // Open "in.txt"
    input.open("in.txt");

    // read stuff from "in.txt"
    getline(input, str);

    // Create a variable that reads line 1 and checks how many times to repeat the for loop  
    int repeats =  atoi(str.c_str());

    // For loop that goes from zero to however many time it repeats
    for (int i = 0; i < (repeats * 7) ; i++){  

        // Reads the courses
        // want this to run after end time runs
        if (i != 0 && (i+1) % 7 == 0){
            cout << "COURSE " << count << ": " << course.name << endl;
            count++;
        }  

        // Gets course name in first line
        if (i % 7 == 0){
            getline(input, course.name);
        }

        // Gets course credits in second line
        else if (i % 7 == 1){
            getline(input, str);
            course.credits = atoi(str.c_str());
        }

        // Gets course major reqs in third line
        else if (i % 7 == 2){
            getline(input, str);
            course.majorRequirement = atoi(str.c_str());
        }

        // Gets course average grade in fourth line
        else if (i % 7 == 3){
            getline(input, str);
            course.avgGrade = atof(str.c_str());
        }

        // Gets course days in fifth line
        else if (i % 7 == 4){
            getline(input, course.days);
        }

        // Gets course start time in sixth line 
        else if (i % 7 == 5){
            getline(input, str);
            getTimeFromUser(course.startTime, str);
        }

        // Gets course end time in final line
        else{
            getline(input, str);

            getTimeFromUser(course.endTime, str);
        }

        // We then return our statements
        // want this to run after end time runs
        if (i != 0 && (i+1) % 7 == 0){
            cout << "Note: ";
            if (course.majorRequirement)
            {
                cout << "this course is a major requirement!" << endl;
            }
            else
            {
                cout << "this course is not a major requirement..." << endl;
            }
            cout << "Number of Credits: " << course.credits << endl;
            cout << "Days of Lecture: " << course.days << endl;
            cout << "Lecture Time: ";
            print24Hour(course.startTime);
            choice(course.startTime);
            cout << " - ";
            print24Hour(course.endTime);
            choice(course.endTime);
            cout << endl;
            cout << "Stat: on average students get " << course.avgGrade << "% in this course." << endl;
            cout << "-------------------" << endl;
        }
    }

    
    // End Program
    return 0;
}