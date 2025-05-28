#include "OrderController.h"
#include "../domain/Validations/OrderValidator.h"
#include <stdexcept>
#include <algorithm>
#include <utility>


OrderController::OrderController(IRepository<Order>& repo) : orderRepo(repo) {}

void OrderController::createReservation(const User& user, const Order& order) {
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

void OrderController::updateOrder(const User& user, const Order& updatedOrder) {
    Order existingOrder = orderRepo.getById(updatedOrder.getId());

    OrderValidator::validateUpdatePermission(existingOrder, updatedOrder);

    if (existingOrder.getEmployee().getId() != user.getId()) {
        throw runtime_error("Employees can only update their own orders.");
    }

    orderRepo.update(updatedOrder);
}


void OrderController::takeOverOrder(const User& user, const string& orderId) {
    Order order = orderRepo.getById(orderId);

    if (order.getEmployee().getId() == user.getId()) return;

    Employee newEmployee(user.getId(), "", "", "", "", "", 0);
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

vector<Order> OrderController::getOrdersForCustomer(const User& user) const {
    string customerId = user.getId();

    vector<Order> allOrders = orderRepo.getAll();
    vector<Order> filteredOrders;

    copy_if(allOrders.begin(), allOrders.end(), back_inserter(filteredOrders),
            [customerId](const Order& o) { return o.getCustomer().getId() == customerId; });

    return filteredOrders;
}


pair<double,double> OrderController::getTotalSumForPeriod(const string& year, const string& month) const {
    vector<Order> allOrders = getOrdersByStatus(OrderStatus::Completed);
    double totalSumForYear = 0.0;
    double totalSumForMonth = 0.0;
    pair<double, double> total;

    for (const auto& order : allOrders) {
        string date = order.getOrderDate(); // Format assumed: YYYY-MM-DD
        if (date.substr(0, 4) == year) {
            if (!month.empty() && date.substr(5, 2) == month) {
                totalSumForMonth += order.getTotalPrice();
            }
            else {
                totalSumForYear += order.getTotalPrice();
            }
        }
        total.first = totalSumForYear;
        total.second = totalSumForMonth;
    }
    return total;
}

Order OrderController::getOrderById(const string& orderId) const {
    return orderRepo.getById(orderId);
}

vector<Order> OrderController::getOrdersForEmployee() const {
    vector<Order> allOrders = orderRepo.getAll();;
    return allOrders;
}
