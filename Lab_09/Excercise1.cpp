#include <iostream>
#include "Stack.h"

using namespace std;

int main(){

    // Initialize a Stack
    Stack h;

    // Place numbers 1-10 into Stack
    for (int i = 1; i < 11; i++){
        h.push(i);
    }

    // Testing insert at back function
    h.insertAtBack(30);

    // Output top of the Stack
    cout << "The top of the stack is: " << h.top() << endl;

    // Output size of the Stack
    cout << "The size of the stack is: " << h.size() << endl;

    // Checks if the Stack is Empty
    if (h.isEmpty()){
        cout << "The stack is empty!" << endl;
    }
    else{
        cout << "The stack is NOT empty!" << endl;
    }

    // Print out the Stack
    cout << "The stack is: "; 
    h.print(); 
    cout << endl;

    // Removes + Shows last number
    cout << "Removing the top of the stack: " << h.pop() << endl;

    // Print out the Stack
    cout << "The stack is: "; 
    h.print(); 
    cout << endl;

    // Clear the stack
    h.clear();

    // Checks if the Stack is Empty
    if (h.isEmpty()){
        cout << "The stack is empty!" << endl;
    }
    else{
        cout << "The stack is NOT empty!" << endl;
    }

    // Place numbers by 2, at the top of the stack
    h.push(2);
    h.push(4);
    h.push(6);
    h.push(8);

    // Output top of the Stack
    cout << "The top of the stack is: " << h.top() << endl;

    // Output size of the Stack
    cout << "The size of the stack is: " << h.size() << endl;

    // Print out the Stack
    cout << "The stack is: "; 
    h.print(); 
    cout << endl;

    // Clear the stack
    h.clear();

    return 0;
}