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

void ToppingGroup::add(PizzaComponent * component)
{
    toppings.push_back(component);
};

string ToppingGroup::getName()
{
    string out = name + " (";
    for(size_t i = 0; i < toppings.size(); i++) {
        out += toppings[i]->getName() + ", ";
    }
    out += ")";
    return out;
}

double ToppingGroup::getPrice()
{
    double total = 0;
    for(size_t i = 0; i < toppings.size(); i++) {
        total += toppings[i]->getPrice();
    }
    return total;
}

ToppingGroup::~ToppingGroup() {
    for(int i = 0; i < toppings.size(); i++) {
        delete toppings[i];
    }
    toppings.clear();
}

ToppingGroup::ToppingGroup(string groupName)
{
    this->name = groupName;
}
