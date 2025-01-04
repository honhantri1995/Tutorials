#include "ProxyInternet.h"
#include <iostream>
using namespace std;

ProxyInternet::ProxyInternet()
{
	mRealInternet = new RealInternet();

	InitBannedSites();
}

ProxyInternet::~ProxyInternet()
{
	delete mRealInternet;
}

void ProxyInternet::InitBannedSites()
{
	mBannedSites = { "github.com", "google.drive.com" };
}

void ProxyInternet::ConnectTo(string host)
{
	for (auto site : mBannedSites) {
		if (site.find(host) != string::npos) {
			cout << "Sorry. This side is banned!" << endl;
			return;
		}
	}

	cout << "This side is accessed!" << endl;
}