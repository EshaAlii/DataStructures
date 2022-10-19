#include <iostream>
#include "Stack_char.h"

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
void Stack::push(char value){
    insertAtBack(value);
}

// removes back element
char Stack::pop(){

    // returns last value in stack
    char remember = last->val;
    removeFromBack();
    return remember;
}

// returns reference to top (last) stack element
char& Stack::top(){

    // returns reference to last value
    return last->val;
}