#include <vector>
#include "Product.h"

#ifndef PRODUCTREPOSITORY_H
#define PRODUCTREPOSITORY_H


class ProductRepository {
private:
    vector<const Product*> products;

public:
    void addProduct(const Product* product);
    void displayProducts() const;
    const Product* findProduct(const string& name) const;
    void sellProduct(const string& name);
};

#endif
