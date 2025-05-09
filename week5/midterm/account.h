#ifndef ACCOUNT_H //checks if account.h has not been previouly defined
#define ACCOUNT_H //defines account.H if it has not been previously defined 
#include <string>
#include <vector>

using namespace std;

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
string inputAccountName();
double inputBalance();
void depositFunds(Account &accounts);
void withdrawFunds(Account &accounts);
void transferFunds(Account &accounts, Account &accounts2);
int chooseID(const vector<Account> &accounts);
int chooseID2(const vector<Account> &accounts);
#endif // skips definition if already defined previously