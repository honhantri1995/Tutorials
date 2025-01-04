#include "SoldState.h"
#include "NoQuarterState.h"
#include "SoldOutState.h"

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
	if (mGumballMachine->GetGumballCount() > 0) {
		mGumballMachine->ReleaseGumball();
		mGumballMachine->TransitionTo(shared_ptr<NoQuarterState>(new NoQuarterState()));
	}
	else {
		cout << "Oops, out of gumballs!" << endl;
		mGumballMachine->TransitionTo(shared_ptr<SoldOutState>(new SoldOutState()));
	}
}