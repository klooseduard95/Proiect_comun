//
// Created by Eduard-Andreas Kloos on 17.04.2025.
//

#include "ClientManagementUI.h"

#include <iostream>

using namespace std;

CustomerUI::CustomerUI(CustomerController& controller)
    : controller(controller) {}

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

void CustomerUI::handleListCustomers() {
    vector<Customer> customers = controller.listAllCustomersSorted();
    for (const auto& customer : customers) {
        cout << "Name: " << customer.getFirstName() << " " << customer.getLastName()
             << " | Email: " << customer.getEmail()
             << " | GDPR: " << (customer.isGdprDeleted() ? "Yes" : "No") << endl;
    }
}

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
