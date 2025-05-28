//
// Created by Eduard-Andreas Kloos on 20.05.2025.
//

#ifndef PRODUCTMANAGEMENTUI_H
#define PRODUCTMANAGEMENTUI_H
#pragma once
#include "../controller/ProductController.h"

/**
 * @class ProductUI
 * @brief Clasa pentru interfata utilizator legata de produse.
 *
 * Aceasta clasa afiseaza meniul pentru gestionarea produselor
 * si permite adaugarea si listarea produselor prin interactiune cu utilizatorul.
 */
class ProductUI {
private:
    /** Referinta catre controller-ul produselor pentru operatii de business */
    ProductController& controller;

public:
    /**
     * @brief Constructor care primeste referinta catre controller.
     * @param controller Referinta catre ProductController.
     */
    explicit ProductUI(ProductController& controller);

    /**
     * @brief Afiseaza meniul principal pentru gestionarea produselor.
     * Permite selectarea optiunilor disponibile.
     */
    void showMenu();

private:
    /**
     * @brief Citeste datele unui produs nou si incearca sa il adauge.
     */
    void addProduct();
};

#endif //PRODUCTMANAGEMENTUI_H
