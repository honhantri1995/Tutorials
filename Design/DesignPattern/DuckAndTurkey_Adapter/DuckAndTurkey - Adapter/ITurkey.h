#pragma once
class ITurkey
{
public:
	ITurkey();
	virtual ~ITurkey();
	virtual void Fly() = 0;
	virtual void Gobble() = 0;
};

