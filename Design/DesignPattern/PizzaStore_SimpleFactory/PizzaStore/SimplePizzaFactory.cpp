#include "SimplePizzaFactory.h"
#include "CheesePizza.h"
#include "VeggiePizza.h"
#include <iostream>

SimplePizzaFactory::SimplePizzaFactory()
{
	m_pPizza = nullptr;
}

SimplePizzaFactory::~SimplePizzaFactory()
{
	delete m_pPizza;
}

IPizza* SimplePizzaFactory::CreatePizza(int inPizzaID)
{
	switch (inPizzaID)
	{
	case CHEESE_PIZZA:
		m_pPizza = new CheesePizza;
		break;
	case VEGGIE_PIZZA:
		m_pPizza = new VeggiePizza;
		break;
	default:
		std::cout << "Pizza is not found!" << std::endl;
		break;
	}

	return m_pPizza;
}
