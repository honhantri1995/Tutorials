#pragma once
#include "IPizza.h"

enum DEF_PIZZA
{
	CHEESE_PIZZA = 1,
	VEGGIE_PIZZA,
};

class SimplePizzaFactory
{
public:
	SimplePizzaFactory();
	~SimplePizzaFactory();
	IPizza* CreatePizza(int inPizzaID);
private:
	IPizza* m_pPizza;
};

