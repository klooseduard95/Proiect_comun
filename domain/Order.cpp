#include "Order.h"
#include "Product.h"

int Order::nextOrderNumber = 1;

Order::Order(const string& orderDate,
             const string& status,
             const string& customerEmail,
             const string& employeeEmail)
        : orderNumber(nextOrderNumber++),
          orderDate(orderDate),
          status(status),
          customerEmail(customerEmail),
          employeeEmail(employeeEmail) {}

void Order::addProduct(const Product& product, int quantity) {
    products.push_back(ProductQuantity(product, quantity));
}

double Order::getTotalSum() const {
    double total = 0;
    for (const auto& productQuantity : products) {
        total += productQuantity.product.getPrice() * productQuantity.quantity;
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
