#include "Order.h"
#include <sstream>
#include <iomanip>

using namespace std;

int Order::nextOrderId = 1;

std::string Order::generateOrderId() {
    std::ostringstream oss;
    oss << "O" << std::setw(4) << std::setfill('0') << nextOrderId++;
    return oss.str();
}

double Order::calculateTotalPrice() const {
    double sum = 0.0;
    for (const auto& p : products) {
        sum += p.first.getPrice() * p.second;
    }
    return sum;
}

Order::Order(const std::string& orderId, const std::string& orderDate, OrderStatus status,
             const std::vector<std::pair<Product, int>>& products, const Customer& customer,
             const Employee& employee, double totalPrice)
    : orderId(orderId), orderDate(orderDate), status(status),
      products(products), customer(customer), employee(employee),
      totalPrice(totalPrice) {}

Order::Order(const std::string& orderDate, OrderStatus status,
             const std::vector<std::pair<Product, int>>& products, const Customer& customer,
             const Employee& employee)
    : orderId(generateOrderId()), orderDate(orderDate), status(status),
      products(products), customer(customer), employee(employee) {
    totalPrice = calculateTotalPrice();
}

string Order::getId() const {
    return orderId;
}

string Order::getOrderDate() const {
    return orderDate;
}

OrderStatus Order::getStatus() const {
    return status;
}

vector<pair<Product, int>> Order::getProducts() const {
    return products;
}

Customer Order::getCustomer() const {
    return customer;
}

Employee Order::getEmployee() const {
    return employee;
}

double Order::getTotalPrice() const {
    return totalPrice;
}

void Order::setStatus(OrderStatus newStatus) {
    status = newStatus;
}

void Order::setEmployee(const Employee& newEmployee) {
    employee = newEmployee;
}

void Order::setTotalPrice(double newPrice) {
    totalPrice = newPrice;
}
