#ifndef ACCOUNT_H //checks if account.h has not been previouly defined
#define ACCOUNT_H //defines account.H if it has not been previously defined 
#include <string>
#include <vector>


// Struct definitions
struct Date {
    int day;
    int month;
    int year;
};

struct Transaction {
    string type;  // "deposit", "withdrawal", "transfer"
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
Account createAccount();
int getAccountNumber();
std::string inputAccountName();
double inputBalance();
void depositFunds(Account &account);
void withdrawFunds(Account &account);
void transferFunds(Account &from, Account &to);
int chooseID(const vector<Account> &account);
int chooseID2(const vector<Account> &account);
#endif // skips definition if already defined previously