#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include "Product.h"
#include "Inventory.h"
using namespace std;

void displayMainMenuOptions();
bool mainMenuValid(int option);
void mainMenuInput(int option, Inventory &inventory);

// Main function
int main() {
    

    cout << std::fixed << std::setprecision(2); //so doubles dont display as scientific notation and only 2 decimals

	Inventory inventory;
    int option = 0;
    do{
        displayMainMenuOptions();
		cout << endl;
		cout << "Enter your choice: ";
        cin >> option;
        if(!mainMenuValid(option)){//loops main menu input if not valid
           continue;
        }
        mainMenuInput(option, inventory);
		cout << endl;
    } while(option != 8);//ends program if option 8 is selected

    return 0;
}



bool mainMenuValid(int option){
    if (checkCinFail()) { 
        return false;
    } else if(option < 1 || option > 8) {
        cout << "Invalid Input! Must input 1-8." << endl;
        return false;
    } else {
        return true;
    }
}


void displayMainMenuOptions(){
    cout << "\nMAIN MENU:" << endl;
    cout << "1. Add New Product" << endl;
    cout << "2. Display All Products" << endl;
    cout << "3. Search for a Product" << endl;
	cout << "4. Update Product" << endl;
	cout << "5. Add Stock" << endl;
    cout << "6. Remove Stock" << endl;
	cout << "7. Display Inventory Statistics" << endl;
    cout << "8. Exit" << endl;
}

void mainMenuInput(int option, Inventory &inventory){
	
    switch(option) {
    case 1: {//add product
		cout << "ADD NEW PRODUCT" << endl;
		cout << "--------------" << endl;
		inventory.addProduct();
        break;
	}
    case 2: {//display all products
		inventory.listAllProducts();
		break;
	}
    case 3: {//search for product
		string searchInput;
		cout << "Enter product Name or ID: ";
		cin >> searchInput;
		Product* isThere = inventory.findById(searchInput);
		if(!isThere){
			isThere = inventory.findByName(searchInput);
		}
		if(isThere){
			isThere->display();
		} else{
			cout << "\"" << searchInput << "\" not found." << endl;
		}
        break;
	}
    case 4: {//update product
		cout << "Enter ID of product to update: ";
		string productInput;
		cin >> productInput;
		inventory.updateProduct(productInput);
        break;
	}
    case 5: {//add stock
		string id;
		int amount;
		cout << "Enter product ID to add stock: ";
		cin >> id;
		Product* isThere = inventory.findById(id);
		if (!isThere) {
			cout << "Product not found." << endl;
			break;
		}
		cout << "Enter quantity to add: ";
		cin >> amount;
		if (!checkCinFail()) {
			isThere->addStock(amount);
			cout << "Stock added." << endl;
		} else {
			cout << "Invalid quantity." << endl;
		}
        break;
	}
    case 6: {//remove stock
		string id2;
		int amount;
		cout << "Enter product ID to remove stock: ";
		cin >> id2;
		Product* isThere = inventory.findById(id2);
		if (!isThere) {
			cout << "Product not found." << endl;
			break;
		}
		cout << "Enter quantity to remove: ";
		cin >> amount;
		if (!checkCinFail()) {
			isThere->removeStock(amount);
			cout << "Stock removed." << endl;
		} else {
			cout << "Invalid quantity." << endl;
		}
        break;
	}
    case 7: {//display inventory stats
		cout << "INVENTORY STATISTICS" << endl;
		cout << "-------------------" << endl;
		cout << "Total number of products: " << inventory.totalProducts() << endl;
		cout << "Total inventory Value: $" << inventory.inventoryValue() << endl;
		inventory.listOutOfStock();
		inventory.listLowStock();
        break;
	}
    case 8: {//exit program
        cout << "Thank you for using the Product Inventory System. Goodbye!" << endl;
        break;
	}
    default:
        cout << "ERROR" << endl;
        break;
    }
}