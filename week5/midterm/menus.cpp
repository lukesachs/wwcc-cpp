#include <iostream>
#include <vector>
#include "account.h"
#include "menu.h"
#include "userInterface.h"
#include "validation.h"

void mainMenuInput(vector<Account> &accounts, int option){
    bool isValid = true;
    switch(option){
    case 1: //create account
    accounts.push_back(createAccount());
        break;
    case 2: //access account info
        displayAccountOptions();
        do{
            cin >> option;
            if(accountMenuValid(option)){
                isValid = false;
            }
        }while(!isValid);

        accountMenuInput(accounts, option);
    break;
    case 3: //make transaction
        displayTransactionOptions();
        do{
            cin >> option;
            if(transactionMenuValid(option)){
                isValid = false;
            }
        }while(!isValid);

        transactionMenuInput(accounts, option);
        break;
    case 4: //exit program
        shutDown();
        break;
    default:
        cout << "ERROR" << endl;
        break;
    }
}



void accountMenuInput(vector<Account> &accounts, int option){
    bool isValid = true;
    int ID = chooseID(accounts);;
    int index;

    
    switch(option){
        case 1: //Transaction History
            getTransactionHistory(accounts[ID]);
            break;
        case 2: //Account Statements
            getAccountStatement(accounts[ID]);

            break;
        case 3: //Personal Info
            
            

            break;
        default:
            cout << "ERROR" << endl;
            break;
        }
}



void transactionMenuInput(vector<Account> &accounts, int option){
    int index = chooseID(accounts);
    switch(option){
        case 1: //Deposit Funds
            depositFunds(accounts[index]);
            break;
        case 2: //Withdraw Funds
            withdrawFunds(accounts[index]);
            break;
        case 3: //Transfer Funds
            if(accounts.size()<2){
                cout << "Must have at least two accounts in the system to be able to transfer funds" << endl;
                break;
            }
            cout << "What Account ID# are you transfering to?" << endl;
            int index2 = chooseID(accounts);
            transferFunds(accounts[index], accounts[index2]);
            break;
        default: 
            cout << "ERROR" << endl;
            break;
    }
}