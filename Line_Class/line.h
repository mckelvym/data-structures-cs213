#ifndef _LINE_H
#define _LINE_H

#include <iostream.h>
#include <stdlib.h>

struct point
{
	float x, y;
};

class line
{
private:
	point p1, p2;
	float Y, X, slope;
	int Parallel, None, Perpendicular;
public:
	line();
	void find_slope();
	void getline();
	float displayX();
	float displayY();
	int parallel_perpendicular(line l1, line l2);
};

line::line()
{
	p1.x = p1.y = p2.x = p2.y = 0.0f;
	Parallel = 1;
	None = 0;
	Perpendicular = -1;
	return;
}

void line::find_slope()
{
	Y = (p2.y - p1.y);
	X = (p2.x - p1.x);
	slope = ((p2.y - p1.y) / (p2.x - p1.x));
	return;
}

void line::getline()
{
	float x1, x2, y1, y2;
	
	cout << endl;
	cout << "Enter x for point 1: ";
	cin >> x1;
	cout << "Enter y for point 1: ";
	cin >> y1;
	cout << endl;
	cout << "Enter x for point 2: ";
	cin >> x2;
	cout << "Enter y for point 2: ";
	cin >> y2;
	
	p1.x = x1;
	p1.y = y1;
	p2.x = x2;
	p2.y = y2;

	return;
}

float line::displayX()
{
	return X;
}

float line::displayY()
{
	return Y;
}

int line::parallel_perpendicular(line l1, line l2)
{
	if ((l1.slope) == (l2.slope))
	{
		return Parallel;
	}
	else if ((l1.slope) == (-1 * (l2.X / l2.Y))) 
	{
		return Perpendicular;
	}
	else
	{
		return None;
	}
}

#endif
