#ifndef MENU_H
#define MENU_H

#include <vector>
#include "account.h"
#include "menu.h"
#include "userInterface.h"

void mainMenuInput(vector<Account> &account, int option);
void accountMenuInput(vector<Account> &account, int option);
void transactionMenuInput(vector<Account> &account, int option);

#endif //MENU_H