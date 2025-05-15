#include "Order.h"

using namespace std;

Order::Order(const string& orderId,
             const string& orderDate,
             OrderStatus status,
             const vector<pair<Product, int>>& products,
             const Customer& customer,
             const Employee& employee,
             double totalPrice)
    : orderId(orderId), orderDate(orderDate), status(status),
      products(products), customer(customer), employee(employee),
      totalPrice(totalPrice) {}

string Order::getOrderId() const {
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
