#include <iostream>
#include <string>
#include "Product.h"
#include "ProductRepository.h"



void ProductRepository::addProduct(const Product* product) {
    products.push_back(product);
}

void ProductRepository::displayProducts() const {
    for (const Product* product : products) {
        product->display();
    }
}

const Product* ProductRepository::findProduct(const string& name) const {
    for (const Product* product : products) {
        if (product->showName() == name) {
            return product;
        }
    }
    return nullptr;
}

void ProductRepository::sellProduct(const string& name) {
    auto productIt = std::find_if(products.begin(), products.end(),
        [name](const Product* p) { return p->showName() == name; });

    if (productIt != products.end()) {
        const Product* product = *productIt;
        products.erase(productIt);
    } else {
        throw OutOfStockException("Product not available: " + name);
    }
}


