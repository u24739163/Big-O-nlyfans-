#ifndef DISCOUNTSTRATEGY_H
#define DISCOUNTSTRATEGY_H

#include <vector>
#include <cmath>
#include "pizza.h"

class DiscountStrategy 
{
    protected:
        vector<Pizza*> pizzas;
    public:
        DiscountStrategy();
        virtual double applyDiscount();
};

class FamilyDiscount : public DiscountStrategy 
{
    public:
        double applyDiscount();
};

class RegularDiscount : public DiscountStrategy 
{
    public:
        double applyDiscount();
};

class BulkDiscount : public DiscountStrategy 
{
    public:
        BulkDiscount(std::vector<Pizza*> p);
        double applyDiscount();
};

#endif