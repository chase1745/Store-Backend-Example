//
//  Customer.cpp
//  HW 9
//
//  Created by Chase McDermott on 10/24/16.
//  Copyright © 2016 Chase McDermott. All rights reserved.
//

#include "customer.h"
#include "store.h"
#include "product.h"
#include <iostream>
#include <stdexcept>
#include <ostream>
using namespace std;

Customer::Customer(std::string name, int customerID, bool credit) : name(name), customerID(customerID), credit(credit) {}

std::string Customer::getName() const {
    return name;
}

void Customer::setName(std::string name) {
    this->name = name;
}

int Customer::getID() const {
    return customerID;
}

bool Customer::getCredit() const {
    return credit;
}

void Customer::setCredit(bool hasCredit) {
    credit = hasCredit;
}

double Customer::getBalance() const {
    return balance;
}

void Customer::listProductsPurchased(std::ostream& os) {
    for (int i = 0; i < productsPurchased.size(); ++i) {
        os <<(os,productsPurchased[i]) << endl;
    }
}

void Customer::processPayment(double amount) {  // adds amount payed to balance, throws exception if amount is negative
    if (!validAmount(amount)) {
        throw runtime_error("Invalid amount inputted.");
    } else {
        balance += amount;
    }
}

void Customer::processPurchase(double amount, Product product) {
    
    if (!validAmount(amount)) {
        throw runtime_error("Invalid amount inputted.");
    }
    if (getCredit()) {
        balance -= amount;
    } else {
        if (!validBalance(amount)) {throw runtime_error("Insuffecient funds.");}
        else {
            balance -= amount;
        }
    }
    
    productsPurchased.push_back(product);  // adds product to products purchased
}

bool Customer::validBalance(double amount) {
    if (amount > static_cast<double>(balance)) {
        return false;
    }
    return true;
}

bool Customer::validAmount(double amount) {
    if (amount < 0) {
        return false;
    }
    return true;
}

ostream& operator<<(std::ostream& os, const Customer& customer) {
    os <<  customer.getName() << " - " <<  customer.getID() << endl;
    return os;
}

