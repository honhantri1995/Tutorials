#pragma once
class IObserver
{
public:
	IObserver();
	virtual ~IObserver();
	virtual void Update(double inTemp) = 0;
};

