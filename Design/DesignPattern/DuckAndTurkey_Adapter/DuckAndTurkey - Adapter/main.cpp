#include <iostream>
#include "MallardDuck.h"
#include "WildTurkey.h"
#include "TurkeyAdapter.h"
using namespace std;

int main()
{
	cout << "Test duck:" << endl;
	IDuck* pDuck = new MallardDuck;
	pDuck->Fly();
	pDuck->Quack();

	cout << "Test turkey:" << endl;
	ITurkey* pTurkey = new WildTurkey;
	pTurkey->Fly();
	pTurkey->Gobble();

	cout << "Test calling turkey in duck:" << endl;
	IDuck* pDuck2 = new TurkeyAdapter(pTurkey);
	pDuck2->Fly();
	pDuck2->Quack();

	delete pDuck;
	delete pTurkey;
	delete pDuck2;

	return 0;
}
