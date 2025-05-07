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
    int accountID;
    
    switch(option){
        case 1: //Transaction History
            break;
        case 2: //Account Statements
            displayUserOptions();
            cin >> option;
    
            
            break;
        case 3: //Personal Info
            displayTransactionOptions();
            cin >> option;

            break;
        default:
            cout << "ERROR" << endl;
            break;
        }
}



void transactionMenuInput(vector<Account> &accounts, int option){
    switch(option){
        case 1: //Deposit Funds

            break;
        case 2: //Withdraw Funds
    

            break;
        case 3: //Transfer Funds

            
            break;
        default: 
            cout << "ERROR" << endl;
            break;
    }
}