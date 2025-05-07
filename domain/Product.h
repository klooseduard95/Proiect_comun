//
// Created by Eduard-Andreas Kloos on 17.04.2025.
//
#pragma once
#include <string>
using namespace std;
#ifndef PRODUCT_H
#define PRODUCT_H

class Product {
private:
    string productId, name;
    double price;
    int stock;
public:
    Product() = default;
    Product(const string& productId,
        const string& name,
        double price,
        int stock);

    [[nodiscard]] string getId() const;
    [[nodiscard]] string getName() const;
    [[nodiscard]] double getPrice() const;
    [[nodiscard]] int getStock() const;

    void setPrice(double);
    void setStock(int);
};

#endif //PRODUCT_H
