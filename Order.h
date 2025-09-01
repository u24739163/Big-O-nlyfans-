#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "pizza.h"
#include "DiscountStrategy.h"
#include "state.h"

class Order {
    public:
        Order();
        ~Order();
        Order(DiscountStrategy* discountStrategy);
        void addPizza(Pizza* pizza);
        void removePizza(Pizza* pizza);
        void clearOrder();
        void calculateTotal();
        double applyDiscount();
        //State things
        void setState(State* state);
        string getState();
        void changeState();
    private:
        State * state;
        vector<Pizza*> pizzas;
        DiscountStrategy* discountStrategy;
};

#endif