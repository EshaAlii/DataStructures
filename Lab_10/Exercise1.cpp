#include <iostream>
#include "Queue.h"

using namespace std;

int main(){

    // Initialize a Queue
    Queue  q;

    // Place numbers 1-10 into Queue
    for (int i = 1; i < 11; i++){
        q.enqueue(i);
    }

    // Testing insert at back function
    q.insertAtBack(30);

    // Output top of the Queue
    try{
       cout << "The top of the queue is: " << q.front() << endl;
    }
    catch(int error){
        cout << "Call to front() generated an exception, because the queue is empty!" << endl;    
    }

    // Output size of the Queue
    cout << "The size of the queue is: " << q.size() << endl;

    // Checks if the Queue is Empty
    if (q.isEmpty()){
        cout << "The queue is empty!" << endl;
    }
    else{
        cout << "The queue is NOT empty!" << endl;
    }

    // Print out the Queue
    cout << "The queue is: "; 
    q.print(); 
    cout << endl;

    // Removes + Shows first number
    try{
        cout << "Removing the top of the queue: " << q.dequeue() << endl;
    }
    catch(int error){
        cout << "Call to dequeue() generated an exception, because the queue is empty" << endl;    
    }

    // Print out the Queue
    cout << "The queue is: "; 
    q.print(); 
    cout << endl;

    // Clear the Queue
    q.clear();

    // Checks if the Queue is Empty
    if (q.isEmpty()){
        cout << "The queue is empty!" << endl;
    }
    else{
        cout << "The queue is NOT empty!" << endl;
    }

    // Place numbers by 2 into Queue
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(6);
    q.enqueue(8);

    // Output top of the Queue
    try{
        cout << "The top of the queue is: " << q.front() << endl;
    }
    catch(int error){
        cout << "Call to front() generated an exception, because the queue is empty!" << endl;    
    }

    // Output size of the Queue
    cout << "The size of the queue is: " << q.size() << endl;

    // Print out the Queue
    cout << "The queue is: "; 
    q.print();
    cout << endl;

    // Clear the Queue
    q.clear();

    // Dequeue an empty Queue to see if catch works
    try{
       q.dequeue();
    }
    catch(int error){
        cout << "Call to dequeue() generated an exception, because the queue is empty" << endl;    
    }

    // Return front of empty Queue to see if catch works
    try{
        q.front();
    }
    catch(int error){
        cout << "Call to front() generated an exception, because the queue is empty!" << endl;    
    }

    // End Program
    return 0;
}