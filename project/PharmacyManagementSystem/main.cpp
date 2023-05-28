#include <iostream>
#include <string>
#include "Product.h"
#include "ProductRepository.h"

using namespace std;

int main() {
    ProductRepository warehouse;
    int choice, productType;

    do {
        cout << "________MENU________" << endl;
        cout << "1: Add product" << endl;
        cout << "2: Find product" << endl;
        cout << "3: Display all products" << endl;
        cout << "4: Sell product" << endl;
        cout << "5: Finish program" << endl;
        cout << "Enter choice:" << endl;
        cin >> choice;
        switch (choice) {
            case 1: {
                string type, name;
                float price;
                int id;
                int pType;
                cout << "Enter product type" << endl;
                cout << "1: Medicine" << endl;
                cout << "2: Supplement" << endl;
                cout << "3: Medical equipment" << endl;
                cin >> pType;
                cout << "Enter product name:" << endl;
                cin >> name;
                cout << "Enter price:" << endl;
                cin >> price;
                cout << "Enter product Id:" << endl;
                cin >> id;
                switch (pType) {
                    case 1: {
                        string prescriptionRequired;
                        type = "Med";
                        cout << "Is prescription required, enter: YES/NO" << endl;
                        cin >> prescriptionRequired;
                        if (prescriptionRequired == "YES") {
                            warehouse.addProduct(new Medicine(type, name, price, id, "YES"));
                        } else if (prescriptionRequired == "NO") {
                            warehouse.addProduct(new Medicine(type, name, price, id, "NO"));
                        } else {
                            warehouse.addProduct(new Medicine(type, name, price, id));
                        }
                        break;
                    }
                    case 2: {
                        type = "Supl";
                        warehouse.addProduct(new Supplement(type, name, price, id));
                        break;
                    }
                    case 3: {
                        type = "MEq";
                        warehouse.addProduct(new medicalEquipment(type, name, price, id));
                        break;
                    }
                    default:
                        cout << "Invalid type!" << endl;
                        break;
                }
                break;
            }
            case 2: {
                string name;
                cout << "Enter the name of the product to find: ";
                cin >> name;
                const Product* foundProduct = warehouse.findProduct(name);
                if (foundProduct != nullptr) {
                    cout << "Product present in warehouse:" << endl;
                    foundProduct->display();
                } else {
                    cout << "Product not found!" << endl;
                }
                break;
            }
            case 3:
                cout << "Products in warehouse:" << endl;
                warehouse.displayProducts();
                break;
            case 4: {
                string name;
                cout << "Enter the name of the product you want to sell:" << endl;
                cin >> name;
                try {
                    warehouse.sellProduct(name);
                    cout << "Product sold successfully." << endl;
                } catch (const OutOfStockException& ex) {
                     cout << "Error: " << ex.what() << endl;
                }
                break;
            }
        }
    } while (choice != 5);

    return 0;
}
