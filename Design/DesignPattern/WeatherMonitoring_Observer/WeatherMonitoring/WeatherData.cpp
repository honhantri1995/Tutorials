#include "WeatherData.h"

WeatherData::WeatherData()
{
	m_temp = 0;
	m_pObserver = nullptr;
}

WeatherData::~WeatherData()
{
}

void WeatherData::RegisterObserver(IObserver* pObsever)
{
	m_pObserver = pObsever;
}

void WeatherData::RemoveObserver()
{
	m_pObserver = nullptr;
}

void WeatherData::NotifyObserver(double inTemp)
{
	SetTemperature(inTemp);
	m_pObserver->Update(GetTemperature());
}

void WeatherData::SetTemperature(double inTemp)
{
	m_temp = inTemp;
}

double WeatherData::GetTemperature()
{
	return m_temp;
}