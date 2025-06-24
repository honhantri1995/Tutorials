#include <iostream>

#include "turtle_activity.h"

TurtleActivity::TurtleActivity() {
    std::cout << "TurtleActivity Ctor" << std::endl;
}

TurtleActivity::~TurtleActivity() {
    std::cout << "TurtleActivity Dtor" << std::endl;
}

void TurtleActivity::Hide() {
    std::cout << "Hide" << std::endl;
    mTurtle.PenDown(); 
    mTurtle.Forward(10);
    mTurtle.Turn(90);
    mTurtle.Forward(5);
}

bool TurtleActivity::IsOutside() {
    std::cout << "IsOutside" << std::endl;
    int x = mTurtle.GetX(); 
    if (0 == x) {
        return false;
    } else {
        return true;
    }
}

bool TurtleActivity::IsInside() {
    std::cout << "IsInside" << std::endl;
    return !IsOutside();
}
