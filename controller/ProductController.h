//
// Created by Eduard-Andreas Kloos on 17.04.2025.
//

#pragma once
#include "../domain/Product.h"
#include "../repository/interfaces/IRepository.h"
#include <vector>
#include <string>
#ifndef PRODUCTCONTROLLER_H
#define PRODUCTCONTROLLER_H

class ProductController {
private:
    IRepository<Product>* productRepository;

public:
    ProductController(IRepository<Product>* repo);

    bool createProduct(const std::string& productId, const std::string& name, double price, int stock);

    void listAvailableProducts() const;
    Product getProductById(const std::string& productId) const {
        return productRepository->getById(productId);
    }
};
#endif //PRODUCTCONTROLLER_H