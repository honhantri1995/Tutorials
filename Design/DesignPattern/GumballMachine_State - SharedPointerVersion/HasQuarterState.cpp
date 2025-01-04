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
	mGumballMachine->TransitionTo(shared_ptr<NoQuarterState>(new NoQuarterState()));
}

void HasQuarterState::TurnCrank()
{
	cout << "You turned..." << endl;

	int random = Utils::getRandomNumberInRange(0, 9);
	cout << "random: " << random << endl;

	if (mGumballMachine->GetGumballCount() > 0) {
		if (random == WINNER_NUMBER) {
			mGumballMachine->TransitionTo(shared_ptr<WinnerState>(new WinnerState()));
		}
		else {
			mGumballMachine->TransitionTo(shared_ptr<SoldState>(new SoldState()));
		}
	}
	else {
		mGumballMachine->TransitionTo(shared_ptr<SoldOutState>(new SoldOutState()));
	}
}

void HasQuarterState::Dispense()
{
	cout << "No gumball dispensed" << endl;
}