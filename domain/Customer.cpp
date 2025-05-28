//
// Created by Eduard-Andreas Kloos on 17.04.2025.
//

#include "Customer.h"
#include <iostream>
using namespace std;
/**
 * @file Customer.h
 * @brief Customer entity class definition
 */

/**
 * @class Customer
 * @brief Represents a customer entity, inheriting from User
 *
 * @details Stores customer personal information and GDPR compliance status
 */
/**
     * @brief Constructs a Customer object
     * @param email Customer's unique email address
     * @param password Customer's password
     * @param firstName Customer's first name
     * @param lastName Customer's last name
     * @param address Customer's physical address
     * @note Additional notes about the customer
     * @param gdprDeleted GDPR compliance deletion flag
     */
Customer::Customer(const string& email, const string& password,
                   const string& firstName, const string& lastName,
                   const string& address, const string& note,
                   bool gdprDeleted)
    : User(email, password, "customer"),
      firstName(firstName), lastName(lastName),
      address(address), note(note), gdprDeleted(gdprDeleted) {}
/**
     * @brief Gets customer's first name
     * @return First name as string
     */
string Customer::getFirstName() const { return firstName; }

/**
     * @brief Gets customer's last name
     * @return Last name as string
     */

string Customer::getLastName() const { return lastName; }
/**
     * @brief Gets customer's address
     * @return Physical address as string
     */

string Customer::getAddress() const { return address; }
/**
     * @brief Gets customer notes
     * @return Additional notes as string
     */
string Customer::getNote() const { return note; }
/**
     * @brief Checks GDPR deletion status
     * @return true if customer is GDPR-deleted, false otherwise
     */
bool Customer::isGdprDeleted() const { return gdprDeleted; }


// Setters documentation for Customer.cpp
/**
 * @brief Sets customer's first name
 * @param newFirstName New first name value
 */
void Customer::setFirstName(const string& newFirstName) {
    this->firstName = newFirstName;
}
/**
     * @brief Sets customer's last name
     * @param newLastName New last name value
     */
void Customer::setLastName(const string& newLastName) {
    this->lastName = newLastName;
}
/**
     * @brief Sets customer's email
     * @warning Changing email affects system uniqueness
     * @param newEmail New email address
     */
void Customer::setEmail(const string& newEmail) {
    this->email = newEmail;
}
/**
     * @brief Sets customer's address
     * @param newAddress New physical address
     */
void Customer::setAddress(const string& newAddress) {
    this->address = newAddress;
}
/**
     * @brief Sets customer notes
     * @param newNote New notes content
     */
void Customer::setNote(const string& newNote) {
    this->note = newNote;
}
/**
     * @brief Sets GDPR deletion status
     * @param deleted true to mark as GDPR-deleted
     * @note GDPR deletion is typically irreversible
     */
void Customer::setGdprDeleted(bool deleted) {
    this->gdprDeleted = deleted;
}


