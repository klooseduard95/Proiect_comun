//
// Created by Eduard-Andreas Kloos on 17.04.2025.
//

#include "ProductController.h"
#include "../domain/Validations/ProductValidator.h"
#include <iostream>
#include <algorithm>

ProductController::ProductController(IRepository<Product>* repo) : productRepository(repo) {}

bool ProductController::createProduct(const std::string& productId, const std::string& name, double price, int stock) {
    Product newProduct(productId, name, price, stock);

    try {
        ProductValidator::validateForCreate(newProduct);

        productRepository->add(newProduct);
        return true;
    } catch (const std::exception& e) {
        std::cout << "Eroare: " << e.what() << "\n";
        return false;
    }
}

void ProductController::listAvailableProducts() const {
    std::vector<Product> availableProducts = productRepository->getAll();

    availableProducts.erase(
        std::remove_if(availableProducts.begin(), availableProducts.end(), [](const Product& p) {
            return p.getStock() <= 0;
        }), availableProducts.end());

    std::sort(availableProducts.begin(), availableProducts.end(), [](const Product& a, const Product& b) {
        return a.getPrice() < b.getPrice();
    });

    if (availableProducts.empty()) {
        std::cout << "Nu există produse disponibile în stoc.\n";
        return;
    }

    std::cout << "Produse disponibile:\n";
    for (const auto& product : availableProducts) {
        std::cout << "ID: " << product.getId() << ", "
                  << "Nume: " << product.getName() << ", "
                  << "Preț: " << product.getPrice() << " lei, "
                  << "Stoc: " << product.getStock() << "\n";
    }
}
