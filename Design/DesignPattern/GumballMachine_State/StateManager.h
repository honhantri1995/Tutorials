#pragma once
#include "GumballMachine.h"

class IState;

class StateManager
{
private:
	GumballMachine* mGumballMachine;
	IState* mState;

public:
	StateManager(GumballMachine* gumballMachine);
	~StateManager();

	void TransitionTo(IState* state);

	IState* GetState();
	GumballMachine* GetGumballMachine();
};

