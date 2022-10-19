#include <iostream>

using namespace std;

int main(){
  
  // Initialize the Variables
  int size;
  int value = 0;
  int arr[size];
  char alpha;

  //User Input
  cout << "Enter the size of the array: " << endl;
  cin >> size;

  // Check If Size Doesn't Work
  if (size < 0 || size == alpha){
    cout << "ERROR: You entered an incorrect value for the array size!" << endl;
  }

  // If Size Works...
  else{
    cout << "Enter the numbers in the array seperated by a space: " << endl;


    // Enter Numbers
    for (int i = 0; i < size; i++){
      cin >> arr[i];
    }


    // Return Numbers
    for (int i = 0; i < size; i++){
      cout << arr[i] << " ";
    }
    cout << endl;

    
    // Not Increasing if Previous Number is Larger
    for (int i = 0; i < size; i++){
      if (arr[i] < arr[i-1]){
        cout << "This is NOT increasing." << endl;
        return 0;
      }
    }


    // Not Increasing if Next Number is Smaller, Else it is increasing
    for (int i = 1; i < size; i++){
      if (arr[i] > arr[i+1]){
        cout << "This is NOT increasing." << endl;
        return 0;
      }
      else{
        cout << "This IS increasing." << endl;
        return 0;
      }
    }
  }


  return 0;
}