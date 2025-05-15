//
// Created by Eduard-Andreas Kloos on 17.04.2025.
//



#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include <string>

class Customer : public User {
private:
    std::string firstName;
    std::string lastName;
    std::string address;
    std::string note;
    bool gdprDeleted;

public:
    Customer(const std::string& email, const std::string& password,
             const std::string& firstName, const std::string& lastName,
             const std::string& address, const std::string& note = "",
             bool gdprDeleted = false);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getAddress() const;
    std::string getNote() const;
    bool isGdprDeleted() const;

    void setGdprDeleted(bool value);
};

#endif // CUSTOMER_H
