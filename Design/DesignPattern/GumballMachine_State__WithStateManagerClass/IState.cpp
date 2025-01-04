#include "IState.h"

IState::IState()
	: mStateManager(nullptr)
{
}

IState::~IState()
{
}

void IState::SetStateManager(StateManager* stateManager)
{
	mStateManager = stateManager;
}
