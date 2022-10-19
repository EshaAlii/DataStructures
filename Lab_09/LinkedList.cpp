#include <iostream>
#include "LinkedList.h"

using namespace std;

//Linked List DEFINITION

// Constructor
LinkedList::LinkedList(){
    // Define both first and last nodes as empty
    first = NULL;
    last = NULL;
}

// Destructor
LinkedList::~LinkedList(){
    // Node to trasverse the list
    Node *temp = first;
    
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
void LinkedList::insertAtBack(int valueToInsert){

   // Creating a new node to add
    Node *temp = new Node;

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
        Node *ptr = first;

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
bool LinkedList::removeFromBack(){

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
       Node *temp = first;

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
void LinkedList::print(){
    // Create a node pointer that goes to first node
    Node *temp = first;

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
bool LinkedList::isEmpty(){
    // If first node is NULL, list is empty, otherwise its not
    if (first == NULL){
        return true;
    }
    else{
        return false;
    }
}

// Check size of list
int LinkedList::size(){

    // Counts the nodes
    int count = 0;
    // Node pointer to travel the list
    Node *temp = first;

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
void LinkedList::clear(){
    // Node to trasverse the list
    Node *temp = first;
    
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
void LinkedList::insertAtFront(int valueToInsert){
    // Create a new node pointer to a new node
    Node *temp = new Node;

    // Value at node is equal to user input
    temp->val = valueToInsert;

    // Value at first is stored in next node over  
    temp->next = first;

    // Set the first node equal to the new node pointer
    first = temp;

    delete temp;
}

// Remove from Front
bool LinkedList::removeFromFront(){
    // If front is empty its false
    if (first == NULL){
        return false;
    }
    else{
        // If not, create a new pointer equal to first
        Node *temp = first;

        // Set the next node equal to first
        first = temp->next;

        // Delete temp
        delete temp;
        
        return true;
    }
}