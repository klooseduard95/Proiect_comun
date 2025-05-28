//
// Created by Eduard-Andreas Kloos on 17.04.2025.
//

#include "Employee.h"
#include <iostream>
using namespace std;

/**
 * @file Employee.h
 * @brief Employee entity class definition
 */

/**
 * @class Employee
 * @brief Represents an employee entity, inheriting from User
 *
 * @details Stores employee professional and personal information including
 *          position, birth date, and salary data.
 */
/**
    * @brief Default constructor
    * @details Creates an empty employee with default values:
    * - Empty strings for all text fields
    * - 0.0 salary
    * - "employee" role
    */
Employee::Employee()
    : User("", "", "employee"),
      firstName(""), lastName(""), position(""),
      birthDate(""), salary(0.0) {}

/**
     * @brief Parameterized constructor
     * @param email Employee's work email (unique identifier)
     * @param password Employee's login password
     * @param firstName Employee's first name
     * @param lastName Employee's last name
     * @param position Job title/position
     * @param birthDate Date of birth in string format (YYYY-MM-DD recommended)
     * @param salary Monthly salary amount
     */
Employee::Employee(const string& email, const string& password,
                   const string& firstName, const string& lastName,
                   const string& position, const string& birthDate,
                   double salary)
    : User(email, password, "employee"),
      firstName(firstName), lastName(lastName),
      position(position), birthDate(birthDate), salary(salary) {}

/**
    * @brief Gets employee's first name
    * @return First name as string
    */
string Employee::getFirstName() const { return firstName; }

/**
     * @brief Gets employee's last name
     * @return Last name as string
     */
string Employee::getLastName() const { return lastName; }

/**
     * @brief Gets employee's job position
     * @return Job title as string
     */
string Employee::getPosition() const { return position; }

/**
     * @brief Gets employee's birth date
     * @return Birth date in string format
     * @note Format depends on implementation (recommend ISO 8601: YYYY-MM-DD)
     */
string Employee::getBirthDate() const { return birthDate; }

/**
     * @brief Gets employee's current salary
     * @return Monthly salary amount as double
     * @warning Sensitive information - access should be restricted
     */
double Employee::getSalary() const { return salary; }
/**
     * @brief Updates employee's salary
     * @param newSalary New monthly salary amount
     */
void Employee::setSalary(double newSalary) { salary = newSalary; }

