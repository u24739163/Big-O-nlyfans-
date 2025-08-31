#include <iostream>
#include "pizzaComponent.h"
#include "pizza.h"
#include "Order.h"
using namespace std;

int main() {
    Topping* t1 = new Topping("Dough",10);
    Topping* t2 = new Topping("Sauce",10);
    Topping* t3 = new Topping("Cheese",10);
    Topping* t4 = new Topping("Pineapple",10);

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
    
    //Decorating the pizza
    ExtraCheese* pizzaWithExtras = new ExtraCheese(new StuffedCrust (new BasePizza(complexPizza)));
    
    //Printing the new decorated pizza
    cout << pizzaWithExtras->getName() << endl;
    cout << "Total price: " << pizzaWithExtras->getPrice() << endl;
    

    //The pizza to be decorated
    BasePizza* pizza = new BasePizza(complexPizza);
    BasePizza* pizza2 = new BasePizza(simplePizza);
    
    //adding pizza's to order
    Order* orderUp = new Order();
    orderUp->addPizza(pizza);
    orderUp->addPizza(pizza2);
    orderUp->addPizza(pizzaWithExtras);

    delete simplePizza; 
    delete complexPizza;
    delete pizzaWithExtras;
    delete pizza;
    delete pizza2;
    delete orderUp;
    
    return 0;
}