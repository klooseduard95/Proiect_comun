//
// Created by Eduard-Andreas Kloos on 20.05.2025.
//

#include "OrderValidator.h"

/**
 * @brief Valideaza daca statusul comenzii este Reservation.
 *
 * @param order Comanda care trebuie validata
 * @throws std::runtime_error daca statusul nu este Reservation
 */
void OrderValidator::validateStatusForReservation(const Order& order) {
    if (order.getStatus() != OrderStatus::Reservation) {
        throw std::runtime_error("Order status must be Reservation when creating a reservation.");
    }
}

/**
 * @brief Verifica daca o comanda poate fi confirmata.
 *
 * @param order Comanda care trebuie validata
 * @throws std::runtime_error daca comanda este deja finalizata
 */
void OrderValidator::validateBeforeConfirm(const Order& order) {
    if (order.getStatus() == OrderStatus::Completed) {
        throw std::runtime_error("Cannot confirm a completed order.");
    }
}


/**
 * @brief Verifica daca o comanda poate fi finalizata.
 *
 * Comanda trebuie sa fie confirmata si sa nu fie deja finalizata.
 *
 * @param order Comanda care trebuie validata
 * @throws std::runtime_error daca comanda este deja finalizata sau nu este confirmata
 */
void OrderValidator::validateBeforeComplete(const Order& order) {
    if (order.getStatus() == OrderStatus::Completed) {
        throw std::runtime_error("Order is already completed.");
    }
    if (order.getStatus() != OrderStatus::Confirmed) {
        throw std::runtime_error("Only confirmed orders can be completed.");
    }
}

/**
 * @brief Verifica daca o comanda poate fi actualizata.
 *
 * Doar comenzile nefinalizate si care apartin aceluiasi angajat pot fi modificate.
 *
 * @param existing Comanda existenta in sistem
 * @param updated Comanda noua care ar trebui sa o inlocuiasca pe cea existenta
 * @throws std::runtime_error daca comanda este finalizata sau daca angajatul nu este acelasi
 */
void OrderValidator::validateUpdatePermission(const Order& existing, const Order& updated) {
    if (existing.getStatus() == OrderStatus::Completed) {
        throw std::runtime_error("Completed orders cannot be modified.");
    }
    if (existing.getEmployee().getId() != updated.getEmployee().getId()) {
        throw std::runtime_error("Employees can only update their own orders.");
    }
}


