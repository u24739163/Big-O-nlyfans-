#include "Menus.h"


void Menus::addObserver(Observer* observer)
{
    observers.push_back(observer);
}

void Menus::removeObserver(Observer* observer)
{
    observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
}

void Menus::addPizza(Pizza * pizza)
{
    pizzas.push_back(pizza);
    notifyObserver("New pizza added: " + pizza->getName());
}

void Menus::removePizza(Pizza * pizza)
{
    pizzas.erase(remove(pizzas.begin(), pizzas.end(), pizza), pizzas.end());
    notifyObserver("Pizza removed: " + pizza->getName());
}

void PizzaMenu::notifyObserver(string message)
{
    message = "Pizza Menu: " + message;
    for(int i = 0; i < observers.size(); i++) {
        observers[i]->update(message);
    }
}

void SpecialMenu::notifyObserver(string message)
{
    message = "Special Menu: " + message;
    for(int i = 0; i < observers.size(); i++) {
        observers[i]->update(message);
    }
}

void Customer::update(string message)
{
    cout << "Customer received update: " << message << endl;
}

void Website::update(string message)
{
    cout << "Website received update: " << message << endl;
}
