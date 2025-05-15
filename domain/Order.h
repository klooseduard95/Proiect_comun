#pragma once
using namespace std;
#include <string>
#include <vector>
#include "Product.h"
#include "Customer.h"
#include "Employee.h"

enum class OrderStatus {
    Reservation,
    Confirmed,
    Completed
};

class Order {
private:
    string orderId;
    string orderDate;
    OrderStatus status;
    vector<std::pair<Product, int>> products;
    Customer customer;
    Employee employee;
    double totalPrice;

public:
    // Constructor
    Order(const string& orderId, const std::string& orderDate, OrderStatus status,
          const vector<pair<Product, int>>& products, const Customer& customer,
          const Employee& employee, double totalPrice);

    // Getters
    string getOrderId() const;
    string getOrderDate() const;
    OrderStatus getStatus() const;
    vector<std::pair<Product, int>> getProducts() const;
    Customer getCustomer() const;
    Employee getEmployee() const;
    double getTotalPrice() const;

    // Setters
    void setStatus(OrderStatus newStatus);
    void setEmployee(const Employee& newEmployee);
    void setTotalPrice(double newPrice);
};
