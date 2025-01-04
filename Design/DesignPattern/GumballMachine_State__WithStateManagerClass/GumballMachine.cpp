#include "GumballMachine.h"
#include "NoQuarterState.h"
#include "StateManager.h"

#include <iostream>
using namespace std;

GumballMachine::GumballMachine(int gumballCount) :
	mGumballCount(gumballCount),
	mStateManager(new StateManager(this))
{
}

GumballMachine::~GumballMachine()
{
	if (mStateManager != nullptr) {
		delete mStateManager;
		mStateManager = nullptr;
	}
}

unsigned int GumballMachine::GetGumballCount()
{
	return mGumballCount;
}

void GumballMachine::InsertQuarter()
{
	mStateManager->GetState()->InsertQuarter();
}

void GumballMachine::ReleaseGumball()
{
	cout << "A gumball comes rolling out the slot..." << endl;

	if (mGumballCount != 0) {
		mGumballCount -= 1;
	}
}

void GumballMachine::TurnCrank()
{
	mStateManager->GetState()->TurnCrank();
	mStateManager->GetState()->Dispense();
}

void GumballMachine::DisplayStatus()
{
	cout << "Current gumball: " << mGumballCount << endl;
}