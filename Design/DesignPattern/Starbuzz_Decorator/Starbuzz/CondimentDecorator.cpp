#include "CondimentDecorator.h"

CondimentDecorator::CondimentDecorator()
{
}

CondimentDecorator::~CondimentDecorator()
{
}

std::string CondimentDecorator::GetDescription()
{
	return m_pBeverage->GetDescription() + " + " + m_description;
}

double CondimentDecorator::GetCost()
{
	return m_pBeverage->GetCost() + m_cost;
}