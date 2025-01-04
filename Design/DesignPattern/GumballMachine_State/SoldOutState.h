#pragma once
#include "IState.h"

class SoldOutState : public IState
{
public:
	SoldOutState();
	~SoldOutState() override;

	void InsertQuarter() override;
	void EjectQuarter() override;
	void TurnCrank() override;
	void Dispense() override;
};