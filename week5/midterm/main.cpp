#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "account.h"
#include "userInterface.h"

using namespace std;


// Function prototypes
void displayAccountOptions();
void displayTransactionOptions();
void displayDate(Date d);
void welcomeUser();
void displayUserOptions();
Account createAccount();
int getAccountNumber();
bool checkAccountNumber(int accountNumber);
string inputAccountName();
bool checkAccountName(string accountName);
double inputBalance();
bool checkBalance(double accountBalance);

// Main function
int main() {
    vector<Account> accounts;

    welcomeUser();
    accounts.push_back(createAccount());
    int option = 0;
    do{
        displayUserOptions();
        cin >> option;

    } while(option != 4);
    return 0;
}
