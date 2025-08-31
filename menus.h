#ifndef MENUS.H
#define MENUS.H

#include <string>
#include <vector>
#include <iostream>
#include "pizza.h"

class Menus {
    public:
        void addObserver(Observer* observer);
        void removeObserver(Observer* observer);
        void addPizza(Pizza * pizza);
        void removePizza(Pizza * pizza);
        virtual void notifyObserver(string message) = 0;
    protected:
        vector<Observer*> observers;    
        vector<Pizza*> pizzas;
};

class Observer {
    public:
      virtual void update(string message) = 0;  
    private:
};

class PizzaMenu : public Menus {
    public:
        void notifyObserver(string message); 
    private:
};

class SpecialMenu : public Menus {
    public:
        void notifyObserver(string message);
    private:
};

class Customer : public Observer {
    public:
        void update(string message);  
    private:
};

class Website : public Observer {
    public:
        void update(string message);  
    private:
};

#endif