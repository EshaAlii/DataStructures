#include <iostream>

using namespace std;

int main(){
  int number;
  char alpha; //named it alpha as a shorhand for alphanumeric characters

  cout << "Enter the number of lines for the punishment: " << endl;
  cin >> number;

  if (number < 0 || number == alpha){
    cout << "You entered an incorrect value for the  number of lines!" << endl;
    return 0;
  }


  for (int i = 0; i < number; i++){
    if (number > 0){
      cout << "I will always use object oriented programming." << endl;
    }
  }
  return 0;

}