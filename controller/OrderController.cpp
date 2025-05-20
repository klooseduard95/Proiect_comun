#include "OrderController.h"
#include "../domain/Validations/OrderValidator.h"
#include <stdexcept>
#include <algorithm>


OrderController::OrderController(IRepository<Order>& repo) : orderRepo(repo) {}

void OrderController::createReservation(const Order& order) {
    OrderValidator::validateStatusForReservation(order);
    orderRepo.add(order);
}

void OrderController::confirmOrder(const string& orderId) {
    Order order = orderRepo.getById(orderId);
    OrderValidator::validateBeforeConfirm(order);
    order.setStatus(OrderStatus::Confirmed);
    orderRepo.update(order);
}

void OrderController::completeOrder(const string& orderId) {
    Order order = orderRepo.getById(orderId);
    OrderValidator::validateBeforeComplete(order);
    order.setStatus(OrderStatus::Completed);
    orderRepo.update(order);
}

void OrderController::updateOrder(const Order& updatedOrder) {
    Order existingOrder = orderRepo.getById(updatedOrder.getId());

    OrderValidator::validateUpdatePermission(existingOrder, updatedOrder);

    // Employees can only update their own orders
    if (existingOrder.getEmployee().getId() != updatedOrder.getEmployee().getId()) {
        throw runtime_error("Employees can only update their own orders.");
    }

    orderRepo.update(updatedOrder);
}

void OrderController::takeOverOrder(const string& orderId, const string& employeeId) {
    Order order = orderRepo.getById(orderId);
    const Employee& currentEmployee = order.getEmployee();

    if (currentEmployee.getId() == employeeId) {
        // Already assigned to this employee, no change needed
        return;
    }

    // Assign new employee (assuming minimal constructor)
    Employee newEmployee(employeeId, "", "", "", "", "", 0);
    order.setEmployee(newEmployee);
    orderRepo.update(order);
}

vector<Order> OrderController::getOrdersByStatus(OrderStatus status) const {
    vector<Order> allOrders = orderRepo.getAll();
    vector<Order> filteredOrders;

    copy_if(allOrders.begin(), allOrders.end(), back_inserter(filteredOrders),
            [status](const Order& o) { return o.getStatus() == status; });

    return filteredOrders;
}

vector<Order> OrderController::getOrdersForCustomer(const string& customerId) const {
    vector<Order> allOrders = orderRepo.getAll();
    vector<Order> filteredOrders;

    copy_if(allOrders.begin(), allOrders.end(), back_inserter(filteredOrders),
            [customerId](const Order& o) { return o.getCustomer().getId() == customerId; });

    return filteredOrders;
}

double OrderController::getTotalSumForPeriod(const string& year, const string& month) const {
    vector<Order> allOrders = orderRepo.getAll();
    double totalSum = 0.0;

    for (const auto& order : allOrders) {
        string date = order.getOrderDate(); // Format assumed: YYYY-MM-DD
        if (date.substr(0, 4) == year) {
            if (month.empty() || date.substr(5, 2) == month) {
                totalSum += order.getTotalPrice();
            }
        }
    }
    return totalSum;
}

Order OrderController::getOrderById(const string& orderId) const {
    return orderRepo.getById(orderId);
}
