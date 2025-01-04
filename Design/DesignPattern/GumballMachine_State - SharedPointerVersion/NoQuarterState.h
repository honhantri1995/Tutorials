#pragma once
#include "IState.h"

class NoQuarterState : public IState
{
public:
	NoQuarterState();
	~NoQuarterState() override;

	void InsertQuarter() override;
	void EjectQuarter() override;
	void TurnCrank() override;
	void Dispense() override;
};