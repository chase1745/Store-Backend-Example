//
//  Store.cpp
//  HW 9
//
//  Created by Chase McDermott on 11/1/16.
//  Copyright © 2016 Chase McDermott. All rights reserved.
//

#include "store.h"
#include "product.h"
#include "customer.h"
#include <stdexcept>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

Store::Store() : name("No name.") {}

Store::Store(string name) : name(name) {}
    
string Store::getName() {
    return name;
}

void Store::setName(std::string name) {
    this->name = name;
}



void Store::addProduct(int productID, string productName) {  // adds a product to the products vector
    if (!validProduct(productID)) {
        throw runtime_error("Product already in datbase.");
    }
    
    Product product{productID, productName};
    products.push_back(product);
}

void Store::addCustomer(int customerID, string customerName) {  // adds a customer to the customers vector
    if (!validCustomer(customerID)) {
        throw runtime_error("Customer already in datbase.");
    }
    
    Customer customer{customerName, customerID, false};
    customers.push_back(customer);
}



bool Store::validProduct(int productID) {
    for (int i = 0; i < products.size(); ++i) {  // checks to see if product is in database or not
        if (products[i].getID() == productID) {
            return false;
        }
    }
    return true;
}

bool Store::validCustomer(int customerID) {
    for (int i = 0; i < customers.size(); ++i) {  // checks to see if customer is in database or not
        if (customers[i].getID() == customerID) {
            return false;
        }
    }
    return true;
}

Product& Store::getProduct(int productID) {  // returns the product given by productID
    for (int i = 0; i < products.size(); ++i) {
        if (products[i].getID() == productID) {return products[i];}
    }
    throw runtime_error("Product doesn't exist.");
}

Customer& Store::getCustomer(int customerID) {  // returns the customer given by customerID
    for (int i = 0; i < customers.size(); i++) {
        if (customers[i].getID() == customerID) {return customers[i];}
    }
    throw runtime_error("Customer doesn't exist.");
}

void Store::takeShipment(int productID, int quantity, double cost) {  // find product and update with quantity and cost
    getProduct(productID).addShipment(quantity, cost);
}

void Store::makePurchase(int customerID, int productID, int quantity) {  // make a purchase by a customer (reduce inventory, proccessPurchase)
    getCustomer(customerID);  // check to make sure customer exists
    getProduct(productID);  // check to make sure product exists
    getCustomer(customerID).processPurchase(getProduct(productID).getPrice(), getProduct(productID));
    getProduct(productID).reduceInventory(quantity);
}


void Store::takePayment(int customerID, double amount) {  // find customer and proeccess payment
    getCustomer(customerID);
    getCustomer(customerID).processPayment(amount);
}

void Store::listProducts() {  // output info about each product (<< overload)
    for (int i = 0; i < products.size(); i++) {
        cout <<(cout, products[i]) << endl;
    }
}

void Store::listCustomers() {  // output info about customer (<< overload)
    for (int i = 0; i < customers.size(); i++) {
        cout <<(cout, customers[i]) << endl;
    }
}
