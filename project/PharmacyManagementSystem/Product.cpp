#include <iostream>
#include <string>
#include "Product.h"
#include "ProductRepository.h"



Product::Product() {}

Product::~Product() {}

Medicine::Medicine(string _type, string _name, double _price, int _id, string _prescriptionRequired) {
    type = _type;
   name = _name;
    price = _price;
    id = _id;
    if(_prescriptionRequired == "YES")
        prescriptionRequired  = 1;
    else
        prescriptionRequired = 0;
}

Medicine::Medicine(string _type, string _name, double _price, int _id) {
 type = _type;
            name = _name;
            price = _price;
            id = _id;
            prescriptionRequired = 0;
}

void Medicine::display() const {
 if(prescriptionRequired)
                cout<<"Product Type: "<<type<<endl<<"Product name: "<<name<<endl<<"Price: "<<price<<endl<<"Id: "<<id<<endl<<"Is prescription required: YES"<<endl;
            else
                cout<<"Product Type: "<<type<<endl<<"Product name: "<<name<<endl<<"Price: "<<price<<endl<<"Id: "<<id<<endl<<"Is prescription required: NO"<<endl;
}

string Medicine::showName() const {
return name;
}

Supplement::Supplement(string _type, string _name, double _price, int _id) {
type = _type;
            name = _name;
            price = _price;
            id = _id;
}

void Supplement::display() const {
cout<<"Product Type: "<<type<<endl<<"Product name: "<<name<<endl<<"Price: "<<price<<endl<<"Id: "<<id<<endl;
}

string Supplement::showName() const {
return name;
}

medicalEquipment::medicalEquipment(string _type, string _name, double _price, int _id) {
            type = _type;
            name = _name;
            price = _price;
            id = _id;

}

void medicalEquipment::display() const {
cout<<"Product Type: "<<type<<endl<<"Product name: "<<name<<endl<<"Price: "<<price<<endl<<"Id: "<<id<<endl;
}

string medicalEquipment::showName() const {
return name;
}

OutOfStockException::OutOfStockException(const string& warning) : runtime_error(warning) {}


