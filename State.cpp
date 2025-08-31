#include "state.h"

void Ordered::handleChange(Observer* observer)
{
    observer->setState(new Preparing());
}
string Ordered::getState()
{
    return "Order is in the Ordered state.";
}

void Preparing::handleChange(Observer* observer)
{
    observer->setState(new Delivering());
}
string Preparing::getState()
{
    return "Order is being prepared.";
}

void Delivering::handleChange(Observer* observer)
{
    observer->setState(new Delivered());
}
string Delivering::getState()
{
    return "Order is out for delivery.";
}

void Delivered::handleChange(Observer* observer)
{
    observer->setState(new Delivered());
}
string Delivered::getState()
{
    return "Order has been delivered.";
}

