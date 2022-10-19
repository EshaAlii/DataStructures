#include <iostream>
#include <string>
#include "HTable.h"

// Default Constructor
HTable::HTable(){
    // Initialzie the table with 23 values 
    max_size = 23;
    dt = new data[max_size];

    // Set numel to 0, state there is nothing in the table
    numel = 0;
    
    // State that unoccupied places of the table have the following values/key
    for(int i = 0; i < max_size; i++){
        dt[i].key = -1;
        dt[i].value = "N/A";
    }

}

// Alternative Constructor
HTable::HTable(int t_size){
    // Initialzie the table with input values as size
    max_size = t_size;
    dt = new data[max_size];

    // Set numel to 0, state there is nothing in the table
    numel = 0;
    
    // State that unoccupied places of the table have the following values/key
    for(int i = 0; i < max_size; i++){
        dt[i].key = -1;
        dt[i].value = "N/A";
    }
}

// Hash function: Runs the value through a hash code
int HTable::hash(int &k){
    // Create a hash code integer that stores the hash code
    int hc = k%max_size;
    
    // Return the hash code
    return hc;
}

// Rehash function: Runs the value through a re-hash code (linear probing)
int HTable::rehash(int &k){
    // Create a re-hash code integer that stores the re-hash code
    int rhc = (k+1)%max_size;

    // Return the re-hash code
    return rhc;
}

// Add function: Adds data structure to the table
int HTable::add(data &d){

    // Create a hash key equal to the hash code of the data key
    int hk = hash(d.key);
    
    // If the table isn't filled...
    while(numel != max_size){

        // If the table key is empty...
        if (dt[hk].key == -1){
            
            // We set the key and values at that spot equal to the new data's key and value
            dt[hk].key = d.key;
            dt[hk].value = d.value;

            // We then increment numel (to tell the code how much stuff there is)
            numel++;

            // We return 0 once something is added
            return 0;
        }

        // We rehash the data key in the case of collisions
        hk = rehash(hk);
    }

    // If none of the conditions are fulfilled (we reach the end of the table), we return -1
    return -1;
}

// Remove Function: Removes data structure from the table
int HTable::remove(data &d){
    // Create a hash key equal to the hash code of the data key
    int hk = hash(d.key);

    // Create a variable that sees how many times we go through the while loop
    int check = 0;

    // If the table isn't filled...
    if (numel == 0){
        // We return -1
        return -1;
    }
    else{
        // While the number of times we go through the loop is less than the max size...
        while (check != max_size){
            if (dt[hk].key == d.key){
                // We assign the defined data structure as having the initial constructor values
                dt[hk].key = -1;
                dt[hk].value = "N/A";
                
                // We decrement numel to say there is one less item in the table
                numel--;

                // We return 0
                return 0;
            }
            // We increase the check variable to eventually reach max_size
            check++;

            // We rehash the data key
            hk = rehash(hk);
        }
    }

    // We return -1 in case the key isn't even in the function
    return -1;

}

// Output Function
void HTable::output(){

    for (int i = 0; i < max_size; i++){
        // We output the content of the table line by line
        cout << i << " ->" <<  " " << dt[i].key << " " << " " << dt[i].value << endl;
    }

    // We print out the amount of data stored in the table
    cout << "There is " << numel << " data in the table." << endl;

}