#pragma once

class StateManager;

class GumballMachine
{
public:
	GumballMachine(int gumballCount);
	~GumballMachine();

	unsigned int GetGumballCount();

	void InsertQuarter();
	void TurnCrank();
	void ReleaseGumball();
	void DisplayStatus();

private:
	unsigned int mGumballCount;

	StateManager* mStateManager;
};