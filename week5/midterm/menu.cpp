#include <iostream>
#include <vector>
#include "account.h"
#include "menu.h"
#include "userInterface.h"
#include "validation.h"
using namespace std;

void mainMenuInput(vector<Account> &account, int option){
    bool isValid = false;
    int subOption;
    switch(option){
    case 1: //create account
    account.push_back(createAccount());
        break;
    case 2: //access account info
        displayAccountOptions();
        do{
            cin >> subOption;
            if(accountMenuValid(subOption)){
                isValid = true;
            }
        }while(!isValid);

        accountMenuInput(account, subOption);
    break;
    case 3: //make transaction
        displayTransactionOptions();
        do{
            cin >> subOption;
            if(transactionMenuValid(subOption)){
                isValid = true;
            }
        }while(!isValid);
        transactionMenuInput(account, subOption);
        break;
    case 4: //exit program
        shutDown();
        break;
    default:
        cout << "ERROR" << endl;
        break;
    }
}



void accountMenuInput(vector<Account> &account, int option){
    int ID = chooseID(account);
    switch(option){
        case 1: //Transaction History
            getTransactionHistory(account[ID]);
            break;
        case 2: //Account Statements
            getAccountStatement(account[ID]);
            break;
        case 3: //Personal Info
            getPersonalInfo(account[ID]);
            break;
        default:
            cout << "ERROR" << endl;
            break;
        }
}



void transactionMenuInput(vector<Account> &account, int option){
    int index = chooseID(account);
    switch(option){
        case 1: //Deposit Funds
            depositFunds(account[index]);
            break;
        case 2: //Withdraw Funds
            withdrawFunds(account[index]);
            break;
        case 3: //Transfer Funds
            int index2 = chooseID2(account);
            if(index2 == -1){
                break;
            }
            transferFunds(account[index], account[index2]);
            break;
        default: 
            cout << "ERROR" << endl;
            break;
    }
}