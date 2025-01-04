#pragma once
#include "Internet.h"

class RealInternet : public Internet
{
public:
	RealInternet();
	~RealInternet();

	void ConnectTo(std::string host) override;
};

