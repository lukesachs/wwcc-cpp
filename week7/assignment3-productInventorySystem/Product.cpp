#include "Product.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

//constructor
Product::Product(const string& id, const string& name, double price, int quantity) 
: id(id), name(name), price(price), quantity(quantity){};

//getters
string Product::getId() const {return id;}
string Product::getName() const {return name;}
double Product::getPrice() const {return price;}
int Product::getQuantity() const {return quantity;}

//setters
void Product::setPrice(double price) {
    if(price > 0){
		this->price = price;
	} else {
		cout << "Price must be more than 0 dollar per item. Setting to 0." << endl;
		this->price = 0;
	}
}

void Product::setQuantity(int quantity) {
    if(quantity > 0){
		this->quantity = quantity;
	} else {
		cout << "Quantity must be more than 0. Setting to 0." << endl;
		this->quantity = 0;
	}
}

void Product::addStock(int add) {
    if(add > 0){
		quantity += add;
	} else {
		cout << "Quantity added must be more than 0." << endl;
	}
}

void Product::setName(string name) {
    if (!name.empty()) {
        this->name = name;
    }
}
void Product::removeStock(int remove) {
    if(remove > 0 && remove <= quantity){
		quantity -= remove;
	} else{
		cout << "Quantity removed be more than 0 and less than or equal to the amount in stock." << endl;
	}
}

void Product::display() const {
    cout << "ID: " << getId() << " | Name: " << getName() << " | Price: $" << getPrice() << " | In Stock: " << getQuantity() << endl;
}


bool checkCinFail() {//checks if user input is correct var type
    if (cin.fail()) {
        cout << "Invalid input! Only numbers allowed." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;
    }
    return false;
}
string newID(){
	
	string ID;
	do{
		cout << "Enter product ID: ";
		cin >> ID;
	} while(ID.empty());
	return ID;
}

string newName(){
	string name;
	cout << "Enter product name: ";
	do{
		getline(cin, name);
	} while(name.empty());
	return name;
}

double newPrice(){
	double price;
	bool check = true;
	do{
		cout << "Enter product price: ";
		cin >> price;
		if(price <= 0){
			cout << "Price must be greater than $0." << endl;
			continue;
		}
	} while(!check);
	return price;
}

int newQuantity(){
	double quantity;
	bool check = true;
	do{
		cout << "Enter initial product quantity: ";
		cin >> quantity;
		if(quantity <= 0){
			cout << "Quantity must be greater than 0." << endl;
			continue;
		}
	} while(!check);
	return quantity;
}
