#ifndef VALIDATION_H
#define VALIDATION_H

#include <vector>
#include <string>
#include "account.h"

//declare funcions
bool checkBalance(double accountBalance);
bool checkAccountName(std::string accountName);
bool checkNewID(int accountNumber);
bool mainMenuValid(int option);
bool transactionMenuValid(int option);
bool accountMenuValid(int option);
bool confirmID(int ID, const std::vector<Account> &account, int &index);
bool checkTransaction(double amount, const Account &account, const std::string &type);
bool checkCinFail();
bool checkDate(int day, int month, int year, const Account &account);
bool checkDate(int day, int month, int year, const Account &to, const Account &from);
#endif
