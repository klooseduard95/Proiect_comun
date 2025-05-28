#include "ClientManagementController.h"
#include <algorithm>
#include <unordered_set>

using namespace std;

/**
 * @file ClientManagementController.h
 * @brief Controller for managing customer operations.
 */

/**
 * @class CustomerController
 * @brief Handles customer-related operations including creation, update, deletion, and queries.
 */
/**
     * @brief Constructs a CustomerController with dependencies.
     * @param repo Pointer to customer repository
     * @param orderCtrl Pointer to order controller
     */
CustomerController::CustomerController(IRepository<Customer>* repo, OrderController* orderCtrl)
    : customerRepository(repo),orderController(orderCtrl) {}
/**
     * @brief Creates a new customer.
     * @param email Customer's email (unique identifier)
     * @param password Customer's password
     * @param firstName Customer's first name
     * @param lastName Customer's last name
     * @param address Customer's physical address
     * @param note Additional notes about customer
     * @param gdprDeleted GDPR compliance flag
     * @return true if creation succeeded, false otherwise
     */
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
/**
     * @brief Updates an existing customer.
     * @param updatedCustomer Customer object with updated data
     * @return true if update succeeded, false otherwise
     */
bool CustomerController::updateCustomer(const Customer& updatedCustomer) {
    try {
        customerRepository->update(updatedCustomer);
        return true;
    } catch (...) {
        return false;
    }
}
/**
     * @brief Deletes a customer if they have no orders.
     * @param email Customer's email identifier
     * @return true if deletion succeeded, false if customer has orders or operation failed
     */
bool CustomerController::deleteCustomer(const string& email) {
    Customer customer = customerRepository->getById(email);
    if (orderController->getOrdersForCustomer(customer).size()==0)
        return false;
    try {
        customerRepository->remove(email);
        return true;
    } catch (...) {
        return false;
    }
}
/**
     * @brief Retrieves all customers sorted by last name (then first name).
     * @return Vector of customers in alphabetical order
     */
vector<Customer> CustomerController::listAllCustomersSorted() const {
    vector<Customer> customers = customerRepository->getAll();
    sort(customers.begin(), customers.end(), [](const Customer& a, const Customer& b) {
        if (a.getLastName() == b.getLastName())
            return a.getFirstName() < b.getFirstName();
        return a.getLastName() < b.getLastName();
    });
    return customers;
}
/**
    * @brief Finds a customer by email.
    * @param email Customer's unique email identifier
    * @return Customer object
    * @throws RepositoryException if customer not found
    */
Customer CustomerController::findCustomerByEmail(const string& email) const {
    return customerRepository->getById(email);
}
/**
     * @brief Anonymizes customer data for GDPR compliance.
     * @param email Customer's email identifier
     * @return true if anonymization succeeded, false otherwise
     */
bool CustomerController::anonymizeCustomer(const string& email) {
    try {
        Customer customer = customerRepository->getById(email);

        string anonymizedName = "Customer-" + customer.getId();

        customer.setLastName(anonymizedName);
        customer.setFirstName("Unknown");
        customer.setEmail("");
        customer.setAddress("");
        customer.setNote("");
        customer.setGdprDeleted(true);

        customerRepository->update(customer);
        return true;
    } catch (...) {
        return false;
    }
}

/**
     * @brief Gets customers who purchased a specific product, sorted by most recent order.
     * @param productId Product identifier
     * @return Vector of unique customers sorted by purchase recency
     */
vector<Customer> CustomerController::getCustomersByProductSorted(const string& productId) const {
    vector<Order> orders = orderController->getOrdersByStatus(OrderStatus::Completed);
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
/**
     * @brief Updates a customer's password.
     * @param email Customer's email identifier
     * @param password New password
     * @throws RepositoryException if customer not found
     */
void CustomerController::updatePassword(const string& email, const string& password) const {
        customerRepository->getById(email).setPassword(password);
}
