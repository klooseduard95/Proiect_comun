#include "UserManagementUI.h"
#include "../domain/Validations/UserValidator.h"
#include <iostream>

using namespace std;

UserManagementUI::UserManagementUI(UserManagementController& controller, ProductController& productController, OrderController& orderController, CustomerController& customerController ,CustomerUI& customerUI, ProductUI& productUI, OrderManagementUI& orderUI)
    : userController(controller), productController(productController), orderController(orderController), customerController(customerController) ,customerUI(customerUI), productUI(productUI), orderUI(orderUI) {
    // initializeSampleData();
}

void UserManagementUI::startLoginFlow() {
    string email, password;
    cout << "Email: ";
    getline(cin, email);
    cout << "Password: ";
    getline(cin, password);

    try {
        User loggedInUser = userController.loginUser(email, password);
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
        cout << "3. Manage Orders\n"; // Orders Menu: 1. Change Status - submenu: complete, confirm
                                      //              2. Update Order - update order details
                                      //              3. Take Over Order - assign order to another employee
        cout << "0. Logout\n";
        int choice = getUserChoice();

        switch (choice) {
            case 0: return;
            case 1: customerUI.run(); break;
            case 2: productUI.showMenu(); break;
            case 3: orderUI.showManageOrdersMenu(loggedInUser); break;
            default: cout << "Invalid option.\n"; break;
        }
    }
}

void UserManagementUI::showCustomerMenu() {
    while (true) {
        cout << "\n--- Customer Menu ---\n";
        cout << "1. View Products\n"; // listAvailableProducts() in ProductController
        cout << "2. Modify Password\n";
        cout << "3. Create Reservation\n"; // order menu for customer -> createReservation() -> getter User.email in OrderController
        cout << "4. View Orders\n"; // submenu 2 - getOrdersForCustomer() in OrderController
                                    //           - getOrdersByStatus() in OrderController
        cout << "0. Logout\n";
        int choice = getUserChoice();

        switch (choice) {
            case 0: return;
            case 1: productController.listAvailableProducts(); break;
            case 2:
                    try {
                        string newPass = getNewPassword();
                        customerController.updatePassword(loggedInUser.getEmail(), newPass);
                        cout << "Password updated successfully.\n";
                    } catch (const exception& e) {
                        cout << "Error: " << e.what() << "\n";
                    }
                    break;
            case 3:
                orderUI.showCreateReservationMenu(loggedInCustomer);
                break;

            case 4:
                    orderUI.showCustomerOrders(loggedInUser);
                    break;
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

string UserManagementUI::getNewPassword() {
    cout << "\nEnter new password: ";
    string newPassword;
    cin.ignore();
    getline(cin, newPassword);
    if (newPassword.empty()) {
        throw invalid_argument("Password cannot be empty.");
    }
    return newPassword;
}
