#include "WeatherData.h"
#include "CurrentConditionDisplay.h"
#include "ForecastDisplay.h"
#include <iostream>
using namespace std;

int main()
{
	double temp = 0;
	cout << "Enter temperature: ";
	cin >> temp;

	ISubject* pSubject = new WeatherData;

	{
		IObserver* pObsever = new CurrentConditionDisplay;
		pSubject->RegisterObserver(pObsever);
		pSubject->NotifyObserver(temp);
		pSubject->RemoveObserver();
		delete pObsever;
		pObsever = NULL;
	}

	{
		IObserver* pObsever = new ForecastDisplay;
		pSubject->RegisterObserver(pObsever);
		pSubject->NotifyObserver(temp);
		pSubject->RemoveObserver();
		delete pObsever;
		pObsever = NULL;
	}

	delete pSubject;

	return 0;
}