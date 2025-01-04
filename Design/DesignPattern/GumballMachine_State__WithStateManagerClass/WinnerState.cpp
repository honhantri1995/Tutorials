#include "WinnerState.h"
#include "SoldOutState.h"
#include "NoQuarterState.h"
#include "GumballMachine.h"

#include <iostream>
using namespace std;

WinnerState::WinnerState()
{
}

WinnerState::~WinnerState()
{
}

void WinnerState::InsertQuarter()
{
    cout << "Error" << endl;
}

void WinnerState::EjectQuarter()
{
    cout << "Error" << endl;
}

void WinnerState::TurnCrank()
{
    cout << "Error" << endl;
}

void WinnerState::Dispense()
{
    cout << "YOU'RE A WINNER! You get two gumballs for your quarter" << endl;

    mStateManager->GetGumballMachine()->ReleaseGumball();

    if (mStateManager->GetGumballMachine()->GetGumballCount() == 0) {
        cout << "Oops, out of gumballs!" << endl;
        mStateManager->TransitionTo(new SoldOutState());
    }
    else {
        mStateManager->GetGumballMachine()->ReleaseGumball();

        if (mStateManager->GetGumballMachine()->GetGumballCount() == 0) {
            cout << "Oops, out of gumballs!" << endl;
            mStateManager->TransitionTo(new SoldOutState());
        }
        else {
            mStateManager->TransitionTo(new NoQuarterState());
        }
    }
}