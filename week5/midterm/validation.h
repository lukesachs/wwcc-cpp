#ifndef VALIDATION_H
#define VALIDATION_H

#include <vector>
#include <string>
#include "account.h"

//declare funcions
bool checkBalance(double accountBalance);
bool checkAccountName(string accountName);
bool checkAccountNumber(int accountNumber);
bool mainMenuValid(int option);
bool transactionMenuValid(int option);
bool accountMenuValid(int option);
bool confirmID(int ID, const vector<Account> &accounts, int &index);
bool checkTransaction(double amount, Account accounts, int index);

#endif
