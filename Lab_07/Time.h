#ifndef TIME_H
#define TIME_H

// CLASS DECLARATION

// Class Time
class Time{

    // Declare private class
    private:

    // Initialize the variables within the class
    int hours;
    int minutes;
    int seconds;

    // Declare the public class
    public:

    // Initialize defualt constructor, constructor, and destructor
    Time();
    Time(int, int, int);
    ~Time();

    // Initialize Accessor Functions -  gets variable from protected class and shows it to user
    int getHours();
    int getMinutes();
    int getSeconds();

    //Intiialize Mutator Functions - manipulates whatever is in private
    void changeHours(int);
    void changeMinutes(int);
    void changeSeconds(int);
};

#endif