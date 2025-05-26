#include "Inventory.h"
#include "Product.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


const int Inventory::LOW_STOCK = 5;

void Inventory::addProduct() {
	string id = newID();
	string name = newName();
	double price = newPrice();
	int quantity = newQuantity();
    Product p(id, name, price, quantity);
	products.push_back(p);
	cout << "Product added successfully!" << endl;
}

void Inventory::removeProduct(int index) {
	products.erase(products.begin() + index);
}

Product* Inventory::findById(const std::string& id) {
    string temp = id;
	transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
	for(int i = 0; i < products.size(); i++){
		string temp2 = products[i].getId();
		transform(temp2.begin(), temp2.end(), temp2.begin(), ::tolower);
		if(temp2 == temp){
			return &products[i];
		}
	}
    return nullptr;
}

Product* Inventory::findByName(const string& name) {
    string temp = name;
	transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
	for(int i = 0; i < products.size(); i++){
		string temp2 = products[i].getName();
		transform(temp2.begin(), temp2.end(), temp2.begin(), ::tolower);
		if(temp2 == temp){
			return &products[i];
		}
	}
    return nullptr;
}

void Inventory::listAllProducts() const {
    cout << "ALL PRODUCTS" << endl;
	cout << "-----------" << endl;
	for(int i = 0; i< products.size(); i++){
		products[i].display();
	}
}

void Inventory::listOutOfStock() const {
	vector<int> n;
    for(int i = 0; i< products.size(); i++){//find all out of stock products
		if(products[i].getQuantity() == 0){
			n.push_back(i);
		}
	}
	cout << "Out of stock products: " << n.size() << endl;
	for(int i = 0; i< n.size(); i++){
		products[n[i]].display();
	}
}

void Inventory::listLowStock() const {
    vector<int> n;
    for(int i = 0; i< products.size(); i++){//find all low stock products
		int q = products[i].getQuantity();
		if (q > 0 && q <= LOW_STOCK){
			n.push_back(i);
		}
	}
	cout << "Low stock products (" << LOW_STOCK << " or fewer): " << n.size() << endl;
	for(int i = 0; i< n.size(); i++){
		products[n[i]].display();
	}
}

bool Inventory::updateProduct(const string& id) {
	int choice;
    Product* product = findById(id);
	if (product) {
		do{
			cout << "1. Update product info.\n2. Delete product from system." << endl;
			cin >> choice;
			if(checkCinFail()){
				continue;
			}
		} while(!(choice == 1 || choice == 2));
		switch(choice){
		case 1:{
			string newName;
			double newPrice;
			int newQuantity;
			cout << "Enter new name: ";
			cin.ignore();
			getline(cin, newName);
			cout << "Enter new price: ";
			cin >> newPrice;
			cout << "Enter new quantity: ";
			cin >> newQuantity;
			cin.ignore();
			product->setName(newName);
			product->setPrice(newPrice);
			product->setQuantity(newQuantity);
			return true;
			break;
		}
		case 2:{
			string temp = id;
			transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
			for(int i = 0; i < products.size(); i++){
				string temp2 = products[i].getId();
				transform(temp2.begin(), temp2.end(), temp2.begin(), ::tolower);
				if(temp2 == temp){
					removeProduct(i);
					break;
				}
			}
			
			break;
		}
		default:
			cout << "ERROR" << endl;
			break;
		}
	}
	return false;
}

double Inventory::inventoryValue() const {
    double total = 0.0;
	for(int i = 0; i< products.size(); i++){
		total += products[i].getQuantity() * products[i].getPrice();
	}
    return total;
}

int Inventory::totalProducts() const {
    int t = 0;
	t = products.size();
    return t;
}

