#pragma once
class IFlyBehaviors
{
public:
	IFlyBehaviors();
	virtual ~IFlyBehaviors();
	virtual void Fly() = 0;
};

