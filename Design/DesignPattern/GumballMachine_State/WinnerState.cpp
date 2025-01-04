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

    mGumballMachine->ReleaseGumball();

    if (mGumballMachine->GetGumballCount() == 0) {
        cout << "Oops, out of gumballs!" << endl;
        mGumballMachine->TransitionTo(new SoldOutState());
    }
    else {
        mGumballMachine->ReleaseGumball();

        if (mGumballMachine->GetGumballCount() == 0) {
            cout << "Oops, out of gumballs!" << endl;
            mGumballMachine->TransitionTo(new SoldOutState());
        }
        else {
            mGumballMachine->TransitionTo(new NoQuarterState());
        }
    }
}