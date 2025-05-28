//
// Created by Eduard-Andreas Kloos on 17.04.2025.
//

#include "ClientManagementUI.h"

#include <iostream>

using namespace std;
/**
 * @file ClientManagementUI.h
 * @brief User Interface for Customer Management System
 */

/**
 * @class CustomerUI
 * @brief Provides console-based interface for customer management operations
 *
 * @details Handles all user interactions for customer CRUD operations,
 *          GDPR compliance actions, and customer data visualization.
 */

/**
     * @brief Constructs a CustomerUI with controller dependency
     * @param controller Reference to CustomerController for business logic
     */

CustomerUI::CustomerUI(CustomerController& controller)
    : controller(controller) {}

/**
     * @brief Displays the main menu options
     */
void CustomerUI::displayMenu() {
    cout << "\n--- Customer Management Menu ---\n";
    cout << "1. Create Customer\n";
    cout << "2. Update Customer\n";
    cout << "3. Delete Customer\n";
    cout << "4. Anonymize Customer (GDPR)\n";
    cout << "5. List All Customers\n";
    cout << "6. Find Customer by Email\n";
    cout << "0. Exit\n";
    cout << "Select an option: ";
}

/**
     * @brief Main application loop
     * @details Continuously displays menu and processes user input until exit
     */
void CustomerUI::run() {
    int option;
    do {
        displayMenu();
        cin >> option;
        cin.ignore();

        switch (option) {
            case 1: handleCreateCustomer(); break;
            case 2: handleUpdateCustomer(); break;
            case 3: handleDeleteCustomer(); break;
            case 4: handleAnonymizeCustomer(); break;
            case 5: handleListCustomers(); break;
            case 6: handleFindCustomer(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid option.\n"; break;
        }
    } while (option != 0);
}

/**
     * @brief Handles customer creation workflow
     * @details Collects all required customer data from user input
     * and attempts creation through controller
     */
void CustomerUI::handleCreateCustomer() {
    string email, password, firstName, lastName, address, note;
    bool gdprDeleted;

    cout << "Email: "; getline(cin, email);
    cout << "Password: "; getline(cin, password);
    cout << "First Name: "; getline(cin, firstName);
    cout << "Last Name: "; getline(cin, lastName);
    cout << "Address: "; getline(cin, address);
    cout << "Note (optional): "; getline(cin, note);
    cout << "GDPR Deleted (0 or 1): "; cin >> gdprDeleted; cin.ignore();

    bool success = controller.createCustomer(email, password, firstName, lastName, address, note, gdprDeleted);
    cout << (success ? "Customer created.\n" : "Failed to create customer.\n");
}

/**
     * @brief Handles customer update workflow
     * @details Allows partial updates of customer information
     * @throws std::exception if customer lookup fails
     */
void CustomerUI::handleUpdateCustomer() {
    string email;
    cout << "Enter customer email to update: ";
    getline(cin, email);

    try {
        Customer customer = controller.findCustomerByEmail(email);

        string firstName, lastName, address, note;
        bool gdprDeleted;

        cout << "New First Name: "; getline(cin, firstName);
        cout << "New Last Name: "; getline(cin, lastName);
        cout << "New Address: "; getline(cin, address);
        cout << "New Note: "; getline(cin, note);
        cout << "GDPR Deleted (0 or 1): "; cin >> gdprDeleted; cin.ignore();

        customer.setFirstName(firstName);
        customer.setLastName(lastName);
        customer.setAddress(address);
        customer.setNote(note);
        customer.setGdprDeleted(gdprDeleted);

        bool success = controller.updateCustomer(customer);
        cout << (success ? "Customer updated.\n" : "Failed to update customer.\n");

    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

/**
     * @brief Handles GDPR anonymization workflow
     * @details Permanently removes PII while maintaining referential integrity
     * @throws std::exception if anonymization fails
     */
void CustomerUI::handleDeleteCustomer() {
    string email;
    cout << "Enter customer email to delete: ";
    getline(cin, email);

    try {
        bool success = controller.deleteCustomer(email);
        cout << (success ? "Customer deleted.\n" : "Failed to delete customer.\n");
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

/**
     * @brief Handles GDPR anonymization workflow
     * @details Permanently removes PII while maintaining referential integrity
     * @throws std::exception if anonymization fails
     */
void CustomerUI::handleAnonymizeCustomer() {
    string email;
    cout << "Enter customer email to anonymize: ";
    getline(cin, email);

    try {
        bool success = controller.anonymizeCustomer(email);
        cout << (success ? "Customer anonymized.\n" : "Failed to anonymize customer.\n");
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}
/**
     * @brief Displays all customers in sorted order
     * @details Shows name, email and GDPR status in tabular format
     */
void CustomerUI::handleListCustomers() {
    vector<Customer> customers = controller.listAllCustomersSorted();
    for (const auto& customer : customers) {
        cout << "Name: " << customer.getFirstName() << " " << customer.getLastName()
             << " | Email: " << customer.getEmail()
             << " | GDPR: " << (customer.isGdprDeleted() ? "Yes" : "No") << endl;
    }
}
/**
    * @brief Handles customer lookup by email
    * @details Shows detailed customer information including address
    * @throws std::exception if customer not found
    */
void CustomerUI::handleFindCustomer() {
    string email;
    cout << "Enter customer email: ";
    getline(cin, email);

    try {
        Customer customer = controller.findCustomerByEmail(email);
        cout << "Name: " << customer.getFirstName() << " " << customer.getLastName()
             << " | Address: " << customer.getAddress()
             << " | GDPR: " << (customer.isGdprDeleted() ? "Yes" : "No") << endl;
    } catch (exception& e) {
        cout << "Customer not found: " << e.what() << endl;
    }
}
