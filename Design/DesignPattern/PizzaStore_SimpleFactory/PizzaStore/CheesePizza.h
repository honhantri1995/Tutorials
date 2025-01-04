#pragma once
#include "IPizza.h"

class CheesePizza :	public IPizza
{
public:
	CheesePizza();
	~CheesePizza();
	void Prepare();
	void Bake();
	void Cut();
	void Box();
};

