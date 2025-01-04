#include "TurkeyAdapter.h"
#include <iostream>
using namespace std;

TurkeyAdapter::TurkeyAdapter(ITurkey* inTurkey)
{
	m_pTurkey = inTurkey;
}

TurkeyAdapter::~TurkeyAdapter()
{
}

void TurkeyAdapter::Fly()
{
	m_pTurkey->Fly();
}

void TurkeyAdapter::Quack()
{
	m_pTurkey->Gobble();
}