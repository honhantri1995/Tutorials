#include "GumballMachine.h"
#include <iostream>
using namespace std;

int main()
{
    unsigned int gumballCount = 0;
    cout << "Set initial number of gumballs: ";
    cin >> gumballCount;

    if (gumballCount <= 0) {
        cout << "You must enter an positive number of gumballs" << endl;
        return -1;
    }

    cout << endl << "Now let's play" << endl;

    GumballMachine* gumballMachine = new GumballMachine(gumballCount);

    gumballMachine->DisplayStatus();

    for (int i = 0; i < 10; i++) {
        cout << endl;
        gumballMachine->InsertQuarter();
        gumballMachine->TurnCrank();
        gumballMachine->DisplayStatus();
    }

    delete gumballMachine;

	return 0;
}