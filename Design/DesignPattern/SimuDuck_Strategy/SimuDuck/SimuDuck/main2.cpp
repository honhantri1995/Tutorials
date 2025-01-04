#include "Client.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// Enter a duck type
	cout << "List of duck types:" << endl
		<< "\t1. Mallard duck" << endl
		<< "\t2. Rubber duck" << endl;
	cout << "Enter duck type by index: ";
	int duckTypeIndex;
	cin >> duckTypeIndex;

	// Show the display and behaviors of the entered duck
	Client* pClient = new Client;
	pClient->Initilize(duckTypeIndex);
	pClient->m_pDuck->Display();
	pClient->m_pDuck->SetFlyBehavior(pClient->m_pFlyBehaviors);

	// Show behaviors of any duck
	cout << "Which duck you want to know its flying behavior: ";
	cin >> duckTypeIndex;
	pClient->Initilize(duckTypeIndex);
	pClient->m_pDuck->SetFlyBehavior(pClient->m_pFlyBehaviors);
	pClient->m_pDuck->GetFlyBehavior();

	// Free memory
	pClient->Finalize();
	delete pClient;
	pClient = NULL;

	return 0;
}