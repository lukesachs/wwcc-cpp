#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

double dollarToEuro(double amount);
double dollarToPound(double amount);
double dollarToYen(double amount);
int getConversionCount();

int main() {
    char again = 'y';
    int num;
    double amount;
    bool check;
    do {
        cout << "CURRENCY CONVERTER" << endl;
        cout << "------------------" << endl;
        cout << "1. Convert USD to Euro (EUR)" << endl;
        cout << "2. Convert USD to British Pound (GBP)" << endl;
        cout << "3. Convert USD to Japanese Yen (JPY)" << endl;
        cout << "4. Exit" << endl;

        cout << "\nEnter your choice (1-4): ";
        cin >> num;
        if (num != 4){
            cout << "\nEnter amount in USD: ";
            cin >> amount;
        }
        switch(num) {
            case 4:
            again = 'n';
            break;
            case 1:
                cout << amount << " USD = " << dollarToEuro(amount) << " EUR" << endl;
                cout << "Number of conversions performed: " << getConversionCount() << endl;
                break;
            case 2:
                cout << amount << " USD = " << dollarToPound(amount) << " GBP" << endl;
                cout << "Number of conversions performed: " << getConversionCount() << endl;
                break;
            case 3:
                cout << amount << " USD = " << dollarToYen(amount) << " JPY" << endl;
                cout << "\nNumber of conversions performed: " << getConversionCount() << endl;
                break;
            default: 
                cout << "Error: incorrect input.\n Must enter a number 1-4";
        }
        if (num != 4){
            do{
            cout << "\nWould you like to perform another conversion? (y/n): ";
            cin >> again;
                if(again != 'y' && again != 'n'){
                    cout << "\nError: incorrect input.\nMust enter y or n.";

                } 
            } while(again != 'y' && again != 'n');
            cout << endl;
        }

    } while(again == 'y');
    
    cout << "Thank you for using the Currency Converter!";

}

int getConversionCount(){
    static int count = 0;
    count++;
    return count;
}

double dollarToEuro(double amount){
    amount = amount * 0.85;
    stringstream sstr;
    sstr << fixed << setprecision(2) << amount;
    return stod(sstr.str());
}

double dollarToPound(double amount){
    amount = amount * 0.74;
    stringstream sstr;
    sstr << fixed << setprecision(2) << amount;
    return stod(sstr.str());
}

double dollarToYen(double amount){
    amount = amount * 110.33;
    stringstream sstr;
    sstr << fixed << setprecision(2) << amount;
    return stod(sstr.str());
}