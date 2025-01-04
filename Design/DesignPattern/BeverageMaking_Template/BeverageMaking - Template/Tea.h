#pragma once
#include "Beverage.h"

class Tea : public Beverage
{
public:
	Tea();
	~Tea();
	void Brew();
	void AddCondiments();
};

