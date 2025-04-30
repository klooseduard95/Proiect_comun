#pragma once
#include <string>
#include <vector>
#include <utility>
#include "Product.h"

using namespace std;

#ifndef ORDER_H
#define ORDER_H

class Order {
private:
    static int nextOrderNumber;

    int orderNumber;
    string orderDate;
    string status;

    vector<pair<Product, int>> products;

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
    string getCustomerEmail() const;
    string getEmployeeEmail() const;

    void setStatus(const string& newStatus);
    void setEmployeeEmail(const string& email);
};

#endif // ORDER_H
