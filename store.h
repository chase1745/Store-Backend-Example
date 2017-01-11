//
//  Store.hpp
//  HW 9
//
//  Created by Chase McDermott on 11/1/16.
//  Copyright © 2016 Chase McDermott. All rights reserved.
//

#ifndef store_h
#define store_h

#include "product.h"
#include "customer.h"
#include <stdio.h>
#include <vector>
#include <string>

class Store {
public:
    Store();
    Store(std::string name);
    
    std::string getName();
    void setName(std::string name);
    Product& getProduct(int productID);
    Customer& getCustomer(int customerID);
    void listProducts();
    void listCustomers();
    
    void takeShipment(int productID, int quantity, double cost);
    void makePurchase(int customerID, int productID, int quantity);
    void takePayment(int customerID, double amount);
    
    void addProduct(int productID, std::string productName);
    void addCustomer(int customerID, std::string customerName);
private:
    std::vector<Product> products;  // creates a vector of product objects
    std::vector<Customer> customers;  // creates a vector of customer objects
    std::string name;
    
    // private helper functions
    bool validProduct(int productID);  // checks to see if added product already exists
    bool validCustomer(int customerID);  //checks to see if added product already exists
};

#endif /* Store_h */
