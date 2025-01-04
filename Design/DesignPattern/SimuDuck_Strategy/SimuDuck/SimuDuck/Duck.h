#pragma once
#include "IFlyBehaviors.h"

class Duck
{
public:
	Duck();
	~Duck();
	virtual void Display() = 0;
	IFlyBehaviors* GetFlyBehavior();
	void SetFlyBehavior(IFlyBehaviors* inFly);

private:
	IFlyBehaviors* m_pFlyBehavior;
};

