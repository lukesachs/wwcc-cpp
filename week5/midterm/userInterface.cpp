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

void displayMainMenuOptions(){
    cout << "\nPlease enter a number 1-4 to select:" << endl;
    cout << "   1. Create bank account" << endl;
    cout << "   2. Access bank account info" << endl;
    cout << "   3. Make a transaction" << endl;
    cout << "   4. Exit Banking System" << endl;
}

void displayAccountOptions() {
    cout << "\nAccount options include 1. transaction history, 2. account statements, and 3. personal information." << endl;
    cout << "   1. Access Transaction History" << endl;
    cout << "   2. Access Account Statement" << endl;
    cout << "   3. Access Personal Information" << endl;
}

void displayTransactionOptions() {
    cout << "\nPlease enter a number 1-3 to select:" << endl;
    cout << "   1. Deposit Funds" << endl;
    cout << "   2. Withdraw Funds" << endl;
    cout << "   3. Transfer Funds" << endl;
}

void displayDate(Date d) {
    cout << d.month << "/" << d.day << "/" << d.year;
}

void getTransactionHistory(const Account &account){
    cout << "\nTransaction History for " << account.holderName << ": ID#" << account.accountNumber << endl;
    cout << "Total transaction count: " << account.transactionCount << endl;
    for(int i = 0; i < account.transactionCount; i++){
        cout << i + 1 << "." << endl; 
        displayDate(account.history[i].date);
        cout << " - " << account.history[i].type << " of $" << account.history[i].amount << endl;
        
    }
}

void getPersonalInfo(const Account &account){
    cout << "Account ID#: " << account.accountNumber << endl;
    cout << "Account Owner Name: " << account.holderName << endl;
    cout << "Account Balance: $" << account.balance << endl;
}

void getAccountStatement(const Account &account){
    cout << "\n\n*********** ACCOUNT STATEMENT ***********" << endl;
    getPersonalInfo(account);
    getTransactionHistory(account);
    cout << "*****************************************\n" << endl;
}

void shutDown(){
    cout << "\nThank you for using the extremely legitimate banking service!\nWe hope you found our services to be helpful." << endl;
    cout << "\n\n\nSHUTTING DOWN......." << endl;
}