#include "OrderController.h"
#include "../domain/Validations/OrderValidator.h"
#include <stdexcept>
#include <algorithm>
#include <utility>

/**
 * @brief Constructs an OrderController with a reference to an Order repository.
 *
 * @param repo Reference to a repository of Order objects.
 */
OrderController::OrderController(IRepository<Order>& repo) : orderRepo(repo) {}



/**
 * @brief Creates a reservation order for a customer.
 *
 * Validates the order status, then adds it to the repository.
 *
 * @param user The user who is placing the reservation.
 * @param order The order object to be added as a reservation.
 *
 * @throws std::invalid_argument If the order status is invalid for a reservation.
 */
void OrderController::createReservation(const User& user, const Order& order) {
    OrderValidator::validateStatusForReservation(order);
    orderRepo.add(order);
}

/**
 * @brief Confirms an existing order by ID.
 *
 * Validates the order state before confirming and then updates its status.
 *
 * @param orderId The ID of the order to confirm.
 *
 * @throws std::runtime_error or std::invalid_argument if the order cannot be confirmed.
 */
void OrderController::confirmOrder(const string& orderId) {
    Order order = orderRepo.getById(orderId);
    OrderValidator::validateBeforeConfirm(order);
    order.setStatus(OrderStatus::Confirmed);
    orderRepo.update(order);
}

/**
 * @brief Marks an order as completed by its ID.
 *
 * Validates the order before setting its status to completed and updates it in the repository.
 *
 * @param orderId The ID of the order to complete.
 *
 * @throws std::runtime_error or std::invalid_argument if the order cannot be completed.
 */
void OrderController::completeOrder(const string& orderId) {
    Order order = orderRepo.getById(orderId);
    OrderValidator::validateBeforeComplete(order);
    order.setStatus(OrderStatus::Completed);
    orderRepo.update(order);
}

/**
 * @brief Updates an existing order.
 *
 * Validates permissions before updating. Only the employee assigned to the order can update it.
 *
 * @param user The employee requesting the update.
 * @param updatedOrder The updated order details.
 *
 * @throws std::runtime_error If the employee is not assigned to the order.
 */
void OrderController::updateOrder(const User& user, const Order& updatedOrder) {
    Order existingOrder = orderRepo.getById(updatedOrder.getId());

    OrderValidator::validateUpdatePermission(existingOrder, updatedOrder);

    if (existingOrder.getEmployee().getId() != user.getId()) {
        throw runtime_error("Employees can only update their own orders.");
    }

    orderRepo.update(updatedOrder);
}



/**
 * @brief Assigns the currently logged-in employee to an order.
 *
 * Used to "take over" an order that is not currently assigned to the employee.
 *
 * @param user The employee taking over the order.
 * @param orderId The ID of the order to take over.
 */
void OrderController::takeOverOrder(const User& user, const string& orderId) {
    Order order = orderRepo.getById(orderId);

    if (order.getEmployee().getId() == user.getId()) return;

    Employee newEmployee(user.getId(), "", "", "", "", "", 0);
    order.setEmployee(newEmployee);
    orderRepo.update(order);
}

/**
 * @brief Retrieves all orders with a specific status.
 *
 * Filters the orders stored in the repository by the provided status.
 *
 * @param status The status to filter orders by.
 *
 * @return A vector of orders matching the given status.
 */
vector<Order> OrderController::getOrdersByStatus(OrderStatus status) const {
    vector<Order> allOrders = orderRepo.getAll();
    vector<Order> filteredOrders;

    copy_if(allOrders.begin(), allOrders.end(), back_inserter(filteredOrders),
            [status](const Order& o) { return o.getStatus() == status; });

    return filteredOrders;
}



/**
 * @brief Retrieves all orders for a specific customer.
 *
 * Filters orders based on the customer's ID.
 *
 * @param user The customer user whose orders should be retrieved.
 *
 * @return A vector of orders belonging to the specified customer.
 */
vector<Order> OrderController::getOrdersForCustomer(const User& user) const {
    string customerId = user.getId();

    vector<Order> allOrders = orderRepo.getAll();
    vector<Order> filteredOrders;

    copy_if(allOrders.begin(), allOrders.end(), back_inserter(filteredOrders),
            [customerId](const Order& o) { return o.getCustomer().getId() == customerId; });

    return filteredOrders;
}


/**
 * @brief Calculates the total price of completed orders in a given year and optionally a specific month.
 *
 * @param year The year to aggregate totals for (e.g., "2024").
 * @param month Optional month to filter orders (e.g., "03").
 *
 * @return A pair:
 *         - first = total price for the year,
 *         - second = total price for the month (if provided).
 */
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

/**
 * @brief Retrieves an order by its ID.
 *
 * @param orderId The unique identifier of the order.
 *
 * @return The matching Order object.
 *
 * @throws std::runtime_error If the order ID is not found.
 */
Order OrderController::getOrderById(const string& orderId) const {
    return orderRepo.getById(orderId);
}

/**
 * @brief Retrieves all orders (used mainly for employee-related operations).
 *
 * @return A vector containing all orders in the repository.
 */
vector<Order> OrderController::getOrdersForEmployee() const {
    vector<Order> allOrders = orderRepo.getAll();;
    return allOrders;
}