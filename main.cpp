#include <iostream>
#include "pizzaComponent.h"
using namespace std;

int main() {
    Topping* t1 = new Topping("dough",10);
    Topping* t2 = new Topping("sauce",10);
    Topping* t3 = new Topping("cheese",10);
    Topping* t4 = new Topping("pinapple",10);

    ToppingGroup* simplePizza = new ToppingGroup("simplePizza"); // Initialize with new
    
    simplePizza->add(t1);
    simplePizza->add(t2);
    simplePizza->add(t3);
    simplePizza->add(t4);

    ToppingGroup* complexPizza = new ToppingGroup("complexPizza");

    complexPizza->add(t1);
    complexPizza->add(t2);
    complexPizza->add(simplePizza);
    complexPizza->add(t4);

    cout << complexPizza->getName() << endl;
    cout << "Total price: " << complexPizza->getPrice() << endl;
    

    delete simplePizza; 
    
    return 0;
}