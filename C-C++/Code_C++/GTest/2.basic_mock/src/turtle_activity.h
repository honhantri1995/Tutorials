#pragma once
#include "turtle.h"

class TurtleActivity {
 public:
    TurtleActivity();
    ~TurtleActivity();
    void Hide();
    virtual bool IsOutside();
    bool IsInside();

 private:
    Turtle mTurtle;
};