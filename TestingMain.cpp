#include <iostream>
#include "pizzaComponent.h"
#include "pizza.h"
#include "State.h"
#include "Order.h"
#include "Menus.h"

using namespace std;

int main() {
    // Topping* t1 = new Topping("Dough",10);
    // Topping* t2 = new Topping("Sauce",10);
    // Topping* t3 = new Topping("Cheese",10);
    // Topping* t4 = new Topping("Pineapple",10);

    // ToppingGroup* simplePizza = new ToppingGroup("simplePizza"); // Initialize with new
    // simplePizza->add(new Topping("Dough",10));
    // simplePizza->add(new Topping("Sauce",10));
    // simplePizza->add(new Topping("Cheese",10));
    // simplePizza->add(new Topping("Pineapple",10));
    
    // ToppingGroup* complexPizza = new ToppingGroup("complexPizza");

    // //complexPizza->add(t1);
    // //complexPizza->add(t2);
    // complexPizza->add(simplePizza);
    // complexPizza->add(new Topping("Pineapple",10));
    
    // //Decorating the pizza
    // ExtraCheese* pizzaWithExtras = new ExtraCheese(new StuffedCrust (new BasePizza(complexPizza)));
    
    // //Printing the new decorated pizza
    // cout << pizzaWithExtras->getName() << endl;
    // cout << "Total price: " << pizzaWithExtras->getPrice() << endl;

    ToppingGroup* pepperoni = new ToppingGroup("Pepperoni");
    pepperoni->add(new Topping("Dough",10));
    pepperoni->add(new Topping("Cheese",10));
    pepperoni->add(new Topping("Sauce",10));
    pepperoni->add(new Topping("Pepperoni",20));
    
    ToppingGroup* vegetarian = new ToppingGroup("Vegetarian");
    vegetarian->add(new Topping("Dough",10));
    vegetarian->add(new Topping("Cheese",10));
    vegetarian->add(new Topping("Sauce",10));
    vegetarian->add(new Topping("Mushrooms",10));
    vegetarian->add(new Topping("Green Peppers",10));
    vegetarian->add(new Topping("Onions",10));


    ToppingGroup* meatLovers = new ToppingGroup("Meat Lovers");
    meatLovers->add(pepperoni->clone());
    meatLovers->add(new Topping("Beef Sausage",30));
    meatLovers->add(new Topping("Salami",20));

    ToppingGroup* vegetarianDeluxe = new ToppingGroup("Vegetarian Deluxe");
    vegetarianDeluxe->add(vegetarian->clone());
    vegetarianDeluxe->add(new Topping("Feta Cheese",15));
    vegetarianDeluxe->add(new Topping("Olives",15));

    //The pizza to be decorated
    BasePizza* pepperoniBase = new BasePizza(pepperoni->clone());
    BasePizza* vegetarianBase = new BasePizza(vegetarian->clone());
    BasePizza* meatLoversBase = new BasePizza(meatLovers->clone());
    BasePizza* vegetarianDeluxeBase = new BasePizza(vegetarianDeluxe->clone());
    //ExtraCheese* extraPizza = new ExtraCheese(new StuffedCrust (new BasePizza(vegetarianDeluxe->clone())));

    //adding pizza's to order
    Order* orderUp = new Order();
    orderUp->addPizza(pepperoniBase);
    orderUp->addPizza(vegetarianBase);
    orderUp->addPizza(meatLoversBase);
    orderUp->addPizza(vegetarianDeluxeBase);
    orderUp->addPizza(new ExtraCheese(new StuffedCrust (vegetarianDeluxeBase->clone())));

    orderUp->printOrder();

    // pepperoniBase->printPizza();
    // vegetarianBase->printPizza();
    // meatLoversBase->printPizza();
    // vegetarianDeluxeBase->printPizza();
    // extraPizza->printPizza();

    orderUp->calculateTotal();
    // orderUp->removePizza(pizza3);
    // orderUp->removePizza(pizza4);

    // orderUp->calculateTotal();
    // delete simplePizza; 
    // delete complexPizza;
    // delete t1;
    // delete t2;
    // delete t3;
    // delete t4;
    //delete simplePizza;
    //delete complexPizza;
    //delete pizzaWithExtras;
    //delete pizza;
    // delete pizza2;
    //delete orderUp;
    delete pepperoni;
    delete vegetarian;
    delete meatLovers;
    delete vegetarianDeluxe;
    delete orderUp;
    
    return 0;
}