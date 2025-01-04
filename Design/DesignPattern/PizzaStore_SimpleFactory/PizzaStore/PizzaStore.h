#pragma once
#include "SimplePizzaFactory.h"

class PizzaStore
{
public:
	PizzaStore();
	~PizzaStore();
	void OrderPizza(int inPizzaID);
};

