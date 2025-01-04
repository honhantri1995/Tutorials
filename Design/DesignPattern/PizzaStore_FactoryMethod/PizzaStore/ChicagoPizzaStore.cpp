#include "ChicagoPizzaStore.h"
#include "CheesePizza.h"
#include "VeggiePizza.h"
#include "Utility.h"

ChicagoPizzaStore::ChicagoPizzaStore()
	: m_Pizza(nullptr)
{
}

ChicagoPizzaStore::~ChicagoPizzaStore()
{
	if (m_Pizza) {
		delete m_Pizza;
		m_Pizza = nullptr;
	}
}

IPizza* ChicagoPizzaStore::CreatePizza(PIZZA inPizzaID)
{
	switch (inPizzaID)
	{
	case PIZZA::CHEESE:
		m_Pizza = new CheesePizza;
		break;
	case PIZZA::VEGGIE:
		m_Pizza = new VeggiePizza;
		break;
	default:
		Utility::WriteDebugLogToFile(LOG_ERROR, "Sorry! We don't serve the pizza you're ordering.", __FUNCTION__, __LINE__);
		break;
	}

	return m_Pizza;
}
