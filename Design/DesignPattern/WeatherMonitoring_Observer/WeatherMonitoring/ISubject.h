#pragma once
#include "IObserver.h"

class ISubject
{
public:
	ISubject();
	virtual ~ISubject();
	virtual void RegisterObserver(IObserver* pObsever) = 0;
	virtual void RemoveObserver() = 0;
	virtual void NotifyObserver(double inTemp) = 0;
};