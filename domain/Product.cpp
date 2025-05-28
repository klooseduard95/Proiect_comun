#include "Product.h"

/**
 * @brief Constructor pentru clasa Product.
 *
 * Initializeaza un produs cu ID, nume, pret si stoc.
 *
 * @param productId ID-ul unic al produsului.
 * @param name Numele produsului.
 * @param price Pretul produsului.
 * @param stock Numarul de unitati disponibile in stoc.
 */
Product::Product(const string& productId,
                 const string& name,
                 double price,
                 int stock)
        : productId(productId), name(name), price(price), stock(stock) {}

/**
 * @brief Returneaza ID-ul produsului.
 * @return ID-ul produsului ca string.
 */
string Product::getId() const {
    return productId;
}

/**
 * @brief Returneaza numele produsului.
 * @return Numele produsului ca string.
 */
string Product::getName() const {
    return name;
}

/**
 * @brief Returneaza pretul produsului.
 * @return Pretul produsului ca double.
 */
double Product::getPrice() const {
    return price;
}

/**
 * @brief Returneaza cantitatea din stoc a produsului.
 * @return Stocul produsului ca int.
 */
int Product::getStock() const {
    return stock;
}

/**
 * @brief Seteaza un nou pret pentru produs.
 *
 * @param newPrice Noul pret care va fi atribuit produsului.
 */
void Product::setPrice(double newPrice) {
    price = newPrice;
}

/**
 * @brief Seteaza un nou stoc pentru produs.
 *
 * @param newStock Noua valoare a stocului.
 */
void Product::setStock(int newStock) {
    stock = newStock;
}