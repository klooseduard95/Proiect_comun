//
// Created by Eduard-Andreas Kloos on 20.05.2025.
//
#include "ProductManagementUI.h"
#include <iostream>
#include <limits>

ProductUI::ProductUI(ProductController& controller) : controller(controller) {}

void ProductUI::showMenu() {
    int option;
    do {
        std::cout << "\n=== Product Menu ===\n";
        std::cout << "1. Add product\n";
        std::cout << "2. List available products\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> option;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (option) {
            case 1:
                addProduct();
            break;
            case 2:
                controller.listAvailableProducts();
            break;
            case 0:
                std::cout << "Exiting product menu.\n";
            break;
            default:
                std::cout << "Invalid option.\n";
        }

    } while (option != 0);
}

void ProductUI::addProduct() {
    std::string id, name;
    double price;
    int stock;

    std::cout << "Enter product ID: ";
    std::getline(std::cin, id);
    std::cout << "Enter product name: ";
    std::getline(std::cin, name);
    std::cout << "Enter product price: ";
    std::cin >> price;
    std::cout << "Enter product stock: ";
    std::cin >> stock;

    try {
        controller.createProduct(id, name, price, stock);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
