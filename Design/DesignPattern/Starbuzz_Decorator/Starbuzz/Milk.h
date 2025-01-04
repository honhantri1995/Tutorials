#pragma once
#include "CondimentDecorator.h"

class Milk : public CondimentDecorator
{
public:
	Milk(Beverage* inBeverage);
	~Milk();
protected:
};

