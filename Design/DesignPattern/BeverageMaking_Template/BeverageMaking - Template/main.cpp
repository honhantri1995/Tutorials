#include <iostream>
#include "Coffee.h"
#include "Tea.h"
using namespace std;

int main()
{
	Beverage* pCoffee = new Coffee;
	pCoffee->PrepareRecipe_TemplateMethod();
	delete pCoffee;

	cout << endl;

	Beverage* pTea = new Tea;
	pTea->PrepareRecipe_TemplateMethod();
	delete pTea;
}