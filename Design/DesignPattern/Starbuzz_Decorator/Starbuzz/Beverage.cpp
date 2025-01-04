#include "Beverage.h"

Beverage::Beverage()
{
	m_description = "Unknown Beverage";
	m_cost = 0;
}

Beverage::~Beverage()
{
}

std::string Beverage::GetDescription()
{
	return m_description;
}

double Beverage::GetCost()
{
	return m_cost;
}
