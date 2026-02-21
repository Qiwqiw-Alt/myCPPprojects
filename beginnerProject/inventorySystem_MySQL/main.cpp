#include <iostream>
#include <string>
#include <vector>
#include <format>
#include "Product.h"
#include "Database.h"

using namespace std;

vector<Product> inventory;
Database db;

void initialDisplay();
void showAllProduct();
void addProduct();
void showProductDetail();
void updateProductDetail();
void removeProduct();
void readData();
void writeDataAppend(const Product& st);
string idGenerator();
void syncUpdateToDB(const Product& pr);
void syncRemoveFromDB(const string& id);

int main() {
    readData();

    initialDisplay();

    return 0;
}

void initialDisplay() {
    int choice = -1;

    do {
        showAllProduct();
        cout << "\n=================== Welcome to Inventory Database Management ====================\n";
        cout << "(1) Add new product" << endl;
        cout << "(2) Show Product Details" << endl;
        cout << "(3) Update Product Details" << endl;
        cout << "(4) Remove Product" << endl;
        cout << "(0) Exit" << endl;
        cout << "Enter your choice: "; cin >> choice;

        switch (choice) {
            case 1: addProduct(); break;
            case 2: showProductDetail(); break;
            case 3: updateProductDetail(); break;
            case 4: removeProduct(); break;
            case 0: cout << "Exiting..." << endl; break;
            default: cout << "Please select the available choice!"; break;
        }
    } while (choice != 0);
}

void showAllProduct() {
    cout << "================================ Students List ================================\n";
    for (int i = 0; i < inventory.size(); i++) {
        cout << format("{}. {:<6} | {:<15} | {:<15} | {} | Rp {}\n", i + 1,
            inventory[i].getId(), inventory[i].getName(), inventory[i].getCategory(), inventory[i].getQuantity(), inventory[i].getPrice());
    }
    cout << "===============================================================================" << endl;
}

void addProduct() {
    string name, category;
    double volume;
    int quantity;
    long long price;

    char addAnotherProduct;

    do {
        string id = idGenerator();
        cout << "\n============================ Add new product menu =============================\n";
        cout << "Enter product name: "; getline(cin >> ws, name);
        cout << "Enter product category: "; getline(cin >> ws, category);
        do {
            cout << "Enter product weight/volume: "; cin >> volume;
            if (volume < 1) {
                cout << "Please enter the positive number!" << endl;
            }
        } while (volume < 1);
        do {
            cout << "Enter product quantity: "; cin >> quantity;
            if (quantity < 1) {
                cout << "Please enter the positive number!" << endl;
            }
        } while (quantity < 1);
        do {
            cout << "Enter product price: "; cin >> price;
            if (price < 1) {
                cout << "Please enter the positive number!" << endl;
            }
        } while (price < 1);

        Product newProduct = Product(id, name, category, volume, quantity, price);
        inventory.push_back(newProduct);
        writeDataAppend(newProduct);

        cout << "Want to add another product? (y/n): "; cin >> addAnotherProduct;
    } while (addAnotherProduct == 'y' || addAnotherProduct == 'Y');
}

void showProductDetail() {
    int maxProduct = inventory.size();
    int productSerialNumber = -1;

    char showAnotherProduct;

    do {
        cout << "\n========================== Show product detail menu ==========================\n";
        showAllProduct();
        do {
            cout << "Enter the product serial number:"; cin >> productSerialNumber;
            if (productSerialNumber - 1 < 0 || productSerialNumber - 1 > maxProduct - 1) {
                cout << "Please enter valid product serial number!" << endl;
            } else {
                const Product& prSelected = inventory[productSerialNumber - 1];
                cout << "(1) Id          : " << prSelected.getId() << endl;
                cout << "(2) Name        : " << prSelected.getName() << endl;
                cout << "(3) Category    : " << prSelected.getCategory() << endl;
                cout << "(4) Wight/Volume: " << prSelected.getVolume() <<  " Kg/L"<< endl;
                cout << "(5) Quantity    : " << prSelected.getQuantity() << endl;
                cout << "(6) Price       : Rp" << prSelected.getPrice() << endl;
            }

        } while (productSerialNumber - 1 < 0 || productSerialNumber - 1 > maxProduct - 1);
        cout << "Want to see another product detail? (y/n): "; cin >> showAnotherProduct;
    } while (showAnotherProduct == 'y' || showAnotherProduct == 'Y');
}

void updateProductDetail() {
    const int maxProduct= inventory.size();
    int productSerialNumber = -1;
    int detailNumber = -1;

    char updateAnotherProduct;

    do {
        cout << "\n========================== Update product detail menu =========================\n";
        showAllProduct();

        string name, category;
        double volume;
        int quantity;
        long long price;


        do {
            cout << "Enter the product serial number:"; cin >> productSerialNumber;
            if (productSerialNumber - 1 < 0 || productSerialNumber - 1 > maxProduct - 1) {
                cout << "Please enter valid product serial number!" << endl;
            } else {
                Product &prSelected = inventory[productSerialNumber - 1];
                cout << "(1) Name        : " << prSelected.getName() << endl;
                cout << "(2) Category    : " << prSelected.getCategory() << endl;
                cout << "(3) Wight/Volume: " << prSelected.getVolume() <<  " Kg/L"<< endl;
                cout << "(4) Quantity    : " << prSelected.getQuantity() << endl;
                cout << "(5) Price       : Rp" << prSelected.getPrice() << endl;
                cout << "(0) Cancel" << endl;
                do {
                    cout << "Enter the detail you want to change: "; cin >> detailNumber;

                    switch (detailNumber) {
                        case 0:
                            return;
                        case 1:
                            cout << "Enter new name: "; getline(cin >> ws, name);
                            prSelected.setName(name);
                            syncUpdateToDB(prSelected);
                            break;
                        case 2:
                            cout << "Enter new category: "; getline(cin >> ws, category);
                            prSelected.setCategory(category);
                            syncUpdateToDB(prSelected);
                        case 3:
                            cout << "Enter new wight/volume: "; cin >> volume;
                            prSelected.setVolume(volume);
                            syncUpdateToDB(prSelected);
                            break;
                        case 4:
                            cout << "Enter new quantity: "; cin >> quantity;
                            prSelected.setQuantity(quantity);
                            syncUpdateToDB(prSelected);
                            break;
                        case 5:
                            cout << "Enter new Price: Rp "; cin >> price;
                            prSelected.setPrice(price);
                            syncUpdateToDB(prSelected);
                            break;
                        default:
                            cout << "Please select the correct detail number!";
                            break;
                    }
                } while (detailNumber < 0 || detailNumber > 4);
            }

        } while (productSerialNumber - 1 < 0 || productSerialNumber - 1 > maxProduct - 1);
        cout << "Want to update another product detail? (y/n): "; cin >> updateAnotherProduct;
    } while (updateAnotherProduct == 'y' || updateAnotherProduct == 'Y');
}

void removeProduct() {
    int maxProduct = inventory.size();
    int productSerialNumber = -1;

    char removeAnotherProduct;

    do {
        cout << "\n============================ Remove product menu =============================\n";
        showAllProduct();
        do {
            cout << "Enter the product serial number:"; cin >> productSerialNumber;
            if (productSerialNumber - 1 < 0 || productSerialNumber - 1 > maxProduct - 1) {
                cout << "Please enter valid product serial number!" << endl;
            } else {
                cout << format("Product with id {} removed", inventory[productSerialNumber - 1].getId()) << endl;;
                inventory.erase(inventory.begin() + productSerialNumber - 1);
                syncRemoveFromDB(inventory[productSerialNumber - 1].getId());
            }

        } while (productSerialNumber - 1 < 0 || productSerialNumber - 1 > maxProduct - 1);
        cout << "Want to remove another product? (y/n): "; cin >> removeAnotherProduct;
    } while (removeAnotherProduct == 'y' || removeAnotherProduct == 'Y');
}

void readData() {
    inventory.clear();
    if (!db.isConnected()) return;

    try {
        sql::Statement *stmt = db.getConnection()->createStatement();
        sql::ResultSet *res = stmt->executeQuery("SELECT * FROM inventory");

        while (res->next()) {
            Product pr(
                res->getString("id"),
                res->getString("name"),
                res->getString("category"),
                res->getDouble("volume"),
                res->getInt("quality"),
                res->getInt("price")
            );

            inventory.push_back(pr);
        }
        delete res;
        delete stmt;
    } catch (sql::SQLException& e) {
        cout << "Error!: " << e.what() << endl;
    }
}

void writeDataAppend(const Product &st) {
    if (!db.isConnected()) return;

    try {
        sql::PreparedStatement *pstmt = db.getConnection()->prepareStatement(
            "INSERT INTO inventory(id, name, category, volume, quantity, price) VALUES (?, ?, ?, ?, ?, ?)"
        );

        pstmt->setString(1, st.getId());
        pstmt->setString(2, st.getName());
        pstmt->setString(3, st.getCategory());
        pstmt->setDouble(4, st.getVolume());
        pstmt->setInt(5, st.getQuantity());
        pstmt->setInt(6, st.getPrice());

        pstmt->executeUpdate();
        delete pstmt;
    } catch (sql::SQLException& e) {
        cout << "Error!: " << e.what() << endl;
    }
}

string idGenerator() {
    int max = 0;
    for (const Product& pr: inventory) {
        try {
            string idStr = pr.getId().substr(2);
            if (int num = stoi(idStr); num > max) {
                max = num;
            }
        } catch (exception e) {
            cout << e.what() << endl;
        }
    }

    return format("PR{:03}", max + 1);
}

void syncUpdateToDB(const Product& pr) {
    if (!db.isConnected()) return;

    try {
        sql::PreparedStatement *pstmt = db.getConnection()->prepareStatement(
            "UPDATE inventory SET name=?, category=?, volume=?, quantity=?, price=?, WHERE id=?"
        );

        pstmt->setString(1, pr.getName());
        pstmt->setString(2, pr.getCategory());
        pstmt->setDouble(3, pr.getVolume());
        pstmt->setInt(4, pr.getQuantity());
        pstmt->setInt(5, pr.getPrice());
        pstmt->setString(6, pr.getId());

        pstmt->executeUpdate();
        delete pstmt;
    } catch (sql::SQLException& e) {
        cout << "Error!: " << e.what() << endl;
    }
}

void syncRemoveFromDB(const string& id) {
    if (!db.isConnected()) return;

    try {
        sql::PreparedStatement *pstmt = db.getConnection()->prepareStatement(
          "DELETE FROM inventory WHERE id=?"
        );
        pstmt->setString(1, id);

        pstmt->executeUpdate();
    } catch (sql::SQLException& e) {
        cout << "Error!: " << e.what() << endl;
    }
}