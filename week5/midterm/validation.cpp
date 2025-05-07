#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "validation.h"

using namespace std;



bool checkAccountNumber(int accountNumber) {
    if (cin.fail()) {
        cout << "Invalid input! Only numbers allowed." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    } else if (accountNumber < 100000 || accountNumber > 999999) {
        cout << "Invalid input! Account number must be 6 digits." << endl;
        return false;
    } else {
        return true;
    }
}

bool checkAccountName(string holderName) {
    string sub = holderName;

    if (holderName.empty() || holderName.find(" ") == string::npos) {
        return false;
    }

    // Checks if the space is at the correct position
    if (holderName.find(" ") == 0 || holderName.find(" ") == holderName.length() - 1) {
        return false;
    }

    // Checks if there is more than one space
    if (holderName.find("  ") != string::npos) {
        return false; // Multiple spaces between words
    }

    return true;
}

bool checkBalance(double accountBalance) {
    if (cin.fail()) {
        cout << "Invalid input!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    } else if (accountBalance < 0) {
        cout << "Invalid input! Balance cannot be negative." << endl;
        return false;
    } else {
        return true;
    }
}