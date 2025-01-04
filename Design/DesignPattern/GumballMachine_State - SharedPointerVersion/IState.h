#pragma once
#include "GumballMachine.h"

class IState
{
protected:
	std::shared_ptr<GumballMachine> mGumballMachine;

public:
	IState();
	virtual ~IState();

	virtual void InsertQuarter() = 0;
	virtual void EjectQuarter() = 0;
	virtual void TurnCrank() = 0;
	virtual void Dispense() = 0;

	void SetGumballMachine(std::shared_ptr<GumballMachine> gumballMachine);
};