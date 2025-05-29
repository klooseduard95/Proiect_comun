#include "OrderManagementUI.h"
#include <iostream>
#include <algorithm>
#include <string.h>
#include <format>

using namespace std;

OrderManagementUI::OrderManagementUI(OrderController& controller, ProductController& productCtrl)
    : orderController(controller), productController(productCtrl) {} // ✅ Add this

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
        cout << "4. Show All Orders\n";
        cout << "5. Show Orders By Status\n";
        cout << "6. Show Total Price By Year\n";
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

            case 4: {
                vector<Order> orders = orderController.getOrdersForEmployee();
                for (int i = 0; i < orders.size(); i++) {
                    string status;
                    if (orders[i].getStatus() == OrderStatus::Confirmed) {
                        status = "Confirmed";
                    }
                    else if (orders[i].getStatus() == OrderStatus::Completed) {
                        status = "Completed";
                    }
                    else if (orders[i].getStatus() == OrderStatus::Reservation) {
                        status = "Reservation";
                    }
                    cout << "Order ID: " << orders[i].getId() << ", Date: " << orders[i].getOrderDate() << ", Status: " << status << "\n" << "Total Price: " << orders[i].getTotalPrice() << ".\n";
                }
                break;
            }

            case 5: {
                cout << "Enter status:\n0. Reservation\n1. Confirmed\n2. Completed\n";
                int status;
                cin >> status;
                auto allByStatus = orderController.getOrdersByStatus(static_cast<OrderStatus>(status));
                for (int i = 0; i < allByStatus.size(); i++) {
                    string status;
                    if (allByStatus[i].getStatus() == OrderStatus::Confirmed) {
                        status = "Confirmed";
                    }
                    else if (allByStatus[i].getStatus() == OrderStatus::Completed) {
                        status = "Completed";
                    }
                    else if (allByStatus[i].getStatus() == OrderStatus::Reservation) {
                        status = "Reservation";
                    }
                    cout << "Order ID: " << allByStatus[i].getId() << ", Date: " << allByStatus[i].getOrderDate() << ", Status: " << status << "\n" << "Total Price: " << allByStatus[i].getTotalPrice() << ".\n";
                }
                break;
            }

            case 6: {
                cout << "Please choose which time period you would like to know the total price for:\n"
                        "1. Year\n"
                        "2. Month\n";
                int choice1 = getUserChoice();
                string year;
                string month = "";
                if (choice1 == 1) {
                    cout << "Please introduce the year you are looking for: \n";
                    cin >> year;
                    pair <double,double> totalSum = orderController.getTotalSumForPeriod(year, month);
                    cout << "Total Price: " << totalSum.first << ".\n";
                }
                if (choice1 == 2) {
                    cout << "Please introduce the year and month you are looking for: \n";
                    cin >> year;
                    cin >> month;
                    pair <double,double> totalSum = orderController.getTotalSumForPeriod(year, month);
                    cout << "Total Price: " << totalSum.second << ".\n";
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
            case 1: {
                orders = orderController.getOrdersForCustomer(customer);
                for (int i = 0; i < orders.size(); i++) {
                    const auto& order = orders[i];

                    cout << "Order ID: " << order.getId() << "\n";
                    cout << "Date: " << order.getOrderDate() << "\n";
                    cout << "Status: ";

                    switch (order.getStatus()) {
                        case OrderStatus::Reservation:
                            cout << "Reservation";
                            break;
                        case OrderStatus::Confirmed:
                            cout << "Confirmed";
                            break;
                        case OrderStatus::Completed:
                            cout << "Completed";
                            break;
                        default:
                            cout << "Unknown";
                    }

                    cout << "\nTotal Price: " << order.getTotalPrice() << "\n";
                    cout << "---------------------------\n";
                }
                break;
            }

            case 2: {
                cout << "Enter status:\n0. Reservation\n1. Confirmed\n2. Completed\n";
                int status;
                cin >> status;

                auto allByStatus = orderController.getOrdersByStatus(static_cast<OrderStatus>(status));

                for (int i = 0; i < allByStatus.size(); i++) {
                    const auto& order = allByStatus[i];

                    cout << "Order ID: " << order.getId() << "\n";
                    cout << "Date: " << order.getOrderDate() << "\n";
                    cout << "Status: ";

                    // Print enum as string manually
                    switch (order.getStatus()) {
                        case OrderStatus::Reservation:
                            cout << "Reservation";
                            break;
                        case OrderStatus::Confirmed:
                            cout << "Confirmed";
                            break;
                        case OrderStatus::Completed:
                            cout << "Completed";
                            break;
                        default:
                            cout << "Unknown";
                    }

                    cout << "\nTotal Price: " << order.getTotalPrice() << "\n";
                    cout << "---------------------------\n";
                }

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

void OrderManagementUI::showCreateReservationMenu(const Customer& customer) {
    cout << "\n--- Creare Rezervare ---\n";

    productController.listAvailableProducts();

    vector<pair<Product, int>> selectedProducts;

    while (true) {
        cout << "\nIntrodu ID-ul produsului (sau 0 pentru a termina): ";
        string productId;
        cin >> productId;

        if (productId == "0") break;

        cout << "Introdu cantitatea: ";
        int qty;
        cin >> qty;

        if (qty <= 0) {
            cout << "Cantitate invalidă.\n";
            continue;
        }

        cout << "Introdu numele produsului (pt verificare): ";
        cin.ignore();
        string name;
        getline(cin, name);

        cout << "Introdu prețul unitar: ";
        double price;
        cin >> price;

        Product product(productId, name, price, qty);
        selectedProducts.emplace_back(product, qty);
    }

    if (selectedProducts.empty()) {
        cout << "Nicio rezervare creată.\n";
        return;
    }

    cout << "Introdu data comenzii (YYYY-MM-DD): ";
    string orderDate;
    cin >> orderDate;

    Employee dummy("x", "x", "x", "x", "x", "2000-01-01", 0.0);

    Order newOrder(orderDate, OrderStatus::Reservation, selectedProducts, customer, dummy);

    try {
        orderController.createReservation(customer, newOrder);
        cout << "Rezervare creată cu succes!\n";
    } catch (const std::exception& e) {
        cout << "Eroare la creare: " << e.what() << "\n";
    }
}

