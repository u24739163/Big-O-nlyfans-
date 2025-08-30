#ifndef DISCOUNTSTRATEGY_H
#define DISCOUNTSTRATEGY_H

class DiscountStrategy {
    public:
        virtual double applyDiscount() = 0;
};

class FamilyDiscount : public DiscountStrategy {
    public:
        double applyDiscount();
};

class RegularDiscount : public DiscountStrategy {
    public:
        double applyDiscount();
};

class BulkDiscount : public DiscountStrategy {
    public:
        double applyDiscount();
};

#endif