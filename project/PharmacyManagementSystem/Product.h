
#include <string>

#ifndef PRODUCT_H
#define PRODUCT_H

using namespace std;

class Product {
protected:
    string type;
    string name;
    double price;
    int id;

public:
    Product();
    virtual ~Product();
    virtual void display() const = 0;
    virtual string showName() const = 0;
};

class Medicine : public Product {
private:
    bool prescriptionRequired;

public:
    Medicine(string _type, string _name, double _price, int _id, string _prescriptionRequired);
    Medicine(string _type, string _name, double _price, int _id);
    void display() const override;
    string showName() const override;
};

class Supplement : public Product {
public:
    Supplement(string _type, string _name, double _price, int _id);
    void display() const override;
    string showName() const override;
};

class medicalEquipment : public Product {
public:
    medicalEquipment(string _type, string _name, double _price, int _id);
    void display() const override;
    string showName() const override;
};

class OutOfStockException : public runtime_error {
public:
    OutOfStockException(const string& warning);
};

#endif

