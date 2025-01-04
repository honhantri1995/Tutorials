#include "GumballMachine.h"
#include "NoQuarterState.h"

#include <iostream>
using namespace std;

GumballMachine::GumballMachine()
{
}

GumballMachine::GumballMachine(int gumballCount) :
	mGumballCount(gumballCount),
	mState(new NoQuarterState())
{
	mState->SetGumballMachine(this);
}

GumballMachine::~GumballMachine()
{
	if (mState != nullptr) {
		delete mState;
		mState = nullptr;
	}
}

void GumballMachine::TransitionTo(IState* state)
{
	if (state == nullptr) {
		cout << "ERROR: state is NUll" << endl;
		return;
	}

	if (mState != nullptr) {
		delete mState;
		mState = nullptr;
	}

	mState = state;

	// NOTE: Very important. This saves GumballMachine object (which contains the latest status of mState) back to mState,
	//       So the state can be transfered
	mState->SetGumballMachine(this);
}

unsigned int GumballMachine::GetGumballCount()
{
	return mGumballCount;
}

void GumballMachine::InsertQuarter()
{
	mState->InsertQuarter();
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
	mState->TurnCrank();
	mState->Dispense();
}

void GumballMachine::DisplayStatus()
{
	cout << "Current gumball: " << mGumballCount << endl;
}