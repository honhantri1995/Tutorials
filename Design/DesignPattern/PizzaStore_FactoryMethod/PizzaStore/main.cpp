#include <iostream>
#include "ChicagoPizzaStore.h"
#include "Utility.h"

using namespace std;

int main()
{
	//int storeID;
	//cout << "Our list of stores: " << endl
	//	<< "\t" << "1. Chicago" << endl;
	//cout << "Enter a store: ";
	//cin >> storeID;

	int pizzaID = 0;
	cout << "Our list of pizzas: " << endl
		 << "\t" << "1. Cheese Pizza" << endl
		 << "\t" << "2. Veggie Pizza" << endl;
	cout << "Enter a pizza you want to eat: ";
	cin >> pizzaID;

	IPizzaStore* pPizzaStore = new ChicagoPizzaStore;
	pPizzaStore->CreatePizza((PIZZA)pizzaID);
	delete pPizzaStore;

	// Release debug log manager
	DebugLog* pDebugLog = DebugLog::GetInstance();
	pDebugLog->ReleaseInstance();

	return 0;
}