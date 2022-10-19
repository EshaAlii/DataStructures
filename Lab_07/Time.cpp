#include "Time.h"

// CLASS DEFINITION
    
// Default Constructor
Time::Time(){
    hours = 0;
    minutes = 0;
    seconds = 0;
}

// Extra constructor
Time::Time(int h, int m, int s){
    hours = h;
    minutes = m;
    seconds = s;
}

// Empty Destructor
Time::~Time(){
    // Does nothing
}

// Accessor functions - gets variable from protected class and shows it to user
int Time::getHours(){
    return hours;
}

int Time::getMinutes(){
    return minutes;
}

int Time::getSeconds(){
    return seconds;
}

// Mutator functions - manipulates whatever is in private
void Time::changeHours(int h){
    hours = h;
}

void Time::changeMinutes(int m){
    minutes = m;
}

void Time::changeSeconds(int s){
    seconds = s;
}

