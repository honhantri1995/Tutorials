#include "ForecastDisplay.h"
#include <iostream>
using namespace std;

ForecastDisplay::ForecastDisplay()
{
	m_temp = 0;
}

ForecastDisplay::~ForecastDisplay()
{
}

void ForecastDisplay::Update(double inTemp)
{
	m_temp = inTemp;
	Display();
}

void ForecastDisplay::Display()
{
	if (m_temp >= 30)
		cout << "Temperature is high" << endl;
	else if (m_temp >= 20 && m_temp < 30)
		cout << "Temperature is good" << endl;
	else if (m_temp < 20)
		cout << "Temperature is low" << endl;
}