#pragma once

class Turtle {
 public:
    Turtle();
    virtual ~Turtle();

    virtual void PenUp();
    virtual void PenDown();
    virtual void Forward(int distance);
    virtual void Turn(int degrees);
    virtual void GoTo(int x, int y);
    virtual int GetX() const;
    virtual int GetY() const;
};
