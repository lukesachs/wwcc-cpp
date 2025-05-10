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
    std::cout << std::fixed << std::setprecision(2); //so doubles dont display as scientific notation and only 2 decimals
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
