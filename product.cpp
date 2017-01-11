//
//  Product.cpp
//  HW 9
//
//  Created by Chase McDermott on 10/24/16.
//  Copyright © 2016 Chase McDermott. All rights reserved.
//

#include "product.h"
#include "customer.h"
#include <vector>
#include <stdexcept>
using namespace std;

Product::Product(int productID, std::string productName) : productID(productID), name(productName) {}

std::string Product::getDescription() const {
    return description;
}

void Product::setDescription(std::string description) {
    this->description = description;
}

std::string Product::getName() const {
    return name;
}

int Product::getID() const {
    return productID;
}

int Product::getNumberSold() const {
    return numSold;
}

double Product::getTotalPaid() const {
    return totalPaid;
}

int Product::getInventoryCount() const {
    return inventory;
}

double Product::getPrice()  {  //**********
    double price = 0;
    if (inventory + numSold <= 0) {
        return 0;
    }
    price = static_cast<double>(static_cast<double>(totalPaid) / (static_cast<double>(inventory) + static_cast<double>(numSold))) * 1.25;
    return price;
}

void Product::addShipment(int shipmentQuantity, double shipmentCost) {
    if (!validQuantity(shipmentQuantity, shipmentCost)) {
        throw runtime_error("Invalid shipment quantity.");
    }
    inventory += shipmentQuantity;
    totalPaid += shipmentCost;
}

void Product::reduceInventory(int purchaseQuantity) {
    
    if (!validPurchase(purchaseQuantity)) {
        throw runtime_error("Invalid purchase quantity amount.");
    }
    inventory -= purchaseQuantity;
    numSold += purchaseQuantity;
}

bool Product::validQuantity(int shipmentQuantity, double shipmentCost) {
    if (shipmentQuantity < 0 || shipmentCost < 0) {
        return false;
    } else {
        return true;
    }
    return true;
}

bool Product::validPurchase(int purchaseQuantity) {
    if (inventory < 1 || purchaseQuantity < 0 || purchaseQuantity > inventory) {
        return false;
    } else {
        return true;
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const Product& product) {
        os <<  product.getName() << " - " <<  product.getID() << endl;
    return os;
}




