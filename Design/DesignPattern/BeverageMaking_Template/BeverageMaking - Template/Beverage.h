#pragma once

class Beverage
{
public:
	Beverage();
	~Beverage();
	void BoilWater();
	virtual void Brew() = 0;
	void PourInCup();
	virtual void AddCondiments() = 0;
	void PrepareRecipe_TemplateMethod();
	virtual bool IsCustomerWantCondiments();
private:

};

