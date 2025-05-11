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
    std::string type;  // "deposit", "withdrawal", "transfer"
    double amount;
    Date date;
};

struct Account {
    int accountNumber;
    std::string holderName;
    double balance;
    std::vector<Transaction> history;
    int transactionCount;
};

// Function prototypes (declarations only)
Account createAccount(std::vector<Account> &accounts);
int getAccountNumber(const std::vector<Account> &accounts);
std::string inputAccountName();
double inputBalance();
int chooseID(const std::vector<Account> &account, bool secondID);
void depositFunds(Account &account);
void withdrawFunds(Account &account);
void transferFunds(Account &from, Account &to);
Date getDate(const Account &account);
Date getDate(const Account &to, const Account &from);
#endif // account.h