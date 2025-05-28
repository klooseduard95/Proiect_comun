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

/**
 * @brief Clasa responsabila de logica de control pentru produse.
 *
 * Permite adaugarea si listarea produselor prin interactiunea cu un repository generic.
 */
class ProductController {
private:
    IRepository<Product>* productRepository;

public:
    /**
     * @brief Constructor pentru ProductController.
     *
     * @param repo Pointer catre repository-ul care gestioneaza produsele
     */
    ProductController(IRepository<Product>* repo);

    /**
     * @brief Creeaza si adauga un produs nou in repository.
     *
     * Valideaza datele produsului inainte de adaugare.
     *
     * @param productId ID-ul unic al produsului
     * @param name Numele produsului
     * @param price Pretul produsului
     * @param stock Cantitatea disponibila in stoc
     * @return true daca produsul a fost adaugat cu succes, altfel false
     */
    bool createProduct(const std::string& productId, const std::string& name, double price, int stock);

    /**
     * @brief Afiseaza toate produsele disponibile in stoc (cu stoc > 0), sortate dupa pret.
     */
    void listAvailableProducts() const;
};
#endif //PRODUCTCONTROLLER_H