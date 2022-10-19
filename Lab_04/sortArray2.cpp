#include<iostream>

using namespace std;

// sortarr function to sort the array using Selection Sort
void sortarr(int &size,int arr[],int &choice){

    // If the User Inputs 0, we Ascend
    if (choice == 0){

        // Insertion Sort for Ascending Order
        for (int i = 1; i < size; i++){
            int saved = arr[i];
            int j = i;
            while (j>0 && arr[j-1] > saved){
                arr[j] = arr[j-1];
                j = j-1;
            }
            arr[j] = saved;
        }
        
        // Returning our Array in Ascending Order
        cout << "This is the array in ascending order: " << endl;
        for (int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }


    // If the User Inputs 1, we Descend
    else if (choice == 1){

        // Insertion Sort for Descending Order
        for (int i = 1; i < size; i++){
            int saved = arr[i];
            int j = i;
            while (j>0 && arr[j-1] < saved){
                arr[j] = arr[j-1];
                j = j-1;
            }
            arr[j] = saved;
        }

        // Returning our Array in Descending Order
        cout << "This is the array in descending order: " << endl;
        for (int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

}


int main(){

    // Initialize Variables
    int choice;
    int size;
    int *arr = new int[size];

    // User enters size of array
    cout << "Enter the size of the array: " << endl;
    cin >> size;

    // If Entered Size Isn't Good, Error message
    if (size <= 0){
        cout << "ERROR: You entered an incorrect value for the array size!" << endl;
    }

    // Else...
    else{

        // User Enters Numbers Into Array
        cout << "Enter the numbers in the array, seperated by a a space, and press enter: " << endl;
        for(int i = 0; i < size; i++){
            cin >> arr[i];
        }

        cout << "Choose to sort in ascending (0) or descending (1) order: " << endl;
        cin >> choice;

        // We Call Our Function to Sort
        sortarr(size, arr, choice);
    }


    // Being Responsible With Our Code
    delete [] arr;

    return 0;

}