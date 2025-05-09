#ifndef VALIDATION_H
#define VALIDATION_H

#include <vector>
#include <string>
#include "account.h"

//declare funcions
bool checkBalance(double accountBalance);
bool checkAccountName(string accountName);
bool checkNewID(int accountNumber);
bool mainMenuValid(int option);
bool transactionMenuValid(int option);
bool accountMenuValid(int option);
bool confirmID(int ID, const vector<Account> &account, int &index, bool secondID);
bool checkTransaction(double amount, const Account &account, int index);

#endif
