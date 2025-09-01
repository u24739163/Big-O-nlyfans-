#include "Menus.h"


void Menus::addObserver(Observer* observer)
{
    observers.push_back(observer);
}

void Menus::removeObserver(Observer* observer)
{
    for (auto it = observers.begin(); it != observers.end(); ++it) {
        if (*it == observer) {
            observers.erase(it);
            break;  // Remove only the first occurrence
        }
    }
}

void Menus::addPizza(Pizza * pizza)
{
    pizzas.push_back(pizza);
    notifyObserver("New pizza added: " + pizza->getName());
}

void Menus::removePizza(Pizza * pizza)
{
    for (auto it = pizzas.begin(); it != pizzas.end(); ++it) {
        if (*it == pizza) {
            pizzas.erase(it);
            break;  // Remove only the first occurrence
        }
    }
    notifyObserver("Pizza removed: " + pizza->getName());
}

// void Observer::setState(State* state)
// {
//     this->state = state;
// }

// string Observer::getState()
// {
//     return state->getState();
// }

// void Observer::changeState()
// {
//     state->handleChange(this);
// }

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
    //changeState();
    cout << "Customer received update: " << message << endl;
}

void Website::update(string message)
{
    //changeState();
    cout << "Website received update: " << message << endl;
}

Menus::~Menus()
{
    observers.clear();
    // for(int i = 0; i < observers.size(); i++)
    // {
    //     delete observers[i];
    // }
    for (int i = 0; i < pizzas.size(); i++) {
        delete pizzas[i];
    }
    pizzas.clear();
}
