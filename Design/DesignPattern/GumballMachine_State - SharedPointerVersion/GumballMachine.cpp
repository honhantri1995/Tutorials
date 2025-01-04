#include "GumballMachine.h"
#include "NoQuarterState.h"

#include <iostream>
using namespace std;

GumballMachine::GumballMachine(int gumballCount) :
	mGumballCount(gumballCount),
	mState(shared_ptr<NoQuarterState>(new NoQuarterState()))
{
	//mState->SetGumballMachine(this);
	mState->SetGumballMachine(shared_from_this());
	
}

GumballMachine::~GumballMachine()
{
}

void GumballMachine::TransitionTo(shared_ptr<IState> state)
{
	if (state == nullptr) {
		cout << "ERROR: state is NUll" << endl;
		return;
	}

	//if (mState != nullptr) {
	//	delete mState;
	//	mState = nullptr;
	//}

	mState = state;

	// NOTE: Very important. This saves GumballMachine object (which contains the latest status of mState) back to mState,
	//       So the state can be transfered
	mState->SetGumballMachine(shared_from_this());
	// mState->SetGumballMachine(shared_ptr<GumballMachine>(this));	// This syntax of pass "this" to smart pointer doesn't WORK
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