#include "pizza.h"
PizzaDecorator::PizzaDecorator(Pizza * pizza)
{
    basePizza = pizza;
}

string PizzaDecorator::getName()
{
    if(basePizza) {
        return basePizza->getName();
    }
    return "No Pizza";
}

double PizzaDecorator::getPrice()
{
    if(basePizza) {
        return basePizza->getPrice();
    }
    return 0;
}

string ExtraCheese::getName()
{
    return PizzaDecorator::getName() + " + (Extra Cheese)";
}

double ExtraCheese::getPrice()
{
    return PizzaDecorator::getPrice() + 20;
}

string StuffedCrust::getName()
{
    return PizzaDecorator::getName() + " + (Stuffed Crust)";
}

double StuffedCrust::getPrice()
{
    return PizzaDecorator::getPrice() + 100;
}

PizzaDecorator::~PizzaDecorator()
{
    delete basePizza;
}
BasePizza::BasePizza(PizzaComponent * base)
{
    topping = base;
}

string BasePizza::getName()
{
    return topping->getName();
}

double BasePizza::getPrice()
{
    return topping->getPrice();
}
