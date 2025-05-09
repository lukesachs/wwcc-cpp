#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "account.h"
#include "validation.h"
using namespace std;

//implement functions
Account createAccount() {
    Account account;
    account.accountNumber = getAccountNumber();
    account.holderName = inputAccountName();
    account.balance = inputBalance();
    account.transactionCount = 0;

    return account;
}


int getAccountNumber() {
    int accountNumber = 0;
    bool isValid = false;
    
    while (!isValid) {
        cout << "Please create a 6 digit account number: ";
        cin >> accountNumber;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        isValid = checkNewID(accountNumber);
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

int chooseID(const vector<Account> &account, bool secondID){
    int accountID;
    int index;
    do{
        cout << "Please enter the ID number of the account you wish to access :" << endl;
        cin >> accountID;
    }while(!confirmID(accountID, account, index, secondID));
    return index;
}

int chooseID2(const vector<Account> &account){
    if(account.size()<2){
        cout << "Must have at least two accounts in the system to be able to transfer funds" << endl;
        return -1;
    }
    cout << "What Account ID# are you transfering to?" << endl;
    return chooseID(account, true);
}

void depositFunds(Account &account){
    int index = account.transactionCount;
    double funds = 0.0;
    account.history[account.transactionCount].type = "deposit";
    do{
    cout << "Please enter the amount of money to be deposited" << endl;
    cin >> funds;
    } while(!checkTransaction(funds, account, index));

    account.balance += funds;
    cout << "New account balance is $" << account.balance;
    account.transactionCount++;
}
void withdrawFunds(Account &account){
    int index = account.transactionCount;
    double funds = 0.0;
    account.history[index].type = "withdrawal";
    do{
    cout << "Please enter the amount of money to be withdrawn" << endl;
    cin >> funds;
    } while(!checkTransaction(funds, account, index));

    account.balance -= funds;
    cout << "New account balance is $" << account.balance;
    account.transactionCount++;
}

void transferFunds(Account &from, Account &to){
    int index = from.transactionCount;
    int index2 = to.transactionCount;
    double funds = 0.0;

    from.history[index].type = "transfer";
    to.history[index2].type = "transfer";

    do{
        cout << "Please enter the amount of money to be transfered" << endl;
        cin >> funds;
    } while(!checkTransaction(funds, to, index));

    from.balance -= funds;
    to.balance += funds;
    cout << "New account balance for " << from.accountNumber << " is $" << from.balance;
    cout << "New account balance for " << to.accountNumber << " is $" << to.balance;
    from.transactionCount++;
    to.transactionCount++;
}
