#pragma once

class IState;

class GumballMachine
{
public:
	GumballMachine();
	GumballMachine(int gumballCount);
	~GumballMachine();

	void TransitionTo(IState* state);

	unsigned int GetGumballCount();

	void InsertQuarter();
	void TurnCrank();
	void ReleaseGumball();
	void DisplayStatus();

private:
	IState* mState;

	unsigned int mGumballCount;
};