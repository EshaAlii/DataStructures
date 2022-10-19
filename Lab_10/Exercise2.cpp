#include <iostream>
#include "Queue_char.h"

using namespace std;

int main(){

    // Initialize a Queue
    Queue q;

    // Spacing
    cout << "-----------------------------------------------------------------" << endl;

    // Print out the top sections of the table
    cout << "Function Call" << "\t\t"  << "Output" << "\t\t" << "Front Queue Rear" << endl;
    
    // Spacing
    cout << "-----------------------------------------------------------------" << endl;

    // Testing our Catch
    try{
       q.dequeue();
    }
    catch(int error){
        cout << "dequeue()" << "\t\t" << "exception" << endl;
    }

    // Insert the letter D into the Queue
    q.enqueue('D');
    cout << "enqueue(D)" << "\t\t" << " " << "\t\t";
    q.print();
    cout << endl;

    // Insert the letter A into the Queue
    q.enqueue('A');
    cout << "enqueue(A)" << "\t\t" << " " << "\t\t";
    q.print();
    cout << endl;

    // Removes first letter from Queue
    try{
       cout << "dequeue()" << "\t\t" << q.dequeue() << "\t\t";
       q.print();
       cout << endl;
    }
    catch(int error){
        cout << "dequeue()" << "\t\t" << "exception" << endl;
    }

    // Check the size of the Queue
    cout << "size()" << "\t\t\t" << q.size() << "\t\t";
    q.print();
    cout << endl;

    // Insert the letter D into the Queue
    q.enqueue('D');
    cout << "enqueue(D)" << "\t\t" << " " << "\t\t";
    q.print();
    cout << endl;

    // Check if Queue is Empty
    if (q.isEmpty()){
        cout << "isEmpty()" << "\t\t" << "true" << endl;
    }
    else{
        cout << "isEmpty()" << "\t\t" << "false";
        cout << "\t\t";
        q.print();
        cout << endl;
    }

    // Return front of the Queue
    try{
       cout << "front()" << "\t\t\t" << q.front() << "\t\t";
       q.print();
       cout << endl;
    }
    catch(int error){
        cout << "front()" << "\t\t\t" << "exception" << endl;
    }

    // Insert the letter T into the Queue
    q.enqueue('T');
    cout << "enqueue(T)" << "\t\t" << " " << "\t\t";
    q.print();
    cout << endl;

    // Return front of the Queue
    try{
       cout << "front()" << "\t\t\t" << q.front() << "\t\t";
       q.print();
       cout << endl;
    }
    catch(int error){
        cout << "front()" << "\t\t\t" << "exception" << endl;
    }

    // Spacing
    cout << "-----------------------------------------------------------------" << endl;

    // End program
    return 0;
}