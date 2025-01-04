#include <iostream>
#include "ChocolateBoiler.h"
using namespace std;

int main()
{
	ChocolateBoiler* p1 = new ChocolateBoiler;
	ChocolateBoiler i1;
	ChocolateBoiler i2;

	cout << "p1 Before Fill(), isEmpty is " << i1.IsEmpty() << endl;
	i1.Fill();
	cout << "p1 After Fill(), isEmpty is " << i1.IsEmpty() << endl;

	cout << "p2 After Fill(), isEmpty is " << i2.IsEmpty() << endl;

	cout << "p1 Before Boil(), isBoiled is " << p1->IsBoilded() << endl;
	p1->Boil();
	cout << "p1 After Boil(), isBoiled is " << p1->IsBoilded() << endl;

	delete p1;
	//delete p2;


	//m_p1 = new ChocolateBoiler;
	//m_p2 = new ChocolateBoiler;
	//cout << "m_p1 Before Fill(), isEmpty is " << m_p1->IsEmpty() << endl;
	//p1->Fill();
	//cout << "m_p1 After Fill(), isEmpty is " << m_p1->IsEmpty() << endl;

	//cout << "m_p2 After Fill(), isEmpty is " << m_p2->IsEmpty() << endl;

	//cout << "m_p1 Before Boil(), isBoiled is " << m_p1->IsBoilded() << endl;
	//p1->Boil();
	//cout << "m_p1 After Boil(), isBoiled is " << m_p1->IsBoilded() << endl;
}
