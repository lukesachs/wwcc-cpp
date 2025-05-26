#ifndef PRODUCT_H
#define PRODUCT_H
using namespace std;
#include <iostream>
#include <limits>
#include <string>

class Product {
private:
    string id;
    string name;
    double price;
    int quantity;

public:
    Product(const string& id, const string& name, double price, int quantity);

    string getId() const;
    string getName() const;
    double getPrice() const;
    int getQuantity() const;



    void setPrice(double p);
    void setQuantity(int q);
	void setName(string name);
    void addStock(int a);
    void removeStock(int a);

    void display() const;
};

//I wasn't sure where to put this so I figured I would throw it where it is called to all the other files.
bool checkCinFail();//checks if user input is correct var type
string newID();
string newName();
double newPrice();
int newQuantity();

#endif // PRODUCT_H