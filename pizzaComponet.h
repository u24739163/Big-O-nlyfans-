#ifndef PIZZACOMPONENT.h
#define PIZZACOMPONENT.h

#include <iostream>
#include <string>
using namespace std;

//PizzaComponent class
class PizzaComponent {
    public:
        virtual string getName();
        virtual double getPrice();
    private:
        string name;
        double price;
};

//PizzaComponent subclasses
class ToppingGroup : public PizzaComponent {
    public:
        void add(PizzaComponent component);
    private:
        PizzaComponent * toppings;
};

class Topping : public PizzaComponent {
    public:
        Topping(string name, double price);
        string getName();
        double getPrice();
    private:
        string name;
        double price;
};
#endif