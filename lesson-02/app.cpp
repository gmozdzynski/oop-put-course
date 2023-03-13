#include <iostream>
#include <string>

class officeObject{
    public:
    std:: string chair;
    std:: string desk;
    std:: string window;
    int quantity;
};

class itObject{
    public:
    std:: string keyboard;
    std:: string monitor;
    std:: string mouse;
};

class houseObjects{
    public:
    std:: string couch;
    std:: string bed;
    std:: string table;

};

int main(){

officeObject firstObject;

firstObject.chair = "chairOne";
firstObject.desk = "tableThree";
firstObject.quantity = 5;

std:: cout << firstObject.chair  << "\n";
std:: cout << firstObject.quantity;
}
