#ifndef STACKCHAR_H 
#define STACKCHAR_H

#include "LinkedList_char.h"

using namespace std;

// Stack DECLARATION

class Stack: public LinkedList{

    public:
        Stack(); // Constructor
        ~Stack(); // Destructor
        void push(char value); // inserts new element at front
        char pop(); // removes first element
        char& top(); // returns reference to top (last) stack element
};

#endif
