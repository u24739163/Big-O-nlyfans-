#ifndef PIZZACOMPONENT_H
#define PIZZACOMPONENT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//PizzaComponent class
class PizzaComponent {
    public:
        virtual string getName() = 0;
        virtual double getPrice() = 0;
        virtual ~PizzaComponent() {};
    protected:
        string name;
        double price;
};

//PizzaComponent subclasses
class ToppingGroup : public PizzaComponent {
    public:
        ToppingGroup(string groupName);
        void add(PizzaComponent * component);
        string getName() override;
        double getPrice() override;
        ~ToppingGroup();
    private:
        vector<PizzaComponent*> toppings;
};

class Topping : public PizzaComponent {
    public:
        Topping(string name, double price);
        string getName() override;
        double getPrice() override;
};
#endif