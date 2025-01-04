#pragma once
#include <string>

class Internet
{
public:
	Internet();
	virtual ~Internet();

	virtual void ConnectTo(std::string host) = 0;
};