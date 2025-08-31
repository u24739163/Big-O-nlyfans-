#ifndef DISCOUNTSTRATEGY_H
#define DISCOUNTSTRATEGY_H

#include <vector>
#include "pizza.h"

class DiscountStrategy 
{
    public:
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
        double applyDiscount();
};

#endif