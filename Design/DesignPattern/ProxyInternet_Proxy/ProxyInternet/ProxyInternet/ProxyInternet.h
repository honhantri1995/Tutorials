#pragma once
#include "RealInternet.h"
#include <vector>

class ProxyInternet : public Internet
{
public:
	ProxyInternet();
	~ProxyInternet();

	void ConnectTo(std::string host) override;

private:
	Internet* mRealInternet;
	std::vector<std::string> mBannedSites;

	void InitBannedSites();
};