//
//  Customer.hpp
//  HW 9
//
//  Created by Chase McDermott on 10/24/16.
//  Copyright © 2016 Chase McDermott. All rights reserved.
//

#ifndef customer_h
#define customer_h

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "product.h"

class Customer {
    
public:
    Customer(std::string name, int customerID, bool credit);
    std::string getName() const;
    
    // setters
    void setName(std::string name);
    void setCredit(bool hasCredit);
    
    // getters
    double getBalance() const;
    int getID() const;
    bool getCredit() const;
    void listProductsPurchased(std::ostream& os);

    void processPayment(double amount);
    void processPurchase(double amount, Product product);

private:
    int customerID = 0;
    std::string name;
    bool credit;  // means the customer's balance is allowed to become negative
    double balance = 0;
    std::vector<Product> productsPurchased;
    
    // private helper functions
    bool validAmount(double amount);
    bool validBalance(double amount);

    friend std::ostream& operator<<(std::ostream& os, const Customer& customer);
};



#endif /* Customer_hpp */





