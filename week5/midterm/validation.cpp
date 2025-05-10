#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "validation.h"
#include "userInterface.h"
using namespace std;



bool checkNewID(int accountNumber) {
    if (checkCinFail()) { 
        return false;
    } else if (accountNumber < 100000 || accountNumber > 999999) {
        cout << "Invalid input! Account number must be 6 digits." << endl;
        return false;
    } else {
        return true;
    }
}

bool checkAccountName(string holderName) {
    if (holderName.empty() || holderName.find(" ") == string::npos) {
        return false;
    }

    // Checks if the space is at the correct position
    if (holderName.find(" ") == 0 || holderName.find(" ") == holderName.length() - 1) {
        return false;
    }

    // Checks if there is more than one space
    if (holderName.find("  ") != string::npos) {
        return false; // Multiple spaces between words
    }

    return true;
}

bool checkBalance(double accountBalance) {
    if (checkCinFail()) { 
        return false;
    } else if (accountBalance < 0) {
        cout << "Invalid input! Balance cannot be negative." << endl;
        return false;
    } else {
        return true;
    }
}

bool mainMenuValid(int option){
    if (checkCinFail()) { 
        return false;
    } else if(option < 1 || option > 4){
        cout << "Invalid Input! Must input 1, 2, 3, or 4." << endl;
        return false;
    } else {
        return true;
    }
}

bool transactionMenuValid(int option){
    if (checkCinFail()) { 
        return false;
    } else if(option < 1 || option > 3){
        cout << "Invalid Input! Must input 1, 2, or 3." << endl;
        return false;
    } else {
        return true;
    }
}
bool accountMenuValid(int option){
    if (checkCinFail()) { 
        return false;
    } else if(option < 1 || option > 3){
        cout << "Invalid Input! Must input 1, 2, or 3." << endl;
        return false;
    } else {
        return true;
    }
}

bool confirmID(int ID, const vector<Account> &account, int &index){
    if (checkCinFail()) { 
        return false;
    } else if (ID < 100000 || ID > 999999) {
        cout << "Invalid input! Account number must be 6 digits." << endl;
        return false;
    }
    for(int i = 0; i < (int) account.size(); i++){
        if(ID == account[i].accountNumber){
            index = i;
            return true;
        }
    }
    cout << "Invalid input! ID number not found." << endl;
    return false;
}

bool checkTransaction(double amount, const Account &account, int index) {
    //index variable type change to be able to compare to account.history.size.
    if (index < 0 || static_cast<vector<Transaction>::size_type>(index) >= account.history.size()) {
        cout << "Invalid transaction history index." << endl;
        return false;
    }
    string transactionType = account.history[index].type;
    if (checkCinFail()) { 
        return false;
    } else if (amount < 0) {
        cout << "Invalid input! Transaction amount cannot be negative." << endl;
        return false;
    }
    if((transactionType == "transfer" || transactionType == "withdrawal") && amount > account.balance){
        cout << "Insufficient funds. Transaction failed!" << endl;
        return false;
    }
    return true;
}

bool checkCinFail() {
    if (cin.fail()) {
        cout << "Invalid input! Only numbers allowed." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;
    }
    return false;
}
bool checkDate(int day, int month, int year, const Account &account){
    const int calander[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};
    if(day < 1 || day > calander[month - 1]){
        cout << "Invalid Input! Month must be 1-12." << endl;
        return false;
    }
    if(day > calander[month] || day < 0){
        cout << "Invalid Input! Day must be between 1-31 depending on month." << endl;
        return false;
    }
    if(year < 1983){
        cout << "Invalid Input! Year must be after the creation of the at home banking system (1983)." << endl;
        return false;
    }
    if(account.transactionCount == 0){
        return true;
    }
    int prevYear = account.history[account.transactionCount].date.year;
    int prevMonth = account.history[account.transactionCount].date.month;
    int prevDay = account.history[account.transactionCount].date.day;

    if(account.history[account.transactionCount].date.year > year){
        return true;
    } else if(prevYear == year){
        if(prevMonth < month){
            return true;
        } else if(prevMonth == month && prevDay < day) {
            return true;
        }
    }
    cout << "Invalid Input! Date must be later than previous transaction!" << endl;
    displayDate(account.history[account.transactionCount].date);
    cout << endl;
    return false;

}
bool checkDate(int day, int month, int year, const Account &to, const Account &from){
    const int calander[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};
    if(month > 12 || month < 0){
        cout << "Invalid Input! Month must be 1-12." << endl;
        return false;
    }
    if(day < 1 || day > calander[month - 1]){
        cout << "Invalid Input! Day must be between 1-31 depending on month." << endl;
        return false;
    }
    if(year < 1983){
        cout << "Invalid Input! Year must be after the creation of the at home banking system (1983)." << endl;
        return false;
    }
    if(to.transactionCount == 0 && from.transactionCount == 0){
        return true;
    }
    int prevYear = from.history[from.transactionCount].date.year;
    int prevMonth = from.history[from.transactionCount].date.month;
    int prevDay = from.history[from.transactionCount].date.day;

    int prevYear2 = to.history[to.transactionCount].date.year;
    int prevMonth2 = to.history[to.transactionCount].date.month;
    int prevDay2 = to.history[to.transactionCount].date.day;

    if(to.history[to.transactionCount].date.year < year && from.history[from.transactionCount].date.year < year){
        return true;
    } else if(prevYear == year && year > to.history[to.transactionCount].date.year < year){
        if(prevMonth < month){
            return true;
        } else if(prevMonth == month && prevDay < day) {
            return true;
        }
    } else if(prevYear2 == year && year > from.history[from.transactionCount].date.year < year){
        if(prevMonth2 < month){
            return true;
        } else if(prevMonth2 == month && prevDay2 < day) {
            return true;
        }
    } else if(prevYear == year && prevYear2 == year){
        if(prevMonth < month && prevMonth2 < month){
            return true;
        } else if((prevMonth == month && prevDay < day) && (prevMonth2 < month)) {//To transaction in same month
            return true;
        } else if((prevMonth2 == month && prevDay2 < day) && (prevMonth == month)) {//From transaction in same month
            return true;
        } else if((prevMonth == month && prevDay < day) && (prevMonth2 == month && prevDay2 < day)) {//both same month
            return true;
        }
    }
    cout << "Invalid Input! Date must be later than previous transaction of both accounts!" << endl;
    displayDate(to.history[to.transactionCount].date);
    displayDate(from.history[from.transactionCount].date);
    cout << endl;
    return false;

}