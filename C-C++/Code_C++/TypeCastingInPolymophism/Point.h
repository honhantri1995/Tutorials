#pragma once

class Point
{
public:
	Point(const int x = 0, const int y = 0);

	int getX() const;
	int getY() const;
	void change(const int x, const int y);

private:
	int x;
	int y;
};

double distance(const Point& p1, const Point& p2);
void show(const Point& p);