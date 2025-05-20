#include "UserManagementUI.h"
#include "../domain/Validations/UserValidator.h"
#include <iostream>

using namespace std;

UserManagementUI::UserManagementUI(UserManagementController& controller)
    : controller(controller) {
    // initializeSampleData();
}

void UserManagementUI::startLoginFlow() {
    string email, password;
    cout << "Email: ";
    getline(cin, email);
    cout << "Password: ";
    getline(cin, password);

    try {
        User loggedInUser = controller.loginUser(email, password);
        cout << "\nLogin successful! Welcome, " << loggedInUser.getEmail() << ".\n";
        showUserMenu(loggedInUser);
    } catch (const exception& e) {
        cerr << "Login failed: " << e.what() << "\n";
    }
}

void UserManagementUI::showUserMenu(const User& user) {
    if (UserValidator::isEmployee(user.getRole())) {
        showEmployeeMenu();
    } else if (UserValidator::isCustomer(user.getRole())) {
        showCustomerMenu();
    } else {
        cerr << "Invalid user role.\n";
    }
}

void UserManagementUI::showEmployeeMenu() {
    while (true) {
        cout << "\n--- Employee Menu ---\n";
        cout << "1. Manage Customers\n";
        cout << "2. Manage Products\n";
        cout << "3. Manage Orders\n";
        cout << "0. Logout\n";
        int choice = getUserChoice();

        switch (choice) {
            case 0: return;
            case 1: /*manageCustomers()*/; break;
            case 2: /*manageProducts()*/; break;
            case 3: /*manageOrders()*/; break;
            default: cout << "Invalid option.\n"; break;
        }
    }
}

void UserManagementUI::showCustomerMenu() {
    while (true) {
        cout << "\n--- Customer Menu ---\n";
        cout << "1. View Products\n";
        cout << "2. Modify Profile\n";
        cout << "3. Create Reservation\n";
        cout << "4. View Orders\n";
        cout << "0. Logout\n";
        int choice = getUserChoice();

        switch (choice) {
            case 0: return;
            case 1: /*viewProducts()*/; break;
            case 2: /*modifyProfile()*/; break;
            case 3: /*createReservation()*/; break;
            case 4: /*viewOrders()*/; break;
            default: cout << "Invalid option.\n"; break;
        }
    }
}

int UserManagementUI::getUserChoice() {
    int choice;
    cout << "\nEnter your choice: ";
    while (!(cin >> choice)) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Invalid input. Please enter a number: ";
    }
    return choice;
}