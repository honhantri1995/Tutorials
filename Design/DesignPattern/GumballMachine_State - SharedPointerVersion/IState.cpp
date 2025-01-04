#include "IState.h"
#include <memory>

IState::IState()
	: mGumballMachine(nullptr)
{
}

IState::~IState()
{
}

void IState::SetGumballMachine(std::shared_ptr<GumballMachine> gumballMachine)
{
	mGumballMachine = gumballMachine;
}
