#include "OrderController.h"
#include <stdexcept>
#include <algorithm>

using namespace std;

// Constructor
OrderController::OrderController(IRepository<Order>& repo) : orderRepo(repo) {}

void OrderController::createReservation(const Order& order) {
    orderRepo.add(order);
}

void OrderController::confirmOrder(const string& orderId) {
    Order order = orderRepo.getById(orderId);
    if (order.getStatus() == OrderStatus::Completed) {
        throw runtime_error("Cannot confirm a completed order.");
    }
    order.setStatus(OrderStatus::Confirmed);
    orderRepo.update(order);
}

void OrderController::completeOrder(const string& orderId) {
    Order order = orderRepo.getById(orderId);
    if (order.getStatus() == OrderStatus::Completed) {
        throw runtime_error("Order is already completed.");
    }
    order.setStatus(OrderStatus::Completed);
    orderRepo.update(order);
}

void OrderController::updateOrder(const Order& updatedOrder) {
    Order existingOrder = orderRepo.getById(updatedOrder.getOrderId());
    if (existingOrder.getStatus() == OrderStatus::Completed) {
        throw runtime_error("Completed orders cannot be modified.");
    }
    orderRepo.update(updatedOrder);
}

void OrderController::takeOverOrder(const string& orderId, const string& employeeId) {
    Order order = orderRepo.getById(orderId);
    Employee newEmployee(employeeId, "", "", "", "", "", 0);
    order.setEmployee(newEmployee);
    orderRepo.update(order);
}

vector<Order> OrderController::getOrdersByStatus(OrderStatus status) const {
    vector<Order> allOrders = orderRepo.getAll();
    vector<Order> filtered;

    copy_if(allOrders.begin(), allOrders.end(), back_inserter(filtered),
            [status](const Order& o) { return o.getStatus() == status; });
    return filtered;
}

vector<Order> OrderController::getOrdersForCustomer(const string& customerId) const {
    vector<Order> allOrders = orderRepo.getAll();
    vector<Order> filtered;

    copy_if(allOrders.begin(), allOrders.end(), back_inserter(filtered),
            [&customerId](const Order& o) { return o.getCustomer().getEmail() == customerId; });
    return filtered;
}

double OrderController::getTotalSumForPeriod(const string& year, const string& month) const {
    vector<Order> allOrders = orderRepo.getAll();
    double total = 0.0;

    for (const auto& order : allOrders) {
        string date = order.getOrderDate();
        if (date.size() >= 7 && date.substr(0, 4) == year && (month.empty() || date.substr(5, 2) == month)) {
            total += order.getTotalPrice();
        }
    }
    return total;
}

Order OrderController::getOrderById(const string& orderId) const {
    return orderRepo.getById(orderId);
}
