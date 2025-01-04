#pragma once
#include "StateManager.h"

class IState
{
protected:
	StateManager* mStateManager;

public:
	IState();
	virtual ~IState();

	virtual void InsertQuarter() = 0;
	virtual void EjectQuarter() = 0;
	virtual void TurnCrank() = 0;
	virtual void Dispense() = 0;

	void SetStateManager(StateManager* stateManager);
};