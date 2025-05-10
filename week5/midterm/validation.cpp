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

bool checkTransaction(double amount, const Account &account, const std::string &type){
    if (checkCinFail()) {
        return false;
    } else if (amount < 0) {
        cout << "Invalid input! Transaction amount cannot be negative." << endl;
        return false;
    }

    if ((type == "transfer" || type == "withdrawal") && amount > account.balance){
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
    static const int calander[] = {31,29,31,30,31,30,31,31,30,31,30,31};

    if (month < 1 || month > 12) {
        cout << "Invalid Input! Month must be 1-12." << endl;
        return false;
    }

    int maxDay = calander[month - 1];

    if (day < 1 || day > maxDay) {
        cout << "Invalid Input! Day must be between 1 and "
             << maxDay << " for month " << month << "." << endl;
        return false;
    }
    if (year < 1983) {
        cout << "Invalid Input! Year must be 1983 or later." << endl;
        return false;
    }
    if (account.transactionCount == 0) {
        return true;
    }

    int lastIndex = account.transactionCount - 1;
    const Date &prev = account.history[lastIndex].date;

    if (year > prev.year || (year == prev.year && month > prev.month) || (year == prev.year && month == prev.month && day > prev.day)){
        return true;
    }

    cout << "Invalid Input! Date must be later than previous transaction on ";
    displayDate(prev);
    cout << "." << endl;
    return false;
}

bool checkDate(int day, int month, int year, const Account &to, const Account &from){
    const int calander[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};
    if(month > 12 || month < 1){
        cout << "Invalid Input! Month must be 1-12." << endl;
        return false;
    }

    int maxDay = calander[month - 1];

    if(day < 1 || day > maxDay){
        cout << "Invalid Input! Day must be between 1-" << maxDay << " for " << month << "." << endl;
        return false;
    }
    if(year < 1983){
        cout << "Invalid Input! Year must be after the creation of the at home banking system (1983)." << endl;
        return false;
    }
    if(to.transactionCount == 0 && from.transactionCount == 0){
        return true;
    }
    int lastIndex = from.transactionCount - 1;
    int prevYear = from.history[lastIndex].date.year;
    int prevMonth = from.history[lastIndex].date.month;
    int prevDay = from.history[lastIndex].date.day;

    int lastIndex2 = to.transactionCount - 1;
    int prevYear2 = to.history[lastIndex2].date.year;
    int prevMonth2 = to.history[lastIndex2].date.month;
    int prevDay2 = to.history[lastIndex2].date.day;

    if(to.history[lastIndex2].date.year < year && from.history[lastIndex].date.year < year){
        return true;
    } else if(prevYear == year && to.history[lastIndex2].date.year < year){
        if(prevMonth < month){
            return true;
        } else if(prevMonth == month && prevDay < day) {
            return true;
        }
    } else if(prevYear2 == year && from.history[lastIndex].date.year < year){
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
    displayDate(to.history[lastIndex2].date);
    displayDate(from.history[lastIndex].date);
    cout << endl;
    return false;

}