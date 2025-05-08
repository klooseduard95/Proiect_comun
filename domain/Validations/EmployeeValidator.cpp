#include "EmployeeValidator.h"

bool EmployeeValidator::canModifyOrder(const Order& order, const std::string& employeeEmail) {
    return order.getStatus() != "Completed" &&
           order.getEmployeeEmail() == employeeEmail;
}

bool EmployeeValidator::canCompleteOrder(const Order& order) {
    return order.getStatus() == "Confirmed";
}

bool EmployeeValidator::canTakeOverOrder(const Order& order, const std::string& employeeEmail) {
    return order.getEmployeeEmail().empty() ||
           order.getEmployeeEmail() != employeeEmail;
}

bool EmployeeValidator::canConfirmOrder(const Order& order) {
    return order.getStatus() != "Completed";
}
