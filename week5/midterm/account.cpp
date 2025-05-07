#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "account.h"

using namespace std;

//implement functions
Account createAccount() {
    Account account;
    account.accountNumber = getAccountNumber();
    account.holderName = inputAccountName();
    account.balance = inputBalance();

    return account;
}


int getAccountNumber() {
    int accountNumber = 0;
    bool isValid = false;

    while (!isValid) {
        cout << "Please create a 6 digit account number: ";
        cin >> accountNumber;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        isValid = checkAccountNumber(accountNumber);
    }

    return accountNumber;
}

string inputAccountName() {
    string holderName;
    bool isValid = false;

    while (!isValid) {
        cout << "Please enter your first and last name separated by a space: ";
        getline(cin, holderName);
        if (!checkAccountName(holderName)) {
            cout << "Invalid input!" << endl;
        } else {
            isValid = true;
        }
    }

    return holderName;
}

double inputBalance() {
    double accountBalance;
    bool isValid = false;

    while (!isValid) {
        cout << "Please enter your initial account balance in USD: ";
        cin >> accountBalance;

        isValid = checkBalance(accountBalance);
    }

    return accountBalance;
}