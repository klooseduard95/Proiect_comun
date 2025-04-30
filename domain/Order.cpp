#include "Order.h"

int Order::nextOrderNumber = 1;

Order::Order(const string& orderDate,
             const string& status,
             const string& customerEmail,
             const string& employeeEmail)
        : orderDate(orderDate),
          status(status),
          customerEmail(customerEmail),
          employeeEmail(employeeEmail) {
    orderNumber = nextOrderNumber++;
}

void Order::addProduct(const Product& product, int quantity) {
    products.emplace_back(product, quantity);
}

double Order::getTotalSum() const {
    double total = 0.0;
    for (const auto& [product, quantity] : products) {
        total += product.getPrice() * quantity;
    }
    return total;
}

int Order::getOrderNumber() const {
    return orderNumber;
}

string Order::getOrderDate() const {
    return orderDate;
}

string Order::getStatus() const {
    return status;
}

string Order::getCustomerEmail() const {
    return customerEmail;
}

string Order::getEmployeeEmail() const {
    return employeeEmail;
}

void Order::setStatus(const string& newStatus) {
    status = newStatus;
}

void Order::setEmployeeEmail(const string& email) {
    employeeEmail = email;
}
