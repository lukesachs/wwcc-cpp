#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "account.h"

void displayAccountOptions();
void displayTransactionOptions();
void displayDate(Date d);
void welcomeUser();
void displayUserOptions();
void shutDown();
void getTransactionHistory(const Account &accounts);
void getAccountStatement(Account accounts);

#endif //USERINTERFACE_H