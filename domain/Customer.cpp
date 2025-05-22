//
// Created by Eduard-Andreas Kloos on 17.04.2025.
//

#include "Customer.h"

Customer::Customer(const std::string& email, const std::string& password,
                   const std::string& firstName, const std::string& lastName,
                   const std::string& address, const std::string& note,
                   bool gdprDeleted)
    : User(email, password, "customer"),
      firstName(firstName), lastName(lastName),
      address(address), note(note), gdprDeleted(gdprDeleted) {}

std::string Customer::getFirstName() const { return firstName; }
std::string Customer::getLastName() const { return lastName; }
std::string Customer::getAddress() const { return address; }
std::string Customer::getNote() const { return note; }
bool Customer::isGdprDeleted() const { return gdprDeleted; }

// Customer.cpp

void Customer::setFirstName(const string& newFirstName) {
    this->firstName = newFirstName;
}

void Customer::setLastName(const string& newLastName) {
    this->lastName = newLastName;
}

void Customer::setEmail(const string& newEmail) {
    this->email = newEmail;
}

void Customer::setAddress(const string& newAddress) {
    this->address = newAddress;
}

void Customer::setNote(const string& newNote) {
    this->note = newNote;
}

void Customer::setGdprDeleted(bool deleted) {
    this->gdprDeleted = deleted;
}


