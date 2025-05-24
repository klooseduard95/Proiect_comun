//
// Created by Eduard-Andreas Kloos on 29.04.2025.
//
#pragma once
#include "Customer.h"

#ifndef CUSTOMERVALIDATOR_H
#define CUSTOMERVALIDATOR_H
class CustomerValidator {
public:
    static void ValidateEmail(const Customer& customer);
    static void ValidateGdpr(const Customer& customer);
};
#endif //CUSTOMERVALIDATOR_H
