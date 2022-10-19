#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

using namespace std;

// Queue DECLARATION

class Queue: public LinkedList{

    public:
        Queue(); // Constructor
        ~Queue(); // Destructor
        void enqueue(int value); // Inserts new element at front
        int dequeue(); // Removes first element
        int& front(); // Returns reference to first element
};

#endif