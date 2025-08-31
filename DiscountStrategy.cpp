#include "DiscountStrategy.h"

class DiscountStrategy 
{
    public:
        virtual double applyDiscount()
        {
            return 0.0;
        };
};


class FamilyDiscount : public DiscountStrategy 
{
    public:
        double applyDiscount()
        {
            return 0.15;
        };
};

class RegularDiscount : public DiscountStrategy 
{
    public:
        double applyDiscount()
        {
            return 0.0;
        };
};

class BulkDiscount : public DiscountStrategy 
{
    public:
        double applyDiscount()
        {
            return 0.1;
        };
};