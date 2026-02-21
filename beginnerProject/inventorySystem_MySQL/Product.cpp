#include "Product.h"
#include <string>
using namespace std;

Product::Product() {
    this->id = "unkown";
    this->name = "unkown";
    this->category = "unknown";
    this->volume = 0;
    this->quantity = 0;
    this->price = 0;
}

Product::Product(const string &id, const string &name, const string &category, const double volume, const int quantity, const long long price) {
    this->id = id;
    this->name = name;
    this->category = category;
    this->volume = volume;
    this->quantity = quantity;
    this->price = price;
}

void Product::setId(const string &id) { this->id = id; }
void Product::setName(const string &name) { this->name = name; }
void Product::setCategory(const string &category) { this->category = category; }
void Product::setVolume(double volume) { this->volume = volume; }
void Product::setQuantity(int quantity) { this->quantity = quantity; }
void Product::setPrice(long long price) { this->price = price; }

string Product::getId() const { return this->id; }
string Product::getName() const { return this->name; }
string Product::getCategory() const { return this->category; }
double Product::getVolume() const { return this->volume; }
int Product::getQuantity() const { return this->quantity; }
long long Product::getPrice() const { return this->price; }