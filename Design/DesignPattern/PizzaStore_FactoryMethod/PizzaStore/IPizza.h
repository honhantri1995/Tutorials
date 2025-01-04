#pragma once

class IPizza
{
public:
	IPizza();
	virtual ~IPizza();
	virtual void Prepare() = 0;
	virtual void Bake() = 0;
	virtual void Cut() = 0;
	virtual void Box() = 0;
};

