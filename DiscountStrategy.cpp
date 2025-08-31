#include "DiscountStrategy.h"

DiscountStrategy::DiscountStrategy()
{
}

DiscountStrategy::~DiscountStrategy()
{
}

double DiscountStrategy::applyDiscount()
{
    return 0.0;
};

double FamilyDiscount::applyDiscount()
{
    return 0.15;
};

double RegularDiscount::applyDiscount()
{
    return 0.0;
};

BulkDiscount::BulkDiscount(vector<Pizza*> p)
{
    pizzas = p;
}

double BulkDiscount::applyDiscount()
{
    double answer = floor(pizzas.size() / 5);
    return answer * 0.1;
};