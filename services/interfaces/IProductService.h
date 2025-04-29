//
// Created by Eduard-Andreas Kloos on 29.04.2025.
//
#pragma once
#include <vector>
#include <string>
#include "../../domain/Product.h"

#ifndef IPRODUCTSERVICE_H
#define IPRODUCTSERVICE_H

class IProductService {
public:
    virtual void addProduct(const Product& product) = 0;
    virtual std::vector<Product> getAvailableProductsSorted() const = 0;

    virtual ~IProductService() = default;
};

#endif //IPRODUCTSERVICE_H
