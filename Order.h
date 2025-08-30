#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "pizza.h"
#include "DiscountStrategy.h"
#include "State.h"

class Order {
    private:
        vector<Pizza*> pizzas;
        DiscountStrategy* discountStrategy;
        State state;
}

#endif