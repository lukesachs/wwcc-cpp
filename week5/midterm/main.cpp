#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "account.h"
#include "userInterface.h"
#include "validation.h"
#include "menu.h"
using namespace std;



// Main function
int main() {
    vector<Account> account;

    welcomeUser();
    account.push_back(createAccount());
    int option = 0;
    do{
        displayUserOptions();
        cin >> option;
        if(!mainMenuValid(option)){
           continue;
        }
        mainMenuInput(account, option);
    } while(option != 4);

    return 0;
}
