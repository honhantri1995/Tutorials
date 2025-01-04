#pragma once
#include "IState.h"

class SoldState : public IState
{
public:
	SoldState();
	~SoldState() override;

	void InsertQuarter() override;
	void EjectQuarter() override;
	void TurnCrank() override;
	void Dispense() override;
};