#ifndef State_H
#define State_H

#include "Order.h"
#include "Menus.h"
class State {
    public:
        virtual void handleChange(Observer* observer) = 0;
        virtual string getState() = 0;
};

class Ordered : public State {
    public:
        void handleChange(Observer* observer) override;
        string getState() override;
};

class Preparing : public State {
    public:
        void handleChange(Observer* observer) override;
        string getState() override;
};

class Delivering : public State {
    public:
        void handleChange(Observer* observer) override;
        string getState() override;
};

class Delivered : public State {
    public:
        void handleChange(Observer* observer) override;
        string getState() override;
};

#endif