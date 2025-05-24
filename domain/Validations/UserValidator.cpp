#include "UserValidator.h"

bool UserValidator::isEmployee(const std::string& role) {
    return role == "employee";
}

bool UserValidator::isCustomer(const std::string& role) {
    return role == "customer";
}
