#ifndef INVENTORY_H
#define INVENTORY_H

#include "Product.h"
#include <string>
#include <vector>
using namespace std;

class Inventory {
private:
    vector<Product> products;

	static const int LOW_STOCK;

public:
    void addProduct();
    void removeProduct(int index);

    Product* findById(const string& id);
    Product* findByName(const string& name);

    void listAllProducts() const;
    void listOutOfStock() const;
    void listLowStock() const;

    bool updateProduct(const string& id);
    double inventoryValue() const;
    int totalProducts() const;
};

#endif // INVENTORY_H