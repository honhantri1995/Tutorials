#pragma once
#include "IFlyBehaviors.h"

class FlyNoWay : public IFlyBehaviors
{
public:
	FlyNoWay();
	~FlyNoWay();
	void Fly();

};

