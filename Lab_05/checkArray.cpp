#include<iostream>
#include<fstream>
#include<string>

using namespace std;

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
    int size = 0;
    string str;
    int choice;

    // Define which file to read and which file to write
    ifstream input;

    // Open file input
    input.open("words_in.txt");

    // While loop to maintain size;
    while(getline(input, str)){
        size++;
    }

    // Close file input
    input.close();

    // Define array AFTER you properly define size
    string *arr = new string[size];

    // Open file input
    input.open("words_in.txt");

    // For loop to get stuff from words_in.txt
    for(int i = 0; i < size; i++){
        getline(input, str);
        arr[i] = str;
    }

    // Save the checkArraySort Function into the variable called choice
    choice = checkArraySort(size, arr);

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

    // Close input file
    input.close();

    // Delete arr
    delete [] arr;

    // End program
    return 0;
}