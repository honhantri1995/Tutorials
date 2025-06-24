#pragma once
#include "Point.h"
#include <string>

class Shape
{
public:
	Shape(const Point& p);

	const Point& getRefPoint() const;
	Point setRefPoint(const Point& point);

	int getX() const;
	int getY() const;
	virtual double area() const = 0;
	virtual void draw() const = 0;

private:
	Point m_refPoint;
};

class Rectangle : virtual public Shape
{
public:
	Rectangle(const Point& point, int h, int w);
	double area() const override;
	void draw() const override;

protected:
	int m_height;
	int m_width;
};

class Line : public Shape
{
public:
	Line(const Point& point1, const Point& point2);
	double area() const override;
	void draw() const override;

	double length() const;

private:
	Point m_endPoint;
};

class Square : public Rectangle
{
public:
	Square(const Point& point, int side);
	void draw() const override;
};

double distance(const Point& p1, const Point& p2);