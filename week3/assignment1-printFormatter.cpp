#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

// Function prototype
string format(int num);
string format(double num);
string format(double numD, int numI);
string format(string s);

int main(){
    //example 1
    int exampleInt = 1234567;
    cout << "Integer formatting:\n";
    cout << "Original: " << exampleInt << endl;
    cout << "Formatted: " << format(exampleInt) << endl;

    //example 2
    double exampleDouble = 45.6789;
    cout << "\nDouble formatting:\n";
    cout << "Original: " << exampleDouble << endl;
    cout << "Formatted: " << format(exampleDouble) << endl;

    //example 3
    int precision = 3;
    cout << "\nDouble formatting (custom decimal places):\n";
    cout << "Original: " << exampleDouble << " with precision " << precision << endl;
    cout << "Formatted: " << format(exampleDouble, precision) << endl;

    //example 4
    string exampleString = "hello world of c++ programming";
    cout << "\nString  formatting:\n";
    cout << "Original: " << exampleString << endl;
    cout << "Formatted: " << format(exampleString) << endl;

    return 0;
}

string format(int num){

    //initialize string
    string str(to_string(num));

    //find length
    int length = str.length();

    for(int i = length; i >0; i--){

        if( (length - i + 1) % 3 == 0){

            //inserts comma at every third index
            str.insert(i-1,",");
        }
    }

    //returns string correct int formatting with commas seperating every three digits
    return str;
}


string format(double num){

    //initializes streamstring
    stringstream sstr;

    //makes sure setprecision only affects the decimal places using fixed.
    sstr << fixed << setprecision(2) << num;

    //returns string with correct decimal precision
    return sstr.str();

}

string format(double num, int i){

    //initializes streamstring
    if(i < 0){

        return("Cannot format a decimal to a negative precision.");
    }

    stringstream sstr;

    //makes sure setprecision only affects i amount of decimal places using fixed.
    sstr << fixed << setprecision(i) << num;

    //returns string with correct decimal precision
    return sstr.str();

}

string format(string s){

    //get string length
    int length = s.length();
    //check that string isn't empty
    if(length == 0){
        return "Empty string inputted.";
    }
    //iterate through the string
    for(int i = 0; i < length; i++){
        //Checks if first digit isn't a space before attempting to make uppercase
        if(i == 0 && s[i] != ' '){
            //change to uppercase
            s[i] = toupper(s[i]);
            //making sure that after the space, there isn't another space or the end of the string
        }else if(s[i] == ' ' && i + 1 < length && s[i + 1] != ' '){
                //change to uppercase
            s[i+1] = toupper(s[i + 1]);
        }
    }

    return s;
}