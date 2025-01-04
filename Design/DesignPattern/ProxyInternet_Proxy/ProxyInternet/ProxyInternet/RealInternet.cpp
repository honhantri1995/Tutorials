#include "RealInternet.h"
#include <iostream>
using namespace std;

RealInternet::RealInternet() {}

RealInternet::~RealInternet() {}

void RealInternet::ConnectTo(string host)
{
	cout << "Connecting to " + host;
}