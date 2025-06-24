#include "mylib.h"
#include <iostream>

Rectangle::Rectangle(int width, int height) 
    : m_width(width),
      m_height(height) {}

int Rectangle::Area() const {
    int area = m_width * m_height;
    std::cout << "Area: " << area << std::endl;
    return area;
}