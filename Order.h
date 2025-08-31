#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "pizza.h"
#include "DiscountStrategy.h"

class Order {
    public:
        Order();
        Order(DiscountStrategy* discountStrategy);
        void addPizza(Pizza* pizza);
        void removePizza(Pizza* pizza);
        void clearOrder();
        void calculateTotal(vector<Pizza*> pizzas);
        double applyDiscount();
    private:
        vector<Pizza*> pizzas;
        DiscountStrategy* discountStrategy;
};

#endif