#include "Milk.h"

Milk::Milk(Beverage* inBeverage)
{
	m_pBeverage = inBeverage;
	m_description = "Milk";
	m_cost = 0.25;
}

Milk::~Milk()
{
}