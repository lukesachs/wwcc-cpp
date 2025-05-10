#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "account.h"
#include "menu.h"
#include "userInterface.h"
#include "validation.h"
using namespace std;



// Main function
int main() {
    vector<Account> accounts;

    welcomeUser();
    accounts.push_back(createAccount(accounts));
    int option = 0;
    do{
        displayUserOptions();
        cin >> option;
        if(!mainMenuValid(option)){
           continue;
        }
        mainMenuInput(accounts, option);
    } while(option != 4);

    return 0;
}
