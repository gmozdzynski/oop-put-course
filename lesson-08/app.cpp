#include <iostream>
#include <vector>

using namespace std;

class Product {
    int price;
    int productID;
    string productName;

public:
    Product(string _productName, int _price, int _productID) {
        price = _price;
        productID = _productID;
        productName = _productName;
    }

    string showName() const {
        return productName;
    }

    int showPrice() const {
        return price;
    }

    int showID() const {
        return productID;
    }
};

class Customer {
    int customerID;
    string name;
    string email;

public:
    Customer(string _name, string _email, int _customerID) {
        customerID = _customerID;
        name = _name;
        email = _email;
    }

    string showName() const {
        return name;
    }

    int showID() const {
        return customerID;
    }

    string showEmail() const {
        return email;
    }
};

class Order {
    Customer customer;
    vector<Product> products;
    int orderID;

public:
    Order(Customer _customer, int _orderID)
        : customer(_customer), orderID(_orderID) {}

    void addProduct(const Product& product) {
        products.push_back(product);
    }

    int calculateTotalCost() const {
        int orderCost = 0;
        for (const Product& product : products) {
            orderCost += product.showPrice();
        }
        return orderCost;
    }
};

int main() {

    Product product1("Milk", 500, 1);
    Product product2("Chair", 1000, 2);


    Customer customer("Jan Kowalski", "j.kowalski@email.pl", 1);


    Order order(customer, 1);


    order.addProduct(product1);
    order.addProduct(product2);


    int totalCost = order.calculateTotalCost();
    cout << "Total Cost: " << totalCost << endl;

    return 0;
}
