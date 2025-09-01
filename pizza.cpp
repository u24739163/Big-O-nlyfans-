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

void ExtraCheese::printPizza()
{
    cout << "Pizza: " << getName() << endl;
    cout << "Price: " << getPrice() << endl;
}

string StuffedCrust::getName()
{
    return PizzaDecorator::getName() + " + (Stuffed Crust)";
}

double StuffedCrust::getPrice()
{
    return PizzaDecorator::getPrice() + 100;
}

void StuffedCrust::printPizza()
{
    cout << "Pizza: " << getName() << endl;
    cout << "Price: " << getPrice() << endl;
}

PizzaDecorator::~PizzaDecorator()
{
    delete basePizza;
}

void PizzaDecorator::printPizza()
{
    if (basePizza) {
        basePizza->printPizza();
    }
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

void BasePizza::printPizza()
{
    cout << "Pizza: " << getName() << endl;
    cout << "Price: " << getPrice() << endl;
}

BasePizza::~BasePizza()
{
    delete topping;
}
