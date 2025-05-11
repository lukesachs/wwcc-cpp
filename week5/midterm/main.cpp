#include <iostream>
#include <iomanip>
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
    cout << std::fixed << std::setprecision(2); //so doubles dont display as scientific notation and only 2 decimals
    welcomeUser();
    accounts.push_back(createAccount(accounts)); // prompts user to create initial account
    int option = 0;
    do{
        displayMainMenuOptions();
        cin >> option;
        if(!mainMenuValid(option)){//loops main menu input if not valid
           continue;
        }
        mainMenuInput(accounts, option);
    } while(option != 4);//ends program if option 4 is selected

    return 0;
}
