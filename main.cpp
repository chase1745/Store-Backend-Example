//
//  main.cpp
//  HW 9
//
//  Created by Chase McDermott on 10/24/16.
//  Copyright © 2016 Chase McDermott. All rights reserved.
//

#include <iostream>
#include "product.h"
#include "customer.h"
#include "store.h"
using namespace std;

int main() {
    
    Store s{"Walmart"};
    s.addProduct(123, "Chase");
    s.addProduct(1275, "johnny");
    return 0;
}
