//
//  Product.hpp
//  HW 9
//
//  Created by Chase McDermott on 10/24/16.
//  Copyright © 2016 Chase McDermott. All rights reserved.
//

#ifndef product_h
#define product_h

#include <stdio.h>
#include <string>
#include <vector>

class Product {
public:
    Product(int productID, std::string productName);
    
    
    std::string getDescription() const;
    void setDescription(std::string description);
    
    std::string getName() const;
    int getID() const;

    int getNumberSold() const;
    double getTotalPaid() const;
    int getInventoryCount() const;
    double getPrice();

    void addShipment(int shipmentQuantity, double shipmentCost);
    void reduceInventory(int purchaseQuantity);

    
private:
    int productID = 0;
    std::string name;
    std::string description;
    int inventory = 0;
    int numSold = 0;
    double totalPaid = 0;
    
    // private helper functions
    bool validQuantity(int shipmentQuantity, double shipmentCost);
    bool validPurchase(int purchaseQuantity);
    
    friend std::ostream& operator<<(std::ostream& os, const Product& product);

};



#endif /* Product_hpp */
