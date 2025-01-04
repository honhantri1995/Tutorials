#pragma once
class IDuck
{
public:
	IDuck();
	virtual ~IDuck();
	virtual void Fly() = 0;
	virtual void Quack() = 0;
};

