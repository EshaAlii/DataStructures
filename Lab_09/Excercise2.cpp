#include <iostream>
#include "Stack_char.h"

using namespace std;

int main(){

    // Declare our Stack
    Stack h;

    // Spacing
    cout << "----------------------------------------" << endl;

    // Print out the top sections of the table
    cout << "Function Call" << "\t"  << "Output" << "\t" << "Stack Contents" << endl;

    cout << "----------------------------------------" << endl;

    // Check if the Stack is empty
    if (h.isEmpty()){
        cout << "isEmpty()" << "\t" << "true" << endl;
    }
    else{
        cout << "isEmpty()" << "\t" << "false";
        cout << "\t";
        h.print();
        cout << endl;
    }

    // Insert the letter A into the Stack
    h.push('A');
    cout << "push(A)" << "\t\t" << " " << "\t";
    h.print();
    cout << endl;

    // Insert the letter Y into the Stack
    h.push('Y');
    cout << "push(Y)" << "\t\t" << " " << "\t";
    h.print();
    cout << endl;

    // Check the size of the Stack
    cout << "size()" << "\t\t" << h.size() << "\t";
    h.print();
    cout << endl;

    // Remove the last letter (top letter) from the Stack
    cout << "pop()" << "\t\t" << h.pop() << "\t";
    h.print();
    cout << endl;

    // Check if the Stack is empty
    if (h.isEmpty()){
        cout << "isEmpty()" << "\t" << "true" << endl;
    }
    else{
        cout << "isEmpty()" << "\t" << "false";
        cout << "\t";
        h.print();
        cout << endl;
    }

    // Insert the letter D into the Stack
    h.push('D');
    cout << "push(D)" << "\t\t" << " " << "\t";
    h.print();
    cout << endl;

    // Check what is the last letter (top letter) on the Stack
    cout << "top()" << "\t\t" << h.top() << "\t";
    h.print();
    cout << endl;

    // Insert the letter T into the Stack
    h.push('T');
    cout << "push(T)" << "\t\t" << " " << "\t";
    h.print();
    cout << endl;

    // Remove the last letter (top letter) from the Stack
    cout << "pop()" << "\t\t" << h.pop() << "\t";
    h.print();
    cout << endl;

    // Spacing
    cout << "----------------------------------------" << endl;

    // End program
    return 0;
}