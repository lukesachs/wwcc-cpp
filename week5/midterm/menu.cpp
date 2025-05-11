#include <iostream>
#include <vector>
#include "account.h"
#include "menu.h"
#include "userInterface.h"
#include "validation.h"
using namespace std;

void mainMenuInput(vector<Account> &accounts, int option){
    bool isValid = false;
    int subOption = -1;
    switch(option){
    case 1: //create account
    accounts.push_back(createAccount(accounts));//creates account and adds to accounts vector
        break;
    case 2: //access account info
        displayAccountOptions();
        do{
            cin >> subOption;
            if (checkCinFail()) continue;
            if(accountMenuValid(subOption)){
                isValid = true;
            }
        }while(!isValid);

        accountMenuInput(accounts, subOption);
    break;
    case 3: { //make transaction
        displayTransactionOptions();
        do{
            cin >> subOption;
            if (checkCinFail()) continue;
            if(transactionMenuValid(subOption)){
                isValid = true;
            }
        }while(!isValid);
        transactionMenuInput(accounts, subOption);
        break;
    }
    case 4: //exit program
        shutDown();
        break;
    default:
        cout << "ERROR" << endl;
        break;
    }
}



void accountMenuInput(vector<Account> &accounts, int option){
    int ID = chooseID(accounts, false); //gets ID for account options
    switch(option){
        case 1: //Transaction History
            getTransactionHistory(accounts[ID]);
            break;
        case 2: //Account Statements
            getAccountStatement(accounts[ID]);
            break;
        case 3: //Personal Info
            getPersonalInfo(accounts[ID]);
            break;
        default:
            cout << "ERROR" << endl;
            break;
        }
}

void transactionMenuInput(vector<Account> &accounts, int option){
    int index = chooseID(accounts, false);
    if (index == -1) { //pervents segmentation fault
        cout << "Invalid account ID selected." << endl;
        return;
    }
    int index2 = -1;
    switch (option) {
        case 1: // Deposit Funds
            depositFunds(accounts[index]);
            break;
        case 2: // Withdraw Funds
            withdrawFunds(accounts[index]);
            break;
        case 3: // Transfer Funds
            index2 = chooseID(accounts, true); //gets second ID index
            if (index2 < 0 || index2 >= (int)accounts.size()) {
                cout << "Invalid destination account. Transaction cancelled." << endl;
                return;
            }
            // Transfer funds if both account IDs are valid
            transferFunds(accounts[index], accounts[index2]);
            break;
        default:
            cout << "ERROR" << endl;
            break;
    }
}