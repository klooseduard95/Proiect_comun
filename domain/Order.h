#pragma once
#include <string>
#include <vector>
#include "Product.h"

using namespace std;

#ifndef ORDER_H
#define ORDER_H

class ProductQuantity {
public:
    Product product;
    int quantity;

    ProductQuantity(const Product& product, int quantity)
            : product(product), quantity(quantity) {}
};

class Order {
private:
    static int nextOrderNumber;

    int orderNumber;
    string orderDate;
    string status;

    vector<ProductQuantity> products;

    string customerEmail;
    string employeeEmail;

public:
    Order(const string& orderDate,
          const string& status,
          const string& customerEmail,
          const string& employeeEmail = "");

    void addProduct(const Product& product, int quantity);

    double getTotalSum() const;

    int getOrderNumber() const;
    string getOrderDate() const;
    string getStatus() const;

    void setStatus(const string& newStatus);
};

#endif // ORDER_H
