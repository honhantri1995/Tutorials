#pragma once
#include <memory>

class IState;

class GumballMachine : public std::enable_shared_from_this<GumballMachine>
{
public:
	GumballMachine(int gumballCount);
	~GumballMachine();

	void TransitionTo(std::shared_ptr<IState> state);

	unsigned int GetGumballCount();

	void InsertQuarter();
	void TurnCrank();
	void ReleaseGumball();
	void DisplayStatus();

private:
	std::shared_ptr<IState> mState;

	unsigned int mGumballCount;
};