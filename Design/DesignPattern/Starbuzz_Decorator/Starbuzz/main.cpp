#include <iostream>
#include <string>
#include <vector>
#include "HouseBlend.h"
#include "Espresso.h"
#include "Milk.h"
#include "Mocha.h"
using namespace std;

enum DEF_COFFEE_ID
{
	DEF_HOUSE_BLEND = 1,
	DEF_EXPRESSO,
};

enum DEF_CONDIMENT_ID
{
	DEF_MILK = 1,
	DEF_MOCHA,
};

int main()
{
	// Input coffee
	int coffeeID = 0;
	cout << "Our list of coffee:" << endl
		 << "\t" << DEF_HOUSE_BLEND << ". House Blend" << endl
		 << "\t" << DEF_EXPRESSO << ". Expresso" << endl
		 << "Enter the one you want: ";
	cin >> coffeeID;

	Beverage* pBeverage = NULL;
	switch (coffeeID)
	{
		case DEF_HOUSE_BLEND:
			pBeverage = new HouseBlend;
			break;
		case DEF_EXPRESSO:
			pBeverage = new Espresso;
			break;
		default:
			cout << "Sorry, we don't serve " << coffeeID << "!" << endl;
			return 0;
	}

	// Input condiment
	string sCondimentIDList;
	cout << "Our list of condiment: " << endl
		 << "\t" << DEF_MILK << ". Milk" << endl
		 << "\t" << DEF_MOCHA << ". Mocha" << endl
		 << "Enter the ones you want (separate each of them by a space): ";
	cin.ignore();		// Ignore the first input
	getline(cin, sCondimentIDList);

	// 1. Split condiment input by delimiter
	// 2. Convert string to int (condiment ID)
	// 3. Store all condiment IDs to vector
	string delimiter = " ";
	vector<int> condimentIDList;
	size_t start = 0;
	size_t end = 0;
	while ((start = sCondimentIDList.find_first_not_of(delimiter, end)) != std::string::npos)
	{
		end = sCondimentIDList.find(delimiter, start);
		condimentIDList.push_back(stoi(sCondimentIDList.substr(start, end - start)));
	}

	for (size_t i = 0; i < condimentIDList.size(); ++i)
	{
		switch (condimentIDList[i])
		{
			case DEF_MILK:
				pBeverage = new Milk(pBeverage);	// Wrap coffee with Milk condiment
				break;
			case DEF_MOCHA:
				pBeverage = new Mocha(pBeverage);	// Wrap coffee with Mocha condiment
				break;
			default:
				cout << "Sorry, we don't flavor " << condimentIDList[i] << " into our coffee!" << endl;
				return 0;
		}
	}

	// Output cost
	cout << "Your " << pBeverage->GetDescription() << " costs " << pBeverage->GetCost() << "$" << endl;

	// Free memory
	if (pBeverage) {
		delete pBeverage;
		pBeverage = NULL;
	}

	return 0;
}
