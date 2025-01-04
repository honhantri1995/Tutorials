#pragma once
#include "IPizzaStore.h"

class ChicagoPizzaStore : public IPizzaStore
{
public:
	ChicagoPizzaStore();
	~ChicagoPizzaStore() override;
	IPizza* CreatePizza(PIZZA inPizzaID) override;

private:
	IPizza* m_Pizza;
};

