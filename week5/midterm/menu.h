#ifndef MENU_H
#define MENU_H

#include <vector>
#include "account.h"
#include "menu.h"
#include "userInterface.h"

void mainMenuInput(vector<Account> &accounts, int option);
void accountMenuInput(vector<Account> &accounts, int option);
void transactionMenuInput(vector<Account> &accounts, int option);

#endif //MENU_H