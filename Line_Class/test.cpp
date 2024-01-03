// Mark McKelvy
// Data Structures 3:00 MWF
// 1/19/03
// Line Class & Program

#include <iostream>
#include <stdlib.h>
#include "line.h"

int main()
{
	line l1, l2;
	int slope;
	float x1, x2, y1, y2;

	system("CLS");
	cout << "Line 1: " << endl << endl;
	l1.getline();
	l1.find_slope();
	system("CLS");
	cout << "Line 2: " << endl << endl;
	l2.getline();
	l2.find_slope();

	slope = l1.parallel_perpendicular(l1, l2);
	x1 = l1.displayX();
	x2 = l2.displayX();
	y1 = l1.displayY();
	y2 = l2.displayY();

	switch (slope)
	{
	case 1:
		system("CLS");
		cout << endl << endl << endl << endl;
		cout << "The lines are Parallel" << endl << endl;
		cout << "Line 1 has a slope of: " << y1 << "/" << x1 << endl;
		cout << "Line 2 has a slope of: " << y2 << "/" << x2 << endl;
		cout << endl;
		exit(0);
		break;
	case 0:
		system("CLS");
		cout << endl << endl << endl << endl;
		cout << "The lines are neither parallel NOR perpendicular" << endl << endl;
		cout << "Line 1 has a slope of: " << y1 << "/" << x1 << endl;
		cout << "Line 2 has a slope of: " << y2 << "/" << x2 << endl;
		cout << endl;
		exit(0);
		break;
	case -1:
		system("CLS");
		cout << endl << endl << endl << endl;
		cout << "The lines are Perpendicular" << endl << endl;
		cout << "Line 1 has a slope of: " << y1 << "/" << x1 << endl;
		cout << "Line 2 has a slope of: " << y2 << "/" << x2 << endl;
		cout << endl;
		exit(0);
		break;
	default:
		system("CLS");
		cout << endl << endl << endl << endl;
		cout << "An ERROR has occured!" << endl << endl;
		exit(0);
	}
	return 0;
}
