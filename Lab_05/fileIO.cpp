#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(){
    // Initialize variables
    int size = 0;
    string str;

    // Define which file to read and which file to write
    ifstream input;
    ofstream output;

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

    // Close file input
    input.close();

    //Open file output
    output.open("words_out.txt");

    // For loop to output the previously stored array into words_out.txt
    for(int i = 0; i < size; i++){
        output << arr[i] << "\n";
    }

    // Close file output
    output.close();

    // Delete arr
    delete [] arr;

    // End program
    return 0;
}