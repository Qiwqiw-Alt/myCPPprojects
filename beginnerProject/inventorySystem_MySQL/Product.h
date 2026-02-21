#ifndef INVENTORYSYSTEM_MYSQL_PRODUCT_H
#define INVENTORYSYSTEM_MYSQL_PRODUCT_H
#include <string>
using namespace std;

class Product {
private:
    string id;
    string name;
    string category;

    double volume;
    int quantity;
    long long price;
public:
    Product();

    Product(const string &id, const string &name, const string &category, double volume, int quantity, long long price);

    void setId(const string& id);
    void setName(const string& name);
    void setCategory(const string& category);
    void setVolume(double volume);
    void setQuantity(int quantity);
    void setPrice(long long price);

    [[nodiscard]] string getId() const;
    [[nodiscard]] string getName() const;
    [[nodiscard]] string getCategory() const;
    [[nodiscard]] double getVolume() const;
    [[nodiscard]] int getQuantity() const;
    [[nodiscard]] long long getPrice() const;

};
#endif //INVENTORYSYSTEM_MYSQL_PRODUCT_H