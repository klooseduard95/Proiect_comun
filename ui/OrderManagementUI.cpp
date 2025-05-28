#include "OrderManagementUI.h"
#include <iostream>
#include <algorithm>

using namespace std;

OrderManagementUI::OrderManagementUI(OrderController& controller) : orderController(controller) {}

int OrderManagementUI::getUserChoice() const {
    int choice;
    cout << "Choice: ";
    cin >> choice;
    return choice;
}

void OrderManagementUI::printOrdersWithIndex(const vector<Order>& orders) const {
    int i = 1;
    for (const auto& o : orders) {
        cout << i++ << ". ID: " << o.getId()
             << " | Date: " << o.getOrderDate()
             << " | Status: " << static_cast<int>(o.getStatus())
             << " | Total: $" << o.getTotalPrice()
             << "\n";
    }
}

void OrderManagementUI::showManageOrdersMenu(const User& employee) {
    while (true) {
        cout << "\n--- Manage Orders ---\n";
        cout << "1. Change Order Status (Confirm/Complete)\n";
        cout << "2. Update Order\n";
        cout << "3. Take Over Order\n";
        cout << "0. Back\n";
        int choice = getUserChoice();

        vector<Order> allOrders = orderController.getOrdersByStatus(OrderStatus::Confirmed);
        if (allOrders.empty()) {
            cout << "No orders available.\n";
            return;
        }

        switch (choice) {
            case 0: return;

            case 1: {
                printOrdersWithIndex(allOrders);
                int idx = getUserChoice();
                if (idx >= 1 && idx <= allOrders.size()) {
                    string id = allOrders[idx - 1].getId();

                    cout << "1. Confirm\n2. Complete\n";
                    int statusChoice = getUserChoice();
                    if (statusChoice == 1)
                        orderController.confirmOrder(id);
                    else if (statusChoice == 2)
                        orderController.completeOrder(id);
                    else
                        cout << "Invalid choice.\n";
                } else {
                    cout << "Invalid selection.\n";
                }
                break;
            }

            case 2: {
                printOrdersWithIndex(allOrders);
                int idx = getUserChoice();
                if (idx >= 1 && idx <= allOrders.size()) {
                    Order existing = allOrders[idx - 1];
                    orderController.updateOrder(employee, existing);
                } else {
                    cout << "Invalid selection.\n";
                }
                break;
            }

            case 3: {
                printOrdersWithIndex(allOrders);
                int idx = getUserChoice();
                if (idx >= 1 && idx <= allOrders.size()) {
                    orderController.takeOverOrder(employee, allOrders[idx - 1].getId());
                    cout << "Order taken over successfully.\n";
                } else {
                    cout << "Invalid selection.\n";
                }
                break;
            }

            default:
                cout << "Invalid option.\n";
        }
    }
}

void OrderManagementUI::showCustomerOrders(const User& customer) {
    while (true) {
        cout << "\n--- View Orders ---\n";
        cout << "1. View All My Orders\n";
        cout << "2. Filter by Status\n";
        cout << "0. Back\n";
        int choice = getUserChoice();

        vector<Order> orders;

        switch (choice) {
            case 0: return;
            case 1:
                orders = orderController.getOrdersForCustomer(customer);
                break;
            case 2: {
                cout << "Enter status:\n0. Reservation\n1. Confirmed\n2. Completed\n";
                int status;
                cin >> status;
                auto allByStatus = orderController.getOrdersByStatus(static_cast<OrderStatus>(status));

                copy_if(allByStatus.begin(), allByStatus.end(), back_inserter(orders),
                    [&customer](const Order& o) {
                        return o.getCustomer().getId() == customer.getId();
                    });
                break;
            }
            default:
                cout << "Invalid option.\n";
                continue;
        }

        if (orders.empty()) {
            cout << "No orders found.\n";
        } else {
            printOrdersWithIndex(orders);
        }
    }
}

void OrderManagementUI::showCreateReservationMenu(const User& customer) {
    while (true) {
        cout << "\n--- Create Reservation Menu ---\n";
        cout << "1. View My Orders\n";
        cout << "2. Reserve an Order by Index\n";
        cout << "0. Back\n";

        int choice = getUserChoice();
        vector<Order> orders = orderController.getOrdersForCustomer(customer);

        switch (choice) {
            case 0:
                return;

            case 1:
                if (orders.empty()) {
                    cout << "No orders found.\n";
                } else {
                    printOrdersWithIndex(orders);
                }
                break;

            case 2:
                if (orders.empty()) {
                    cout << "No orders to reserve.\n";
                    break;
                }

                printOrdersWithIndex(orders);
                cout << "Select order index to reserve: ";
                int idx;
                cin >> idx;

                if (idx < 1 || idx > orders.size()) {
                    cout << "Invalid selection.\n";
                    break;
                }

                try {
                    Order orderToReserve = orders[idx - 1];
                    orderToReserve.setStatus(OrderStatus::Reservation);
                    orderController.createReservation(customer, orderToReserve);
                    cout << "Reservation successful.\n";
                } catch (const exception& e) {
                    cout << "Error: " << e.what() << "\n";
                }
                break;

            default:
                cout << "Invalid option.\n";
        }
    }
}
