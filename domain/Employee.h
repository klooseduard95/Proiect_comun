//
// Created by Eduard-Andreas Kloos on 17.04.2025.
//

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "User.h"
#include <string>

class Employee : public User {
private:
    std::string firstName;
    std::string lastName;
    std::string position;
    std::string birthDate;
    double salary;

public:
    Employee();
    Employee(const std::string& email, const std::string& password,
             const std::string& firstName, const std::string& lastName,
             const std::string& position, const std::string& birthDate,
             double salary);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getPosition() const;
    std::string getBirthDate() const;
    double getSalary() const;

    void setSalary(double newSalary);
};

#endif // EMPLOYEE_H


