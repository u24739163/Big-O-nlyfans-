#ifndef PIZZA_H
#define PIZZA_H

#include "pizzaComponent.h"

//Pizza class 
class Pizza {
    public:
        virtual string getName() = 0;
        virtual double getPrice() = 0;
        void printPizza();
        virtual ~Pizza() {};
    private:
};

//Pizza subclasses
class BasePizza : public Pizza {
    public:
        BasePizza(PizzaComponent * base);
        string getName() override;
        double getPrice() override;
        virtual ~BasePizza();
    private:
        PizzaComponent * topping;
};

//PizzaDecorator
class PizzaDecorator : public Pizza {
    public:
        PizzaDecorator(Pizza * pizza);
        virtual string getName();
        virtual double getPrice();
        virtual ~PizzaDecorator();
    private:
        Pizza * basePizza;
};

//PizzaDecorator subclasses
class ExtraCheese : public PizzaDecorator {
    public:
        ExtraCheese(Pizza * p) : PizzaDecorator(p) {}
        string getName() override;
        double getPrice() override;
};

class StuffedCrust : public PizzaDecorator {
    public:
        StuffedCrust(Pizza * p) : PizzaDecorator(p) {}
        string getName() override;
        double getPrice() override;
};

#endif