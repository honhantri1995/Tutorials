#pragma once
#include "IPizza.h"

class CheesePizza :	public IPizza
{
public:
	CheesePizza();
	~CheesePizza() override;
	void Prepare() override;
	void Bake() override;
	void Cut() override;
	void Box() override;
};

