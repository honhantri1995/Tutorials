#include "GumballMachine.h"
#include "HasQuarterState.h"

#include <iostream>
using namespace std;

StateManager::StateManager(GumballMachine* gumballMachine)
	: mGumballMachine(gumballMachine),
	  mState(new HasQuarterState())
{
	mState->SetStateManager(this);
}

StateManager::~StateManager()
{
	if (mState != nullptr) {
		delete mState;
		mState = nullptr;
	}
}

void StateManager::TransitionTo(IState* state)
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

	// NOTE: Very important. This saves StateManager object (which contains the latest status of mState) back to mState,
	//       So the state can be transfered
	mState->SetStateManager(this);
}

IState* StateManager::GetState()
{
	return mState;
}

GumballMachine* StateManager::GetGumballMachine()
{
	return mGumballMachine;
}