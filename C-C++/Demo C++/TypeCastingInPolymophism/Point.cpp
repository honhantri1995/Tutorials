#include "Point.h"

#include <cmath>
#include <iostream>

using std::cout;
using std::endl;
using std::sqrt;

Point::Point(int x, int y)
	: x(x),
	  y(y)
{
}

void Point::change(const int newX, const int newY)
{
	x = newX;
	y = newY;
}

int Point::getX() const
{
	return x;
}

int Point::getY() const
{
	return y;
}

double distance(const Point& p1, const Point& p2)
{
	double dx = static_cast<double>(p1.getX() - p2.getX());
	double dy = static_cast<double>(p1.getY() - p2.getY());
	return sqrt(dx * dx + dy * dy);
}

void show(const Point& p)
{
  cout << '(' << p.getX() << ", " << p.getY() << ')';
}