#include <iostream>
#include <string>

using namespace std;

int main(){
  
  // Initialize the Variables
  string alpha;
  string arr[] = {alpha};

  // User Input
  cout << "Enter the string to reverse: " << endl;
  cin >> alpha;


  // For loop to Reverse the String Using 
  cout << "The reverse of the string is: " << endl;
  for (int i = 0; i < alpha.size(); i++){
    cout << alpha[alpha.size() - i - 1];
  }
  cout << endl;
  
  return 0;
}