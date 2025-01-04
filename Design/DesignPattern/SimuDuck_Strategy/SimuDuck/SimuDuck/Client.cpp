#include "Client.h"

Client::Client()
{
	m_pDuck = nullptr;
	m_pFlyBehaviors = nullptr;
}

Client::~Client()
{
}

void Client::Initilize(int inDuck)
{
	switch (inDuck)
	{
	case DEF_MALLARD_DUCK:
	{
		m_pDuck = new MallardDuck;
		m_pFlyBehaviors = new FlyWithWings;
		break;
	}
	case DEF_RUBBER_DUCK:
	{
		m_pDuck = new RubberDuck;
		m_pFlyBehaviors = new FlyNoWay;
		break;
	}
	default:
		break;
	}
}

void Client::Finalize()
{
	if (m_pDuck)
		delete m_pDuck;
	if (m_pFlyBehaviors)
		delete m_pFlyBehaviors;
}
