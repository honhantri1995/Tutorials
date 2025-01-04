// This main() is not good


//#include "MallardDuck.h"
//#include "RubberDuck.h"
//#include "FlyWithWings.h"
//#include "FlyNoWay.h"
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	cout << "List of duck types:" << endl
//		 << "\t1. Mallard duck" << endl
//		 << "\t2. Rubber duck" << endl;
//
//	cout << "Enter duck type by index: ";
//	int duckTypeIndex;
//	cin >> duckTypeIndex;
//
//	switch (duckTypeIndex)
//	{
//	case 1:
//	{
//		Duck* pMallardDuck = new MallardDuck;
//		IFlyBehaviors* pFlyBehaviors = new FlyWithWings();
//
//		pMallardDuck->Display();
//		pMallardDuck->SetFlyBehavior(pFlyBehaviors);
//
//		delete pMallardDuck;
//		delete pFlyBehaviors;
//		break;
//	}
//	case 2:
//	{
//		Duck* pRubberDuck = new RubberDuck;
//		IFlyBehaviors* pFlyBehaviors = new FlyNoWay();
//
//		pRubberDuck->Display();
//		pRubberDuck->SetFlyBehavior(pFlyBehaviors);
//
//		delete pRubberDuck;
//		delete pFlyBehaviors;
//		break;
//	}
//	default:
//		cout << "No duck type";
//		break;
//	}
//
//	cout << "Which duck you want to know its flying behavior: ";
//	cin >> duckTypeIndex;
//
//
//	return 0;
//}