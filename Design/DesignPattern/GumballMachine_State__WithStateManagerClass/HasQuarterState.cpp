#include "HasQuarterState.h"
#include "WinnerState.h"
#include "SoldState.h"
#include "SoldOutState.h"
#include "NoQuarterState.h"

#include "Utils.h"
#include <iostream>
using namespace std;

#define WINNER_NUMBER 0

HasQuarterState::HasQuarterState()
{
}

HasQuarterState::~HasQuarterState()
{
}

void HasQuarterState::InsertQuarter()
{
	cout << "You can't insert another quarter" << endl;
}

void HasQuarterState::EjectQuarter()
{
	cout << "Quarter returned" << endl;
	mStateManager->TransitionTo(new NoQuarterState());
}

void HasQuarterState::TurnCrank()
{
	cout << "You turned..." << endl;

	int random = Utils::getRandomNumberInRange(0, 9);
	cout << "Random number: " << random << endl;

	if (mStateManager->GetGumballMachine()->GetGumballCount() > 0) {
		if (random == WINNER_NUMBER) {
			mStateManager->TransitionTo(new WinnerState());
		}
		else {
			mStateManager->TransitionTo(new SoldState());
		}
	}
	else {
		mStateManager->TransitionTo(new SoldOutState());
	}
}

void HasQuarterState::Dispense()
{
	cout << "No gumball dispensed" << endl;
}