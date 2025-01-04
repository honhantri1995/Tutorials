#include <iostream>
#include "PizzaStore.h"

using namespace std;

int main()
{
	int pizzaID;
	cout << "Our list of pizzas: " << endl
		 << "\t" << CHEESE_PIZZA << ". Cheese Pizza" << endl
		 << "\t" << VEGGIE_PIZZA << ". Veggie Pizza" << endl;
	cout << "Enter a pizza you want to eat: ";
	cin >> pizzaID;

	PizzaStore* pPizzaStore = new PizzaStore;
	pPizzaStore->OrderPizza(pizzaID);
	delete pPizzaStore;

	return 0;
}