#include <iostream>
#include "Queue.h"

using namespace std;

// Queue DEFINITION

// Constructor
Queue::Queue(){
 // Empty
}

// Destructor
Queue::~Queue(){
    // Empty
}

// Inserts new element at back
void Queue::enqueue(int value){
    insertAtBack(value);
}

// Removes first element
int Queue::dequeue(){

    // Throwing an exception
    if (isEmpty()){
       throw (10);
    }

    // Returns first value in Queue + Removes from front
    int remember = first->val;
    removeFromFront();
    return remember;
}

// Returns reference to first element
int& Queue::front(){

    // Throwing an exception
    if (isEmpty()){
        throw (2);
    }

    // Returns reference to first value
    return first->val;
}
