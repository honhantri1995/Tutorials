#include "IState.h"

IState::IState()
	: mGumballMachine(nullptr)
{
}

IState::~IState()
{
}

void IState::SetGumballMachine(GumballMachine* gumballMachine)
{
	mGumballMachine = gumballMachine;
}
