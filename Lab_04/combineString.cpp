#include<iostream>
#include<string>


using namespace std;

// CombineStr Function that combines strings
string combineStr(int number, string enter){

    // Create a new empty string to act as our returned string
    string stemp;

    // For loop that combines strings up until the entered number
    for(int i = 0; i < number; i++){
        stemp = stemp + enter;
    }

    return stemp;
}

int main(){

    // Initialize Variables
    int number;
    string enter;
    string blank;

    // Ask user for string
    cout << "Enter a string: " << endl;
    cin >> enter;

    // Ask user for number of times to repeat
    cout << "Enter a number of times: " << endl;
    cin >> number;

    // If the number is equal to zero we end the program
    if (number != 0){
        cout << "The resulting string is: " << combineStr(number, enter) << endl;
    }
    else{
        return 0;
    }


    // We Repeat This Process Until the User Enters Zero
    while (number != 0){


        if (number != 0){
            
            cout << "Enter a string: " << endl;
            cin >> enter;

            cout << "Enter a number of times: " << endl;
            cin >> number;

            if (number != 0){
                cout << "The resulting string is: " << combineStr(number, enter) << endl;
            }
            else{
                return 0;
            }
        }

        else{
            break;
        }
    }

    return 0;
    
}