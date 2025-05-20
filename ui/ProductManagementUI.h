//
// Created by Eduard-Andreas Kloos on 20.05.2025.
//

#ifndef PRODUCTMANAGEMENTUI_H
#define PRODUCTMANAGEMENTUI_H
#pragma once
#include "../controller/ProductController.h"

class ProductUI {
private:
    ProductController& controller;

public:
    explicit ProductUI(ProductController& controller);
    void showMenu();

private:
    void addProduct();
};

#endif //PRODUCTMANAGEMENTUI_H
