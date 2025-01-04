#include <iostream>

#include "turtle.h"

Turtle::Turtle() {
    std::cout << "Turtle Ctor" << std::endl;
}

Turtle::~Turtle() {
    std::cout << "Turtle Dtor" << std::endl;
}

void Turtle::PenUp() {
    std::cout << "PenUp" << std::endl;
}

void Turtle::PenDown() {
    std::cout << "PenDown" << std::endl;
}

void Turtle::Forward(int distance) {
    std::cout << "Forward by " << distance << " units" << std::endl;
}

void Turtle::Turn(int degrees) {
    std::cout << "Turn by " << degrees << " degrees" << std::endl;
}

void Turtle::GoTo(int x, int y) {
    std::cout << "Go to (" << x << ", " << y << ")" << std::endl;
}

int Turtle::GetX() const {
    std::cout << "GetX" << std::endl;
    return 0;
}

int Turtle::GetY() const {
    std::cout << "GetY" << std::endl;
    return 0;
}
