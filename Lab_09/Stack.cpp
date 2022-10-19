#include <iostream>
#include "Stack.h"

using namespace std;

// Stack DEFINITION

// Constructor
Stack::Stack(){
 // Empty
}

// Destructor
Stack::~Stack(){
    // Empty
}

// Inserts new element at back
void Stack::push(int value){
    insertAtBack(value);
}

// removes back element
int Stack::pop(){

    // returns last value in stack
    int remember = last->val;
    removeFromBack();
    return remember;
}

// returns reference to top (last) stack element
int& Stack::top(){

    // returns reference to last value
    return last->val;
}