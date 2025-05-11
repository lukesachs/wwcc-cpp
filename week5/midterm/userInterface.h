#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "account.h"

void welcomeUser();
void displayMainMenuOptions();
void displayAccountOptions();
void displayTransactionOptions();
void displayDate(Date d);
void getTransactionHistory(const Account &account);
void getPersonalInfo(const Account &account);
void getAccountStatement(const Account &account);
void shutDown();

#endif //userInterface.h