#include "Shape.h"
#include "Point.h"

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<Shape*> shapes;
	Point point(0, 0);

	shapes.push_back(new Rectangle(point, 10, 10));
	shapes.push_back(new Rectangle(point, 17, 17));
	shapes.push_back(new Square(point, 5));
	shapes.push_back(new Line(point, Point(47, 11)));

	// Draw all shapes
	for (auto shape : shapes)
	{
		shape->draw();
		cout << endl;
	}

	// Count number of rectanges and squares in list
	{
		int count = 0;
		for (auto shape : shapes)
		{
			if (dynamic_cast<Rectangle*>(shape) != nullptr)
			{
				count++;
			}
		}
		cout << count << " rectanges in list" << endl;		// 3
	}

	// Count number of rectanges in list
	{
		int count = 0;
		for (auto shape : shapes)
		{
			if (typeid(*shape) == typeid(Rectangle))
			{
				count++;
			}
		}
		cout << count << " rectanges in list" << endl;		// 2
	}

	cout << "Is Shape based of Line: " << std::is_base_of<Shape, Line>() << endl;		// 1

	return 0;
}