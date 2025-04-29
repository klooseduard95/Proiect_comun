//
// Created by Eduard-Andreas Kloos on 29.04.2025.
//
#pragma once
#include <vector>
#include <string>
#include "../../domain/Customer.h"
#ifndef ICUSTOMERSERVICE_H
#define ICUSTOMERSERVICE_H

class ICustomerService {
public:
    virtual void addCustomer(const Customer& customer) = 0;
    virtual void updateCustomer(const Customer& customer) = 0;
    virtual void deleteCustomer(const std::string& customerId) = 0;
    virtual void anonymizeCustomer(const std::string& customerId) = 0;

    virtual Customer getCustomerByEmail(const std::string& email) const = 0;
    virtual std::vector<Customer> getAllCustomersSorted() const = 0;
    virtual std::vector<Customer> getCustomersByProduct(const std::string& productId) const = 0;

    virtual ~ICustomerService() = default;
};

#endif //ICUSTOMERSERVICE_H
