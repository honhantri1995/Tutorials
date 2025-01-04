#pragma once
#include "IPizza.h"

class VeggiePizza : public IPizza
{
public:
	VeggiePizza();
	~VeggiePizza();
	void Prepare();
	void Bake();
	void Cut();
	void Box();
};

