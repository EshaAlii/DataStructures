#include <iostream>

using namespace std;

int main(){
  int number; // input for number of times we want to repeat line
  int typo; // input for line number we want the typo on
  char alpha; //named it alpha as a shorhand for alphanumeric characters


  // Enter the number and immedietly check if it is incorrect 
  cout << "Enter the number of lines for the punishment: " << endl;
  cin >> number;

  if (number < 0 || number == alpha){
    cout << "Number of lines is wrong." << endl;
    return 0;
  }

  // Enter the typo and immedietly check if it is incorrect
  cout << "Enter the line for which we want to make a typo: " << endl;
  cin >> typo;

  if (typo < 0 || typo == alpha || typo > number){
    cout << "Typo is wrong." << endl;
    return 0;
  }
  
  // add return 0 to the end of each of the if-statements since we don't want the program to continue running if it holds false


  // our for loop to work with the punishment
  for (int i = 1; i < number; i++){

    if (typo == i){
      cout << "I will always use object oriented programing." << endl;
    }

    else{
      cout << "I will always use object oriented programming." << endl;
    }

  }

  return 0;

}