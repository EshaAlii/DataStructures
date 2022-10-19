#include<iostream>

using namespace std;


int main(){

    // Initialize Variables
    int size;
    int count = 0;
    int *arr = new int[size];
    int Min;
    int iMin;


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
        
        // Selection sort code
        for (int i = size - 1; i < 1; i++){
            Min = arr[0];
            iMin = 0;
            for (int j = 1; j < i; j++){
                if (arr[j] < arr[iMin]){
                    Min = arr[j];
                    iMin = j;
                }
            }
            if(iMin != i){
                swap(arr[iMin], arr[i]);
            }
            count++;
        }


        // Outputting the array
        for (int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;

        // Telling us how the array acts
        cout << "This is the sorted array in descending order." << endl;
        cout << "The algorithm selected the minimum for the traverse of the array." << endl;
        cout << "It took " << count << " swap(s) to sort the array." << endl;
    }

    // Being responsible with our code
    delete [] arr;

    return 0;

}