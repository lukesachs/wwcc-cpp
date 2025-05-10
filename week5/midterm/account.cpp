#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "account.h"
#include "validation.h"
using namespace std;

//implement functions
Account createAccount(vector<Account> &accounts) {
    Account account;
    account.accountNumber = getAccountNumber(accounts);
    account.holderName = inputAccountName();
    account.balance = inputBalance();
    account.transactionCount = 0;

    return account;
}


int getAccountNumber(const vector<Account> &accounts) {
    int accountNumber = 0;
    bool isValid;
    do{
        cout << "Please create a 6 digit account number: ";
        cin >> accountNumber;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        isValid = checkNewID(accountNumber);
        if (isValid) {
            // Basic for loop to check for duplicates in the accounts vector
            for (int i = 0; std::vector<Transaction>::size_type(i) < accounts.size(); i++) {
                if (accounts[i].accountNumber == accountNumber) {
                    cout << "Account number already exists. Please choose a different one." << endl;
                    isValid = false;
                    break;  // Exit the loop if a duplicate is found
                }
            }
        }
    } while(!isValid);

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

int chooseID(const vector<Account> &account, bool isTransfer) {
    int accountID;
    int index = -1;
    
    // Display the appropriate prompt based on the transaction
    if (isTransfer) {
        cout << "What Account ID# are you transferring to?" << endl;
    } else {
        cout << "Please enter the ID number of the account you wish to access:" << endl;
    }

    // Continuously ask for a valid ID number until it passes validation
    do {
        cin >> accountID;
        if (checkCinFail()) continue;  // Check for invalid input

    } while (!confirmID(accountID, account, index));

    return index;  // Return the index of the selected account
}

void depositFunds(Account &account){
    Transaction trnsct;
    double funds = 0.0;

    do{
    cout << "Please enter the amount of money to be deposited" << endl;
    cin >> funds;
    } while(!checkTransaction(funds, account, "deposit"));
    trnsct.type = "deposit";
    trnsct.amount = funds;
    trnsct.date = getDate(account);

    account.balance += funds;

    cout << "New account balance is $" << account.balance << endl;
    
    account.history.push_back(trnsct);
    account.transactionCount++;
}
void withdrawFunds(Account &account){
    Transaction trnsct;
    double funds = 0.0;

    do{
    cout << "Please enter the amount of money to be withdrawn" << endl;
    cin >> funds;
    } while(!checkTransaction(funds, account, "withdrawal"));

    trnsct.type = "withdrawal";
    trnsct.amount = funds;
    trnsct.date = getDate(account);

    account.balance -= funds;

    cout << "New account balance is $" << account.balance << endl;
    
    account.history.push_back(trnsct);
    account.transactionCount++;
}

void transferFunds(Account &from, Account &to){
    Transaction trnsct;

    double funds = 0.0;
    do{
        cout << "Please enter the amount of money to be transfered" << endl;
        cin >> funds;
    } while(!checkTransaction(funds, from, "transfer"));  

    trnsct.type = "transfer";
    trnsct.amount = funds;
    trnsct.date = getDate(from);

    from.balance -= funds;
    to.balance += funds;

    cout << "New account balance for " << from.accountNumber << " is $" << from.balance << endl;
    cout << "New account balance for " << to.accountNumber << " is $" << to.balance << endl;

    from.history.push_back(trnsct);
    to.history.push_back(trnsct);
    from.transactionCount++;
    to.transactionCount++;
}

Date getDate(const Account &account){
    Date d;
    do{
        cout << "Please enter transaction Day, Month and Year separately." << endl;
        cout << "Enter day: " << endl;
        cin >> d.day;
        if(checkCinFail()){
            continue;
        }
        cout << "Enter month: " << endl;
        cin >> d.month;
        if(checkCinFail()){
            continue;
        }
        cout << "Enter year: " << endl;
        cin >> d.year;
        if(checkCinFail()){
            continue;
        }
    }while(!checkDate(d.day, d.month, d.year, account));
    return d;
}
Date getDate(const Account &to, const Account &from){
    Date d;
    bool isValid = false;
    do{
        cout << "Please enter transaction Day, Month and Year separately." << endl;
        cout << "Enter day: " << endl;
        cin >> d.day;
        if(checkCinFail()){
            continue;
        }
        cout << "Enter month: " << endl;
        cin >> d.month;
        if(checkCinFail()){
            continue;
        }
        cout << "Enter year: " << endl;
        cin >> d.year;
        if(checkCinFail()){
            continue;
        }
    } while (!isValid);
    return d;
}