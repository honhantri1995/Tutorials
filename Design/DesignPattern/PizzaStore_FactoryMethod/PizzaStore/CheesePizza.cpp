#include <iostream>
#include "CheesePizza.h"
#include "Utility.h"

using namespace std;

CheesePizza::CheesePizza()
{
	Utility::WriteDebugLogToFile(LOG_INFO, "Create Cheese pizza.", __FUNCTION__, __LINE__);
}

CheesePizza::~CheesePizza()
{
	Utility::WriteDebugLogToFile(LOG_INFO, "Destroy Cheese pizza.", __FUNCTION__, __LINE__);
}

void CheesePizza::Prepare()
{
	cout << "Prepare like Cheese Pizza" << endl;
}

void CheesePizza::Bake()
{
	cout << "Bake like Cheese Pizza" << endl;
}

void CheesePizza::Cut()
{
	cout << "Cut like Cheese Pizza" << endl;
}

void CheesePizza::Box()
{
	cout << "Box like Cheese Pizza" << endl;
}
