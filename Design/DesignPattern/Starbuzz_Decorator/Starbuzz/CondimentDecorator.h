#pragma once
#include "Beverage.h"
#include <string>

class CondimentDecorator : public Beverage
{
public:
	CondimentDecorator();
	~CondimentDecorator();
	virtual std::string GetDescription();
	virtual double GetCost();
protected:
	Beverage* m_pBeverage;
};

