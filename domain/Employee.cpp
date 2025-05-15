//
// Created by Eduard-Andreas Kloos on 17.04.2025.
//

#include "Employee.h"

Employee::Employee(const std::string& email, const std::string& password,
                   const std::string& firstName, const std::string& lastName,
                   const std::string& position, const std::string& birthDate,
                   double salary)
    : User(email, password, "employee"),
      firstName(firstName), lastName(lastName),
      position(position), birthDate(birthDate), salary(salary) {}

std::string Employee::getFirstName() const { return firstName; }
std::string Employee::getLastName() const { return lastName; }
std::string Employee::getPosition() const { return position; }
std::string Employee::getBirthDate() const { return birthDate; }
double Employee::getSalary() const { return salary; }

void Employee::setSalary(double newSalary) { salary = newSalary; }

