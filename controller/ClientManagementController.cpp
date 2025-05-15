#include "ClientManagementController.h"
#include <algorithm>
#include <stdexcept>

using namespace std;

CustomerController::CustomerController(IRepository<Customer>* repo)
    : customerRepository(repo) {}

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
//trebuie adaugat sa verifici daca are order!!!
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
