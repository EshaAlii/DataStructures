#ifndef LINKEDLIST_H 
#define LINKEDLIST_H
#include<iostream>

using namespace std; 

//Linked List DECLARATION

// Representation of an element in the linked list
template <class T>
struct Node{
    T val; // Value of the node
    Node *next; // Pointer to the next node
};

template <class T>
class LinkedList{

    // Public Functions/Variables
    public:
        LinkedList(); // Constructor
        ~LinkedList(); // Destructor
        void insertAtBack(T valueToInsert);
        bool removeFromBack();
        void print();
        bool isEmpty();
        int size();
        void clear();
        void insertAtFront(T valueToInsert);
        bool removeFromFront();
    // Private Functions/Variables
    protected:
        Node<T> *first; // Pointer pointing to the begining of the list
        Node<T> *last; // Pointer pointing to the end of the list
};


//Linked List DEFINITION

// Constructor
template <class T>
LinkedList<T>::LinkedList(){
    // Define both first and last nodes as empty
    first = NULL;
    last = NULL;
}

// Destructor
template <class T>
LinkedList<T>::~LinkedList(){
    // Node to trasverse the list
    Node<T> *temp = first;
    
    // Traverse the list
    while (temp != NULL){

        // Temp is equal to the node after first one
        temp = first->next;

        // Delete the current first node
        delete first;

        // Set first as temp 
        first = temp;
    }
}

// Insert at Back
template <class T>
void LinkedList<T>::insertAtBack(T valueToInsert){

   // Creating a new node to add
    Node<T> *temp = new Node<T>;

    // Filling in the temporary node with user input data
    temp->val = valueToInsert;
    temp->next = NULL;

    // If list is empty we are essentially creating a new node for the list
    if (first == NULL){
        // set both first and last pointer equal to same value
        first = temp;
        last = temp;
    }
    else{
        // Otherwise if list is not empty...

        // Node pointer to point to first node
        Node<T> *ptr = first;

        // We traverse through the nodes...
        while(ptr->next != NULL){
            // Until we reach one that is NULL
            ptr = ptr->next;
        }

        // We then define new last as a new node
        ptr->next = temp;
        last = temp;
    }
}

// Remove from Back
template <class T>
bool LinkedList<T>::removeFromBack(){

    // If the first node is NULL automatically return false cause nothing in list
    if (first == NULL){
        return false;
    }

    // If the first node isn't null but the next one is, (aka just one thing in linked list)...
    else if (first->next == NULL){
        // We say that the first is NULL
        first = NULL;
    }
   else{
       // Otherwise...

       // Create a node pointer
       Node<T> *temp = first;

       // Traverse through the list...
       while (temp->next->next != NULL){
           // Until it reaches to the second last element before NULL node
           temp = temp->next;
       }

        // We then say the last element is NULL
        temp->next = NULL;
   }
   // Return true
   return true;
}

// Print List
template <class T>
void LinkedList<T>::print(){
    // Create a node pointer that goes to first node
    Node<T> *temp = first;

    // While trasversing the Linked List...
    while(temp != NULL){
        // Return the value of the current position in list
        std::cout << temp->val;

        // If node isn't last one
        if (temp->next != NULL){
            // Properly print out commas
            std::cout << " ,";
        }

        // Traverse to next node
        temp = temp->next;
    }

}

// Check if list is empty
template <class T>
bool LinkedList<T>::isEmpty(){
    // If first node is NULL, list is empty, otherwise its not
    if (first == NULL){
        return true;
    }
    else{
        return false;
    }
}

// Check size of list
template <class T>
int LinkedList<T>::size(){

    // Counts the nodes
    int count = 0;
    // Node pointer to travel the list
    Node<T> *temp = first;

    // If list is empty we return 0
    if (temp == NULL){
        return count;
    }
    else{
        // If list is not empty and it isn't at the last node
        while (temp != NULL){
            // We traverse list and increase count by 1
            temp = temp->next;
            count++;
        }
        return count;
    }
}

// Clear the list
template <class T>
void LinkedList<T>::clear(){
    // Node to trasverse the list
    Node<T> *temp = first;
    
    // While we traverse the list...
    while (temp != NULL){
        // Temp is equal to the node after first one
        temp = first->next;
        // Delete the current first node
        delete first;
        // Set first as temp 
        first = temp;
    }
    
}

// Insert at Front
template <class T>
void LinkedList<T>::insertAtFront(T valueToInsert){
    // Create a new node pointer to a new node
    Node<T> *temp = new Node<T>;

    // Value at node is equal to user input
    temp->val = valueToInsert;

    // Value at first is stored in next node over  
    temp->next = first;

    // Set the first node equal to the new node pointer
    first = temp;

    //delete temp;
}

// Remove from Front
template <class T>
bool LinkedList<T>::removeFromFront(){
    // If front is empty its false
    if (first == NULL){
        return false;
    }
    else{
        // If not, create a new pointer equal to first
        Node<T> *temp = first;

        // Set the next node equal to first
        first = temp->next;

        // Delete temp
        delete temp;
        
        return true;
    }
}

#endif