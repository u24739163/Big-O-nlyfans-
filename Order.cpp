#include "Order.h"

vector<Pizza*> pizzas;
DiscountStrategy* discountStrategy;

Order::Order()
{
    discountStrategy = new RegularDiscount();
    vector<Pizza*> pizzas;
}

Order::Order(DiscountStrategy* discountStrategy)
{
    discountStrategy = new RegularDiscount();
    vector<Pizza*> pizzas;
}

void Order::addPizza(Pizza* pizza)
{
    pizzas.push_back(pizza);
    if (pizzas.size() >= 5) 
    {
        delete discountStrategy;
        discountStrategy = new BulkDiscount(this->pizzas);
    }
    else 
    {
        delete discountStrategy;
        discountStrategy = new RegularDiscount();
    }
};

void removePizza(Pizza* pizza)
{
    for (int i = 0; i < pizzas.size(); i++) 
    {
        if (pizzas[i] == pizza) 
        {
            pizzas.erase(pizzas.begin() + i);
            break; //otherwise will erase multiple instances of that kind of pizza :)
        }
    }
    if (pizzas.size() < 5) 
    {
        delete discountStrategy;
        discountStrategy = new RegularDiscount();
    }
    else
    {
        delete discountStrategy;
        discountStrategy = new BulkDiscount(pizzas);
    }
};

void clearOrder()
{
    pizzas.clear();
};

double applyDiscount()
{
    
    return discountStrategy->applyDiscount();

};

void calculateTotal(vector<Pizza*> pizzas)
{
    double total = 0.0;
    for (int i = 0; i < pizzas.size(); i++) 
    {
        total += pizzas[i]->getPrice();
    
    }
    std::cout << "Total price after discount: " << total << "\n";
    std::cout << "Total price after discount: " << total - (total * applyDiscount()) << "\n";
};
