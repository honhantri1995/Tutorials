#include "PizzaStore.h"

PizzaStore::PizzaStore()
{
}

PizzaStore::~PizzaStore()
{
}

void PizzaStore::OrderPizza(int inPizzaID)
{
	IPizza* pPizza = nullptr;
	SimplePizzaFactory* pPizzaFactory = new SimplePizzaFactory;
	pPizza = pPizzaFactory->CreatePizza(inPizzaID);
	pPizza->Prepare();
	pPizza->Bake();
	pPizza->Cut();
	pPizza->Box();
	delete pPizzaFactory;
}
