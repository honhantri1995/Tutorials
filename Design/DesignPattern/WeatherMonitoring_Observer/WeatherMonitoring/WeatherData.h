#include "ISubject.h"
#include "IObserver.h"

#pragma once
class WeatherData :	public ISubject
{
public:
	WeatherData();
	~WeatherData();
	// concrete impl for interface ISubject
	void RegisterObserver(IObserver* pObsever);
	void RemoveObserver();
	void NotifyObserver(double inTemp);
	// NOT for interface ISubject
	void SetTemperature(double inTemp);
	double GetTemperature();
private:
	double m_temp;
	IObserver* m_pObserver;
};

