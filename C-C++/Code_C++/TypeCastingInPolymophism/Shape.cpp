#include "Shape.h"
#include "Point.h"
#include <iostream>

using std::cout;
using std::endl;

Shape::Shape(const Point& p)
    : m_refPoint(p)
{
}

int Shape::getX() const
{
  return m_refPoint.getX();
}

int Shape::getY() const
{
  return m_refPoint.getY();
}

Point Shape::setRefPoint(const Point& point)
{
  Point temp = m_refPoint;
  m_refPoint = point;
  return temp;
}

const Point& Shape::getRefPoint() const
{
  return m_refPoint;
}

void Shape::draw() const
{
  cout << "Draw: Reference point (" << getX() << "/" << getY() << ")" << endl;
}

// =================================================
Rectangle::Rectangle(const Point& point, int h, int w)
	: Shape(point),
	  m_height(h),
	  m_width(w)
{
}

double Rectangle::area() const
{
  return static_cast<double>(m_height) * m_width;
}

void Rectangle::draw() const
{
  Shape::draw();
  cout << "Draw: Rectangle (" << m_height << " x " << m_width << ")" << endl;
}

// =================================================
Line::Line(const Point& point1, const Point& point2)
	: Shape(point1),
	  m_endPoint(point2)
{
}

double Line::area() const
{
  return 0.0;
}

void Line::draw() const
{
  Shape::draw();
  cout << "Draw: Line (" << m_endPoint.getX() << "/" << m_endPoint.getY() << ")" << endl;
}

double Line::length() const
{
  return distance(getRefPoint(), m_endPoint);
}

// =================================================
Square::Square(const Point& point, int side)
	: Shape(point),
	  Rectangle(point, side, side)
{
}

void Square::draw() const
{
  Shape::draw();
  cout << "Draw: Square (" << m_height << ")" << endl;
}