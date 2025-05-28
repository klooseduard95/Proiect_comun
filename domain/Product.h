#pragma once
#include <string>
using namespace std;
#ifndef PRODUCT_H
#define PRODUCT_H

/**
 * @brief Clasa care reprezinta un produs din sistem.
 */
class Product {
private:
    string productId, name;
    double price;
    int stock;
public:
    /**
     * @brief Constructor implicit pentru Product.
     */
    Product() = default;
    /**
     * @brief Constructor pentru initializarea unui produs cu valori specifice.
     *
     * @param productId ID-ul unic al produsului
     * @param name Numele produsului
     * @param price Pretul produsului
     * @param stock Cantitatea in stoc
     */
    Product(const string& productId,
            const string& name,
            double price,
            int stock);

    /**
     * @brief Returneaza ID-ul produsului.
     * @return ID-ul ca string
     */
    [[nodiscard]] string getId() const;

    /**
     * @brief Returneaza numele produsului.
     * @return Numele ca string
     */

    [[nodiscard]] string getName() const;
    /**
     * @brief Returneaza pretul produsului.
     * @return Pretul ca double
     */
    [[nodiscard]] double getPrice() const;

    /**
     * @brief Returneaza stocul disponibil.
     * @return Stocul ca int
     */
    [[nodiscard]] int getStock() const;

    /**
     * @brief Seteaza un nou pret pentru produs.
     *
     * @param newPrice Noul pret
     */
    void setPrice(double);

    /**
     * @brief Seteaza o noua valoare pentru stoc.
     *
     * @param newStock Noua cantitate disponibila
     */
    void setStock(int);
};

#endif //PRODUCT_H