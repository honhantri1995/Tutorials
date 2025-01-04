#pragma once
#include <string>

class Beverage
{
public:
	Beverage();
	~Beverage();
	virtual std::string GetDescription();
	virtual double GetCost();
protected:
	std::string m_description;
	double m_cost;
};