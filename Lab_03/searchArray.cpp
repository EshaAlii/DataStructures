#include<iostream>

using namespace std;

int main(){

    // Initialize Variables
    int size;
    int value;
    int count = 1;
    int *arr = new int[size];


    // User enters size of array
    cout << "Enter the size of the array: " << endl;
    cin >> size;

    // If entered size isn't good, Error message
    if (size <= 0){
        cout << "ERROR: You entered an incorrect value for the array size!" << endl;
    }

    // Else...
    else{

        // User enters numbers into array
        cout << "Enter the numbers in the array, seperated by a a space, and press enter: " << endl;
        for(int i = 0; i < size; i++){
            cin >> arr[i];
        }

        // User enters number to search in array
        cout << "Enter a number to search for in the array: " << endl;
        cin >> value; 

        // For loop that checks if entered value = to arr[i]
        for (int i = 0; i < size; i++){
            int x = i+1;
            if (value == arr[i]){
                cout << "Found value " << value << " at index " << i << " which took " << x << " checks." << endl;
                if (x == size){
                    cout << "We ran into the worst case scenario." << endl;
                }
                else if (x == 1){
                    cout << "We ran into the best case scenario!" << endl;
                }
                break;
            }
            // Else count counter adds one
            else{
                count++;
            }
        }

        // If the counter is equal to the size of the array + 1, return the value wasn't found
        if (count == size+1){
            cout << "The value " << value << " was not found in the array!" << endl;
        }


    }

    // Being responsible with our code
    delete [] arr;

    return 0;
}