#include "ProxyInternet.h"
#include "RealInternet.h"
#include <iostream>
using namespace std;

int main()
{
	Internet* proxyInternet = new ProxyInternet();

	while (true) {
		string site;
		cout << "Enter the side you want to access: ";
		cin >> site;

		proxyInternet->ConnectTo(site);
	}

	delete proxyInternet;
}