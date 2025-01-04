#pragma once
#include "IObserver.h"

class CurrentConditionDisplay :	public IObserver
{
public:
	CurrentConditionDisplay();
	~CurrentConditionDisplay();
	// concrete impl for interface ISubject
	void Update(double inTemp);
	// NOT for interface ISubject
	void Display();
private:
	double m_temp;
};

