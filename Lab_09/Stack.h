#ifndef STACK_H 
#define STACK_H

#include "LinkedList.h"

using namespace std;

// Stack DECLARATION

class Stack: public LinkedList{

    public:
        Stack(); // Constructor
        ~Stack(); // Destructor
        void push(int value); // inserts new element at front
        int pop(); // removes first element
        int& top(); // returns reference to top (last) stack element
};

#endif
