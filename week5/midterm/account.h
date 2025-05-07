#ifndef ACCOUNT_H //checks if account.h has not been previouly defined
#define ACCOUNT_H //defines account.H if it has not been previously defined 

#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// Struct definitions
struct Date {
    int day;
    int month;
    int year;
};

struct Transaction {
    std::string type;  // "deposit", "withdrawal", "transfer"
    double amount;
    Date date;
};

struct Account {
    int accountNumber;
    string holderName;
    double balance;
    std::vector<Transaction> history;
    int transactionCount;
};

// Function prototypes (declarations only)
void displayAccountOptions();
void displayTransactionOptions();
void displayDate(Date d);
void welcomeUser();
Account createAccount();
int getAccountNumber();
bool checkAccountNumber(int accountNumber);
string inputAccountName();
bool checkAccountName(string accountName);
double inputBalance();
bool checkBalance(double accountBalance);


#endif // skips definition if already defined previously