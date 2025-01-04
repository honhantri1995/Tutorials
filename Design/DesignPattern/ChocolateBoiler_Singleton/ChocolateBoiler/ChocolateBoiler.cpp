#include "ChocolateBoiler.h"

ChocolateBoiler::ChocolateBoiler()
{
	isEmpty = true;
	isBoiled = false;
}

ChocolateBoiler::~ChocolateBoiler()
{
}

void ChocolateBoiler::Fill()
{
	if (IsEmpty()) {
		isEmpty = false;
		isBoiled = false;
	}
}

void ChocolateBoiler::Drain()
{
	if (!IsEmpty() && IsBoilded()) {
		isEmpty = true;
	}
}

void ChocolateBoiler::Boil()
{
	if (!IsEmpty() && !IsBoilded()) {
		isBoiled = true;
	}
}

bool ChocolateBoiler::IsEmpty()
{
	return isEmpty;
}

bool ChocolateBoiler::IsBoilded()
{
	return isBoiled;
}
