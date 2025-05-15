//
// Created by Eduard-Andreas Kloos on [Datum].
//

#pragma once

#include "../domain/Customer.h"
#include "../repository/interfaces/IRepository.h"
#include <vector>
#include <string>

#ifndef CUSTOMERCONTROLLER_H
#define CUSTOMERCONTROLLER_H

class CustomerController {
private:
    IRepository<Customer>* customerRepository;

public:
    CustomerController(IRepository<Customer>* repo);


    bool createCustomer(const std::string& email, const std::string& password,
                        const std::string& firstName, const std::string& lastName,
                        const std::string& address, const std::string& note = "",
                        bool gdprDeleted = false);


    bool updateCustomer(const Customer& updatedCustomer);


    bool deleteCustomer(const std::string& email);


    std::vector<Customer> listAllCustomersSorted() const;


    Customer findCustomerByEmail(const std::string& email) const;
};

#endif // CUSTOMERCONTROLLER_H
