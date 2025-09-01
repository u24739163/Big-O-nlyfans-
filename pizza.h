// pizza.h

#ifndef PIZZA_H
#define PIZZA_H

#include "pizzaComponent.h"

//Pizza class 
class Pizza {
    public:
        virtual Pizza* clone() const = 0;
        virtual string getName() = 0;
        virtual double getPrice() = 0;
        virtual void printPizza() = 0;
        virtual ~Pizza() {};
    private:
};

//Pizza subclasses
class BasePizza : public Pizza {
    public:
        BasePizza(PizzaComponent * base);
        BasePizza(const BasePizza& other);
        Pizza* clone() const override;
        string getName() override;
        double getPrice() override;
        void printPizza() override;
        virtual ~BasePizza();
    private:
        PizzaComponent * topping;
};

//PizzaDecorator
class PizzaDecorator : public Pizza {
    public:
        PizzaDecorator(Pizza * pizza);
        PizzaDecorator(const PizzaDecorator& other);
        Pizza* clone() const override;
        virtual string getName();
        virtual double getPrice();
        virtual void printPizza();
        virtual ~PizzaDecorator();
    private:
        Pizza * basePizza;
};

//PizzaDecorator subclasses
class ExtraCheese : public PizzaDecorator {
    public:
        ExtraCheese(Pizza * p) : PizzaDecorator(p) {}
        ExtraCheese(const ExtraCheese& other) : PizzaDecorator(other) {}
        Pizza* clone() const override;
        string getName() override;
        double getPrice() override;
        void printPizza() override;
};

class StuffedCrust : public PizzaDecorator {
    public:
        StuffedCrust(Pizza * p) : PizzaDecorator(p) {}
        StuffedCrust(const StuffedCrust& other) : PizzaDecorator(other) {}
        Pizza* clone() const override;
        string getName() override;
        double getPrice() override;
        void printPizza() override;
};

#endif