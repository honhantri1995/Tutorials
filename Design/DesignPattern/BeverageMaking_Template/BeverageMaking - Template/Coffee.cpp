#include "Coffee.h"
#include <iostream>
using namespace std;

Coffee::Coffee()
{
}

Coffee::~Coffee()
{
}

void Coffee::Brew()
{
	cout << "Brew coffee powder with boided water" << endl;
}

void Coffee::AddCondiments()
{
	cout << "Add milk or sugar" << endl;
}

// This is to override the hook
bool Coffee::IsCustomerWantCondiments()
{
	return 0 == GetUserInput().compare("yes") ? true : false;
}

std::string Coffee::GetUserInput()
{
	string ans;
	cout << "Do you want to add condiments to your coffee (answer 'yes' if you want)? ";
	cin >> ans;
	return ans;
}
