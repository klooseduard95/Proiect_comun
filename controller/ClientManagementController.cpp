#include "ClientManagementController.h"
#include <algorithm>
#include <stdexept>
#include <unordered_set>

using namespace std;

CustomerController::CustomerController(IRepository<Customer>* repo, OrderController& orderCtrl)
    : customerRepository(repo), orderController(orderCtrl) {}

bool CustomerController::createCustomer(const string& email, const string& password,
                                        const string& firstName, const string& lastName,
                                        const string& address, const string& note,
                                        bool gdprDeleted) {
    try {
        Customer customer(email, password, firstName, lastName, address, note, gdprDeleted);
        customerRepository->add(customer);
        return true;
    } catch (...) {
        return false;
    }
}

bool CustomerController::updateCustomer(const Customer& updatedCustomer) {
    try {
        customerRepository->update(updatedCustomer);
        return true;
    } catch (...) {
        return false;
    }
}
bool CustomerController::deleteCustomer(const string& email) {
    try {
        customerRepository->remove(email);
        return true;
    } catch (...) {
        return false;
    }
}

vector<Customer> CustomerController::listAllCustomersSorted() const {
    vector<Customer> customers = customerRepository->getAll();
    sort(customers.begin(), customers.end(), [](const Customer& a, const Customer& b) {
        if (a.getLastName() == b.getLastName())
            return a.getFirstName() < b.getFirstName();
        return a.getLastName() < b.getLastName();
    });
    return customers;
}

Customer CustomerController::findCustomerByEmail(const string& email) const {
    return customerRepository->getById(email);
}

vector<Customer> CustomerController::getCustomersByProductSorted(const string& productId) const {
    vector<Order> orders = orderController.getOrdersByStatus(OrderStatus::Completed);
    vector<pair<Customer, string>> matching;

    for (const auto& order : orders) {
        for (const auto& item : order.getProducts()) {
            if (item.first.getId() == productId) {
                matching.emplace_back(order.getCustomer(), order.getOrderDate());
                break;
            }
        }
    }

    sort(matching.begin(), matching.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    vector<Customer> result;
    unordered_set<string> seen;

    for (const auto& [customer, _] : matching) {
        if (seen.insert(customer.getId()).second) {
            result.push_back(customer);
        }
    }

    return result;
}
