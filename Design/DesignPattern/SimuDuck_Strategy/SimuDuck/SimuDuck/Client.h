#pragma once
#include "MallardDuck.h"
#include "RubberDuck.h"
#include "FlyWithWings.h"
#include "FlyNoWay.h"

enum _DEF_DUCK_TYPE
{
	DEF_MALLARD_DUCK = 1,
	DEF_RUBBER_DUCK,
};

class Client
{
public:
	Client();
	~Client();
	void Initilize(int inDuck);
	void Finalize();
	Duck* m_pDuck;
	IFlyBehaviors* m_pFlyBehaviors;
};

