# Simple Banking System Midterm
## Luke Sachs

## Program Explanation
The simple banking system allows for the creation of bank accounts, accessing bank account information, and making transactions. Creating bank accounts allows the user to input ID, name of account owner, and account balance. Making transactions includes the ability to deposit or withdraw funds, as well as transfer funds between accounts. When displaying the account information, the user is able to choose between accessing personal information, transaction history, and account statements. 

## Explanation of files
main.cpp is self explanatory

account.cpp/h includes all account specific code, such as account related structs and functions related to inputing account info.

validation.cpp/h includes functions to check user input and make sure each input has the correct data type and constraints, such as checking that the account number is a integer and is 6 digits.

userInterface.cpp/h includes all functions that soley provide output such as outputting account options or transaction options.

menu.cpp/h contains all user menu related functions, allowing the user to choose between multiple options for the main menu, account menu, and transaction menu

Makefile allows for compilation for the compilation of these files in one command.

## How to navigate banking menu
To choose an option from the banking menu, use numbers 1-4 depending on the menu and the choice you would like to make. Make sure to only provide the integer. 