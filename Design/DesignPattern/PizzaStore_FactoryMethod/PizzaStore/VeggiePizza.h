#pragma once
#include "IPizza.h"

class VeggiePizza : public IPizza
{
public:
	VeggiePizza();
	~VeggiePizza() override;
	void Prepare() override;
	void Bake() override;
	void Cut() override;
	void Box() override;
};

