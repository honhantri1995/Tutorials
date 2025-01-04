#include "NoQuarterState.h"
#include "HasQuarterState.h"

#include <iostream>
using namespace std;

NoQuarterState::NoQuarterState()
{
}

NoQuarterState::~NoQuarterState()
{
}

void NoQuarterState::InsertQuarter()
{
	cout << "You inserted a quarter" << endl;
	mStateManager->TransitionTo(new HasQuarterState());
}

void NoQuarterState::EjectQuarter()
{
	cout << "You haven't inserted a quarter" << endl;
}

void NoQuarterState::TurnCrank()
{
	cout << "You turned, but there's no quarter" << endl;
}

void NoQuarterState::Dispense()
{
	cout << "You need to pay ﬁrst" << endl;
}
