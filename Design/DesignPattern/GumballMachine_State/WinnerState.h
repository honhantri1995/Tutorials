#pragma once
#include "IState.h"

class WinnerState : public IState
{
public:
	WinnerState();
	~WinnerState() override;

	void InsertQuarter() override;
	void EjectQuarter() override;
	void TurnCrank() override;
	void Dispense() override;
};