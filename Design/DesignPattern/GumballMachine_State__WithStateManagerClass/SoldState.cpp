#include "SoldOutState.h"
#include "StateManager.h"
#include "SoldState.h"
#include "NoQuarterState.h"

#include <iostream>
using namespace std;

SoldState::SoldState()
{
}

SoldState::~SoldState()
{
}

void SoldState::InsertQuarter()
{
	cout << "Please wait, we're already giving you a gumball" << endl;
}

void SoldState::EjectQuarter()
{
	cout << "Sorry, you already turned the crank" << endl;
}

void SoldState::TurnCrank()
{
	cout << "Turning twice doesn't get you another gumball" << endl;
}

void SoldState::Dispense()
{
	if (mStateManager->GetGumballMachine()->GetGumballCount() > 0) {
		mStateManager->GetGumballMachine()->ReleaseGumball();
		mStateManager->TransitionTo(new NoQuarterState());
	}
	else {
		cout << "Oops, out of gumballs!" << endl;
		mStateManager->TransitionTo(new SoldOutState());
	}
}