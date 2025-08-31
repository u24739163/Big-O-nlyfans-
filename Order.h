#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "pizza.h"
#include "DiscountStrategy.h"

class Order {
    public:
        void addPizza(Pizza* pizza);
        void removePizza(Pizza* pizza);
        void clearOrder();
        void calculateTotal(vector<Pizza*> pizzas);
        void applyDiscount(DiscountStrategy* strategy);
    private:
        vector<Pizza*> pizzas;
        DiscountStrategy* discountStrategy;
};

#endif