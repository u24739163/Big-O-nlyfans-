#ifndef State_H
#define State_H

#include "Order.h"

class State {
    public:
        virtual void handle();
        virtual void changeState();
    protected:
        Order order;
};

class Ordering : public State {
    public:
        void handle() override;
        void changeState() override;
};

class Preparing : public State {
    public:
        void handle() override;
        void changeState() override;
};

class Payment : public State {
    public:
    
        void handle() override;
        void changeState() override;
};

class Delivery : public State {
    public:
        void handle() override;
        void changeState() override;
};

#endif