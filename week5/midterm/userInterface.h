#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "account.h"

void displayAccountOptions();
void displayTransactionOptions();
void displayDate(Date d);
void welcomeUser();
void displayUserOptions();
void shutDown();
void getTransactionHistory(const Account &account);
void getPersonalInfo(const Account &account);
void getAccountStatement(const Account &account);

#endif //USERINTERFACE_H