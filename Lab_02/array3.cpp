#include <iostream>

using namespace std;

int main(){

    // Initialize Variables
    int size;
    int arr[size][size];
    char alpha;
    int count = 0;

    // Ask User for values of row one
    cout << "Enter the size of a 2D array: " << endl;
    cin >> size;

    // Check if the Input of the Array is Good
    if (size > 10 || size <= 0 || size == alpha){
        cout << "Your array is too large! Enter a value from 1 to 10!" << endl;
    }


    // If the Input is Good...
    else{

        // Ask User for values in each row
        for (int i = 1; i <= size; i++){
            cout << "Enter the values in the array for row " << i << " seperated by a space, and press enter." << endl;
            for (int j = 1; j <= size; j++){
                cin >> arr[i][j];
                
                // Count negative values on each row
                if (arr[i][j] < 0){
                    count = count + 1;
                }
            }
        }

        // If the Count is Greater Than Zero, We Return the Number of Negatives. Else we say There are None.
        if (count > 0){
            cout << "There are " << count << " negative values." << endl;
        }
        else{
            cout << "All values are non-negative." << endl;
        }
        
    }

    return 0;

}
