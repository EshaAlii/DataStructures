#ifndef STACK_H 
#define STACK_H

#include "LinkedList.h"

using namespace std;

// Stack DECLARATION
template <class T>
class Stack: public LinkedList<T>{

    public:
        Stack(); // Constructor
        ~Stack(); // Destructor
        void push(T value); // inserts new element at front
        T pop(); // removes first element
        T& top(); // returns reference to top (last) stack element
};

// Stack DEFINITION

// Constructor
template <class T>
Stack<T>::Stack(){
 // Empty
}

// Destructor
template <class T>
Stack<T>::~Stack(){
    // Empty
}

// Inserts new element at back
template <class T>
void Stack<T>::push(T value){
    LinkedList<T>::insertAtFront(value);
}

// removes back element
template <class T>
T Stack<T>::pop(){

    // returns last value in stack
    T remember = LinkedList<T>::first->val;
    LinkedList<T>::removeFromFront();
    return remember;
}

// returns reference to top (last) stack element
template <class T>
T& Stack<T>::top(){
    // returns reference to last value
    return LinkedList<T>::first->val;
}

#endif