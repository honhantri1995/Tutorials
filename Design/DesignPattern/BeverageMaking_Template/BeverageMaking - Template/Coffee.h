#pragma once
#include "Beverage.h"

class Coffee : public Beverage
{
public:
	Coffee();
	~Coffee();
	void Brew();
	void AddCondiments();
	bool IsCustomerWantCondiments();
protected:
	std::string GetUserInput();

};

