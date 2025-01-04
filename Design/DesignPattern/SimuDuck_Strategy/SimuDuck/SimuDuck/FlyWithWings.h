#pragma once
#include "IFlyBehaviors.h"

class FlyWithWings : public IFlyBehaviors
{
public:
	FlyWithWings();
	~FlyWithWings();
	void Fly();
};

