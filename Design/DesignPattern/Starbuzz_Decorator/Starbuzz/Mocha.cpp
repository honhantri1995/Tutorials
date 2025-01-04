#include "Mocha.h"

Mocha::Mocha(Beverage* inBeverage)
{
	m_pBeverage = inBeverage;
	m_description = "Mocha";
	m_cost = 0.5;
}

Mocha::~Mocha()
{
}