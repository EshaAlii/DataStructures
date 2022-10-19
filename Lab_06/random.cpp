#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

struct Time{

    int hours;
    int minutes;
    int seconds;

    //this constructor has hours minutes and seconds
    Time(){
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

// this destructor is empty
    ~Time(){
      
    }
};
struct Course{//make course a struct
// have variables which will be string, int, bool and out time struct
    string name;
    int credits;
    bool majorRequirement;
    double avgGrade;
    string days;
    struct Time startTime;
    struct Time endTime;

    // course constructor
    Course(){
        name = " ";
        credits = 0;
        majorRequirement = false;
        avgGrade = 0;
        days = " ";
    }
    // course destructor
    ~Course(){
      
    }
};

// this void function will get the time and check it 
void getTimeFromUser(Time& time, string checknum){

    string hours;
    string minutes;
    string seconds;

    // Iwe make colon 1 and 2 ints and have length and in as well
    int colon1;
    int colon2;
    int length;
    
    // this will check the first colon
    colon1 = checknum.find(":");
    
    // this will check / find the second colon
    colon2 = checknum.find_last_of(":");

    // this will find the size of the length
    length = checknum.size();

   
  // this wil check the strings for hours minutes and seconds
    hours = checknum.substr(0, colon1);
    minutes = checknum.substr(colon1 +1, length - colon2 - 1);
    seconds = checknum.substr(colon2 +1, length);

    // we will use atoi function
    time.hours = atoi(hours.c_str());
    time.minutes = atoi(minutes.c_str());
    time.seconds = atoi(seconds.c_str());
}

// this void function will print out
void print24Hour(Time& time){

    // this if statement will fill in the spaces with 0 if it is less then 12
    if (time.hours <= 12){
       
        cout << setfill('0') << setw(2);
        cout << time.hours << ":";
        cout << setfill('0') << setw(2);
        cout << time.minutes << ":";
        cout << setfill('0') << setw(2);
        cout << time.seconds;
    }

    //this else will check if it is greater then 12
    else if(time.hours > 12){
        
        cout << setfill('0') << setw(2);
        cout << time.hours-12 << ":";
        cout << setfill('0') << setw(2);
        cout << time.minutes << ":";
        cout << setfill('0') << setw(2);
        cout << time.seconds;
    }
}

// this void function will check if it is am then any thing else pm 
void choice(Time& time){
    
    
    if (time.hours < 12){
        cout << " " << "AM";
    }
    else{
        cout <<  " " << "PM";
    }

}


int main()
{
    string word;
    Course course;
    int counter = 1;
  // this will print out phrase
    cout << "-------------------" << endl;
    cout << "SCHEDULE OF STUDENT" << endl;
    cout << "-------------------" << endl;

    // this wil read the file
    ifstream input;
    
    // this will open the file
    input.open("in.txt");

    // this will read the file
    getline(input, word);
 
    int repeats =  atoi(word.c_str());

  // this for loop will go to 1 whic is 0 to repeats times 7 which wil interage through out the for loop
    for (int i = 0; i < (repeats * 7) ; i++){  

        if (i != 0 && (i+1) % 7 == 0){
            cout << "COURSE " << counter << ": " << course.name << endl;
            counter++;
        }  
        if (i % 7 == 0){
            getline(input, course.name);
        }
        else if (i % 7 == 1){
            getline(input, word);
            course.credits = atoi(word.c_str());
        }
        else if (i % 7 == 2){
            getline(input, word);
            course.majorRequirement = atoi(word.c_str());
        }

        else if (i % 7 == 3){
            getline(input, word);
            course.avgGrade = atof(word.c_str());
        }

        else if (i % 7 == 4){
            getline(input, course.days);
        }

        else if (i % 7 == 5){
            getline(input, word);
            getTimeFromUser(course.startTime, word);
        }
        else{
            getline(input, word);

            getTimeFromUser(course.endTime, word);
        }

        if (i != 0 && (i+1) % 7 == 0){
            cout << "Notes: ";
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

    
  
    return 0;
}