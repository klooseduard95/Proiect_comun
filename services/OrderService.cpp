#include "OrderService.h"
#include <stdexcept>
#include <sstream>

static int parseOrderId(const std::string& orderId) {
    return std::stoi(orderId);
}

void OrderService::createReservation(const Order& order) {
    orders[order.getOrderNumber()] = order;
}

void OrderService::confirmOrder(const std::string& orderId) {
    int id = parseOrderId(orderId);
    if (orders.find(id) == orders.end())
        throw std::runtime_error("Order not found");

    Order& ord = orders[id];
    if (ord.getStatus() == "Completed")
        throw std::runtime_error("Cannot confirm a completed order");

    ord.setStatus("Confirmed");
}

void OrderService::completeOrder(const std::string& orderId) {
    int id = parseOrderId(orderId);
    if (orders.find(id) == orders.end())
        throw std::runtime_error("Order not found");

    Order& ord = orders[id];
    if (ord.getStatus() != "Confirmed")
        throw std::runtime_error("Only confirmed orders can be completed");

    ord.setStatus("Completed");
}

void OrderService::updateOrder(const Order& order) {
    int id = order.getOrderNumber();
    if (orders.find(id) == orders.end())
        throw std::runtime_error("Order not found");

    Order& existing = orders[id];

    if (existing.getStatus() == "Completed")
        throw std::runtime_error("Cannot modify a completed order");

    if (existing.getEmployeeEmail() != order.getEmployeeEmail())
        throw std::runtime_error("Only assigned employee can update the order");

    orders[id] = order;
}

void OrderService::takeOverOrder(const std::string& orderId, const std::string& employeeId) {
    int id = parseOrderId(orderId);
    if (orders.find(id) == orders.end())
        throw std::runtime_error("Order not found");

    Order& ord = orders[id];
    if (ord.getEmployeeEmail().empty() || ord.getEmployeeEmail() != employeeId) {
        ord.setEmployeeEmail(employeeId);
    } else {
        throw std::runtime_error("Order already assigned to this employee");
    }
}
