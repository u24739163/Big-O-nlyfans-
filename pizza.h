#ifndef PIZZA.h
#define PIZZA.h

#include "pizzaComponet.h"

//Pizza class 
class Pizza {
    public:
        virtual double getPrice();
        virtual string getName();
        void printPizza();
    private:
};

//Pizza subclasses
class BasePizza : public Pizza{
    public:
        double getPrice();
        string getName();
    private:
        PizzaComponent topping;
};

class PizzaDecorator : public Pizza{
    public:
        virtual double getPrice();
        virtual string getName();
    private:
        Pizza pizza;
};

//PizzaDecorator subclasses
class ExtraCheese : public PizzaDecorator{
    public:
        double getPrice();
        string getName();
};

class StuffedCrust : public PizzaDecorator{
    public:
        double getPrice();
        string getName();
};

#endif