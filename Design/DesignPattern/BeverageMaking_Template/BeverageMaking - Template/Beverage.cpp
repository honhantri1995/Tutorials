#include "Beverage.h"
#include <iostream>
using namespace std;

Beverage::Beverage()
{
}

Beverage::~Beverage()
{
}

void Beverage::BoilWater()
{
	cout << "Boid water to 100 degrees C" << endl;
}

void Beverage::Brew()
{
}

void Beverage::PourInCup()
{
	cout << "Pour beveage to a cup" << endl;
}

void Beverage::AddCondiments()
{
}

void Beverage::PrepareRecipe_TemplateMethod()
{
	BoilWater();
	Brew();
	PourInCup();
	if (IsCustomerWantCondiments()) {
		AddCondiments();
	}
}

// This is a hook
bool Beverage::IsCustomerWantCondiments()
{
	return true;
}
