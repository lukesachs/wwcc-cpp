#ifndef VALIDATION_H
#define VALIDATION_H

#include <vector>
#include <string>
#include "account.h"

//declare funcions
bool checkCinFail();
bool checkNewID(int accountNumber);
bool confirmID(int ID, const std::vector<Account> &account, int &index);
bool checkAccountName(std::string accountName);
bool checkBalance(double accountBalance);
bool mainMenuValid(int option);
bool accountMenuValid(int option);
bool transactionMenuValid(int option);
bool checkTransaction(double amount, const Account &account, const std::string &type);
bool checkDate(int day, int month, int year, const Account &account);
bool checkDate(int day, int month, int year, const Account &to, const Account &from);

#endif //validation.h
