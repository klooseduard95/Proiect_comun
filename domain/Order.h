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
    vector<pair<Product, int>> products;
    Customer customer;
    Employee employee;
    double totalPrice;
    static int nextOrderId;

    static std::string generateOrderId();
    double calculateTotalPrice() const;

public:
    Order() = default;
    // Constructor
    Order(const std::string& orderId, const std::string& orderDate, OrderStatus status,
          const std::vector<std::pair<Product, int>>& products, const Customer& customer,
          const Employee& employee, double totalPrice);

    Order(const std::string& orderDate, OrderStatus status,
          const std::vector<std::pair<Product, int>>& products, const Customer& customer,
          const Employee& employee);

    // Getters
    string getId() const;
    string getOrderDate() const;
    OrderStatus getStatus() const;
    vector<pair<Product, int>> getProducts() const;
    Customer getCustomer() const;
    Employee getEmployee() const;
    double getTotalPrice() const;

    // Setters
    void setStatus(OrderStatus newStatus);
    void setEmployee(const Employee& newEmployee);
    void setTotalPrice(double newPrice);
};
