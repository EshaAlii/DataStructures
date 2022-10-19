#ifndef QUEUECHAR_H
#define QUEUECHAR_H

#include "LinkedList_char.h"

using namespace std;

// Queue DECLARATION

class Queue: public LinkedList{

    public:
        Queue(); // Constructor
        ~Queue(); // Destructor
        void enqueue(char value); // Inserts new element at front
        char dequeue(); // Removes first element
        char& front(); // Returns reference to first element
};

#endif