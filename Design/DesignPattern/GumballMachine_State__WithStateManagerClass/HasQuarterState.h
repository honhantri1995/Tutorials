#pragma once
#include "IState.h"

class HasQuarterState : public IState
{
public:
	HasQuarterState();
	~HasQuarterState() override;

	void InsertQuarter() override;
	void EjectQuarter() override;
	void TurnCrank() override;
	void Dispense() override;
};