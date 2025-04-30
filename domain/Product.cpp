#include "Product.h"

Product::Product(const string& productId,
                 const string& name,
                 double price,
                 int stock)
        : productId(productId), name(name), price(price), stock(stock) {}

string Product::getId() const {
    return productId;
}

string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

int Product::getStock() const {
    return stock;
}

void Product::setPrice(double newPrice) {
    price = newPrice;
}

void Product::setStock(int newStock) {
    stock = newStock;
}