#include<iostream>
#include<fstream>
#include<string>

using namespace std;

// binarySearchL function
int binarySearchL(string arr[], string key, int high, int low, int choice){

    // Initialize variable i as the index
    int i;

    // If top part of array is less than bottom part, index doesn't exist
    if (high < low){
        i = -1;
        return i;
    }

    // If array is ascending...
    if (choice == 1){

        // While the top part is larger than bottom...
        while (high >= low){

            // Initialize a midpoint variable
            int mid = (high + low)/2; 

            // We check the conditions to see what index the key is
            if (key == arr[mid]){
                i = mid;
                break;
            }
            if (key < arr[mid]){
                high = mid - 1;
            }
            if (key > arr[mid]){
                low = mid + 1;
            }
        }
    }

    // If array is descending...
    if (choice == -1){

        // While the top part is larger than bottom...
        while (high >= low){

            // We check the conditions to see what index the key is
            int mid = (high + low)/2; 
            if (key == arr[mid]){
                i = mid;
                break;
            }
            if (key > arr[mid]){
                high = mid - 1;
            }
            if (key < arr[mid]){
                low = mid + 1;
            }
        }
    }


    // Return the index
    return i;
}


// checkArraySort Function
int checkArraySort(int size, string arr[]){

    // Initialize variable choice to return
    int choice;

    // We first want to see the array based on the first two indeces
    if (arr[0] > arr[1]){
        choice = -1;
    }
    if (arr[0] < arr[1]){
        choice = 1;
    }
    if (arr[0] == arr[1]){
        choice = 0;
    }



    // Use a for loop to check for every situation with the indeces
    for(int i = 1; i < size-1; i++){
        if (choice == 1){
            if (arr[i] < arr[i+1]){
                choice = 1;
                break;
            }
            else{
                choice = 0;
                break;
            }
        }
        else if (choice == -1){
            if (arr[i] > arr[i+1] || arr[i-1] > arr[i]){
                choice = -1;
                break;
            }
            else{
                choice = 0;
                break;
            }
        }
        else if (choice == 0){
            choice = 0;
            break;
        }
    }


    // Return if its ascending, descending, or neither
    return choice;
}




int main(){
    // Initialize variables
    int high = 0;
    string str;
    string key;
    int choice;
    int low = 0;
    int bs;

    // Define which file to read and which file to write
    ifstream input;

    // Open file input
    input.open("words_in.txt");

    // While loop to maintain size;
    while(getline(input, str)){
        high++;
    }

    // Close file input
    input.close();

    // Define array AFTER you properly define size
    string *arr = new string[high];

    // Open file input
    input.open("words_in.txt");

    // For loop to get stuff from words_in.txt
    for(int i = 0; i < high; i++){
        getline(input, str);
        arr[i] = str;
    }

    // Save the checkArraySort Function into the variable called choice
    choice = checkArraySort(high, arr);


    // Conditions for choice being equal to each of the return values
    if (choice == -1){
        cout << "The array is in descending order!" << endl;
    }
    else if (choice == 1){
        cout << "The array is in ascending order!" << endl;
    }
    else if (choice == 0){
        cout << "The array is not sorted!" << endl;
        return 0;
    }

    // Ask user for search key
    cout << "Input search key: " << endl;
    cin >> key;

    // Save binarySearchL function into a variable called bs
    bs = binarySearchL(arr, key, high, low, choice);


    // Conditions for key being found at an index bs
    if (bs == -1){
        cout << "The key " << key << " was not found in the array!" << endl;
    }
    else{
        cout << "Found key " << key << " at index " << bs << "!"<< endl;
    }

    // Close input file
    input.close();

    // Delete arr
    delete [] arr;

    // End Program
    return 0;
}