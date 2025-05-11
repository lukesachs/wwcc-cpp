#ifndef MENU_H
#define MENU_H

#include <vector>
#include "account.h"
#include "userInterface.h"

void mainMenuInput(std::vector<Account> &accounts, int option);
void accountMenuInput(std::vector<Account> &accounts, int option);
void transactionMenuInput(std::vector<Account> &accounts, int option);

#endif //menu.h