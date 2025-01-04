#include "Duck.h"

Duck::Duck()
{
	m_pFlyBehavior = nullptr;
}

Duck::~Duck()
{
}

//void Duck::Display()		// pure virtual
//{
//}

void Duck::SetFlyBehavior(IFlyBehaviors* inFly)
{
	inFly->Fly();
	m_pFlyBehavior = inFly;
}

IFlyBehaviors* Duck::GetFlyBehavior()
{
	return m_pFlyBehavior;
}