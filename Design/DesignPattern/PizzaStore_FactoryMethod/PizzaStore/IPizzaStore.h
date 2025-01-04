#pragma once

class IPizza;

enum class PIZZA
{
	CHEESE = 1,
	VEGGIE,
};

class IPizzaStore
{
public:
	IPizzaStore();
	virtual ~IPizzaStore();
	virtual IPizza* CreatePizza(PIZZA inPizzaID) = 0;
};

