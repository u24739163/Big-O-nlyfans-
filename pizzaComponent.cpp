#include "pizzaComponent.h"

Topping::Topping(string name, double price)
{
    this->name = name;
    this->price = price;
}

string Topping::getName()
{
    return name;
}

double Topping::getPrice()
{
    return price;
}

string PizzaComponent::getName()
{
    
}

double PizzaComponent::getPrice()
{
    
}

void ToppingGroup::add(PizzaComponent * component)
{
    
};

