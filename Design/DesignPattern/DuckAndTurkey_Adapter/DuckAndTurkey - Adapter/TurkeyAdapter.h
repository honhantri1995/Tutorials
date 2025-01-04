#pragma once
#include "IDuck.h"
#include "ITurkey.h"

class TurkeyAdapter : public IDuck
{
public:
	TurkeyAdapter(ITurkey* inTurkey);
	~TurkeyAdapter();
	void Fly();
	void Quack();
protected:
private:
	ITurkey* m_pTurkey;
};

