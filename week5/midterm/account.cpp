#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "account.h"
#include "validation.h"

using namespace std;

//implement functions
Account createAccount() {
    Account accounts;
    accounts.accountNumber = getAccountNumber();
    accounts.holderName = inputAccountName();
    accounts.balance = inputBalance();
    accounts.transactionCount = 0;

    return accounts;
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

int chooseID(const vector<Account> &accounts, bool secondID){
    int accountID;
    int index;
    do{
        cout << "Please enter the ID number of the account you wish to access :" << endl;
        cin >> accountID;
    }while(!confirmID(accountID, accounts, index, secondID));
    return index;
}

int chooseID2(const vector<Account> &accounts){
    if(accounts.size()<2){
        cout << "Must have at least two accounts in the system to be able to transfer funds" << endl;
        return -1;
    }
    cout << "What Account ID# are you transfering to?" << endl;
    return chooseID(accounts, true);
}

void depositFunds(Account &accounts){
    int index = accounts.transactionCount;
    double funds = 0.0;
    accounts.history[accounts.transactionCount].type = "deposit";
    do{
    cout << "Please enter the amount of money to be deposited" << endl;
    cin >> funds;
    } while(!checkTransaction(funds, accounts, index));

    accounts.balance += funds;
    cout << "New account balance is $" << accounts.balance;
    accounts.transactionCount++;
}
void withdrawFunds(Account &accounts){
    int index = accounts.transactionCount;
    double funds = 0.0;
    accounts.history[index].type = "withdrawal";
    do{
    cout << "Please enter the amount of money to be withdrawn" << endl;
    cin >> funds;
    } while(!checkTransaction(funds, accounts, index));

    accounts.balance -= funds;
    cout << "New account balance is $" << accounts.balance;
    accounts.transactionCount++;
}

void transferFunds(Account &accounts, Account &accounts2){
    int index = accounts.transactionCount;
    int index2 = accounts.transactionCount;
    double funds = 0.0;

    accounts.history[index].type = "transfer";
    accounts2.history[index2].type = "transfer";

    do{
        cout << "Please enter the amount of money to be transfered" << endl;
        cin >> funds;
    } while(!checkTransaction(funds, accounts, index));

    accounts.balance -= funds;
    accounts2.balance += funds;
    cout << "New account balance for " << accounts.accountNumber << " is $" << accounts.balance;
    cout << "New account balance for " << accounts2.accountNumber << " is $" << accounts2.balance;
    accounts.transactionCount++;
    accounts2.transactionCount++;
}
