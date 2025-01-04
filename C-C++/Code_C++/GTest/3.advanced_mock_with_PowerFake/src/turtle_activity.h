#pragma once
#include "turtle.h"

class TurtleActivity {
 public:
    TurtleActivity();
    ~TurtleActivity();
    bool IsOutside();
    bool IsInside();

 private:
    Turtle mTurtle;
};