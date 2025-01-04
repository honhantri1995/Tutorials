#include "CurrentConditionDisplay.h"
#include <iostream>
using namespace std;

CurrentConditionDisplay::CurrentConditionDisplay()
{
	m_temp = 0;
}

CurrentConditionDisplay::~CurrentConditionDisplay()
{
}

void CurrentConditionDisplay::Update(double inTemp)
{
	m_temp = inTemp;
	Display();
}

void CurrentConditionDisplay::Display()
{
	cout << "Temperature = " << m_temp << endl;
}