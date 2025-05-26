//Adding nessecary librarys
#include <iostream>
#include <string>

using namespace std;

// A class for managing a bank account
class Account {//capitalized account
private:
    string customerName;
    double funds;
    bool isActive;
    int accountNumber;
    string accountType;
	//made interest rates const ints
	const int SAVINGS_INTREST = 1.03;
	const int CHECKING_INTREST = 1.01;
	const int BUISNESS_INTREST = 1.005;
//I renamed many variables and functions to better convey their function
public:
//constructor
	Account(const string& n, int num, const string& t) : customerName(n), accountNumber(num), accountType(t){
		setFunds(0.0);
		setActivityStatus(true);
	};


	//added getters for all private vars.
    double getFunds() const {return funds;}
	string getCustomerName() const {return customerName;}
	bool getActiveStatus() const {return isActive;}
	int getAccountNumber() const {return accountNumber;}
	string getAccountType() const {return accountType;}
    
	void setFunds(double funds){
		if(funds >= 0){
			this->funds = funds;
		}
	}

	void setActivityStatus(bool isActive){
		this->isActive = isActive;
	}

	void deposit(double x) {
		if(isActive && x > 0){//checks if active
        	this->funds = funds + x;
		}
    }

    void withdraw(double x) {
		if(isActive && x > 0 && x < funds){//checks if active and that enought funds exist to withdraw
        	this->funds = funds - x;
		}
	}

    void addIntrest() {
		if(isActive){//checks if active
			if (accountType == "Savings") {
				funds = funds * SAVINGS_INTREST;
			} else if (accountType == "Checking") {
				funds = funds * CHECKING_INTREST;
			} else if (accountType == "Business") {
				funds = funds * BUISNESS_INTREST;
			}
		}
    }

    void printAccountDetails() const {
        cout << "Account Number: " << getAccountNumber() << endl;
        cout << "Customer Name: " << getCustomerName() << endl;
        cout << "Balance: $" << getFunds() << endl;
        cout << "Account Type: " << getAccountType() << endl;
        cout << "Status: " << (isActive ? "Open" : "Closed") << endl;
    }

    void close() {
        isActive = false;
    }
};

int main() {
    // Create an account
    Account acc1("John Smith", 12345, "Savings");

    // Perform operations
    acc1.deposit(1000);
    acc1.withdraw(250);
    acc1.addIntrest();

    // Display information
    acc1.printAccountDetails();

    // Close the account
    acc1.close();

    return 0;
}