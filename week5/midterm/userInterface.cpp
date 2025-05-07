#include <iostream>
#include <string>
#include "account.h"
#include "userInterface.h"

using namespace std;

void welcomeUser() {
    cout << "EXTREMELY LEGITIMATE BANKING SYSTEM" << endl;
    cout << "***********************************" << endl;
    cout << "\nWelcome to the extremely legitimate banking system, where we have your best interests at heart." << endl;
    cout << "To access system features, please begin by creating an account!" << endl;
}

void displayUserOptions(){
    cout << "Please enter a number 1-4 to select:" << endl;
    cout << "   1. Create bank account" << endl;
    cout << "   2. Access bank account info" << endl;
    cout << "   3. Make a transaction" << endl;
    cout << "   4. Exit Banking System" << endl;
}

void displayAccountOptions() {
    cout << "Account options include 1. transaction history, 2. account statements, and 3. personal information.";
    cout << "   1. Access Transaction History" << endl;
    cout << "   2. Access Account Statement" << endl;
    cout << "   3. Access Personal Information" << endl;
}

void displayTransactionOptions() {
    cout << "Please enter a number 1-3 to select:" << endl;
    cout << "   1. Deposit Funds" << endl;
    cout << "   2. Withdraw Funds" << endl;
    cout << "   3. Transfer Funds" << endl;
}

void displayDate(Date d) {
    cout << d.month << "/" << d.day << "/" << d.year;
}

void shutDown(){
    cout << "Thank you for using the extremely legitimate banking service!\nWe hope you found our services to be helpful." << endl;
    cout << "\n\n\nSHUTTING DOWN......." << endl;
}