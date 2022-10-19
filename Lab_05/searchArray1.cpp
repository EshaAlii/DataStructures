#include<iostream>
#include<fstream>
#include<string>

using namespace std;

// binarySearchR function
int binarySearchR(string arr[], string key, int high, int low, int choice){
    // Initialize our index variable
    int i; 

    // Initialize our midpoint variable
    int mid = (high + low)/2;

    // If array is ascending...
    if (choice == 1){

        // If the top part is larger than bottom...
        if (high >= low){

            // We recursively check the conditions to see what index the key is
            if (key == arr[mid]){
                i = mid;
            }
            if (key < arr[mid]){
                return binarySearchR(arr, key, mid-1, low, choice);
            }
            if (key > arr[mid]){
                return binarySearchR(arr, key, high, mid+1, choice);
            }
        }
        else{
            // Otherwise the index does not exist
            i = -1;
        }
    }

    // If array is descending... 
    if (choice == -1){

        // If the top part is larger than bottom...
        if (high >= low){

            // We recursively check the conditions to see what index the key is
            if (key == arr[mid]){
                i = mid;
            }
            if (key > arr[mid]){
                return binarySearchR(arr, key, mid-1, low, choice);
            }
            if (key < arr[mid]){
                return binarySearchR(arr, key, high, mid+1, choice);
            }
        }
        else{
            // Otherwise the index does not exist
            i = -1;
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

    // Save binarySearchR function into a variable called bs
    bs = binarySearchR(arr, key, high, low, choice);

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

    // End program
    return 0;
}