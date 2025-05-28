//
// Created by Eduard-Andreas Kloos on 20.05.2025.
//

#pragma once
#include "Order.h"
#include <stdexcept>

/**
 * @brief Clasa utilitara pentru validarea obiectelor de tip Order.
 *
 * Contine metode statice care verifica daca o comanda respecta anumite reguli
 * de business inainte de a fi procesata sau modificata.
 */
class OrderValidator {
public:
    /**
     * @brief Valideaza daca o comanda are statusul Reservation.
     *
     * @param order Comanda care trebuie validata.
     * @throws std::runtime_error daca statusul nu este Reservation.
     */
    static void validateStatusForReservation(const Order& order);
    /**
     * @brief Verifica daca o comanda poate fi confirmata.
     *
     * @param order Comanda care trebuie verificata.
     * @throws std::runtime_error daca comanda este deja finalizata.
     */
    static void validateBeforeConfirm(const Order& order);
    /**
     * @brief Verifica daca o comanda poate fi finalizata.
     *
     * Comanda trebuie sa fie in starea Confirmed si sa nu fie deja completata.
     *
     * @param order Comanda care trebuie verificata.
     * @throws std::runtime_error daca comanda nu este confirmata sau este deja finalizata.
     */
    static void validateBeforeComplete(const Order& order);
    /**
     * @brief Verifica daca o comanda poate fi modificata.
     *
     * Comenzile completate nu pot fi modificate, iar modificarile trebuie facute doar de acelasi angajat.
     *
     * @param existing Comanda existenta in sistem.
     * @param updated Comanda actualizata.
     * @throws std::runtime_error daca angajatii difera sau comanda este finalizata.
     */
    static void validateUpdatePermission(const Order& existing, const Order& updated);
};

