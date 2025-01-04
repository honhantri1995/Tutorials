#pragma once
#include "IObserver.h"

class ForecastDisplay :	public IObserver
{
public:
	ForecastDisplay();
	~ForecastDisplay();
	// concrete impl for interface ISubject
	void Update(double inTemp);
	// NOT for interface ISubject
	void Display();
private:
	double m_temp;
};

