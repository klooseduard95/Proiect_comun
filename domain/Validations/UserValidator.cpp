#include "UserValidator.h"

bool UserValidator::isEmployee(const std::string& role) {
    return role == "Employee";
}

bool UserValidator::isCustomer(const std::string& role) {
    return role == "Customer";
}
