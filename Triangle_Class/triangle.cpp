// Mark McKelvy
// Data Structures 3:00 MWF
// 1/16/03
// Triangle Class

#include <iostream.h>
#include <stdlib.h>
#include <math.h>

class triangle
{
  public:
    triangle();        
    
	float bharea(float sidea, float height);
	float karea(float sidea, float sideb, float sidec);
    float perimeter(float sidea, float sideb, float sidec);
	
  private:
    float sidea,sideb,sidec,height;
};

triangle::triangle()
{
	sidea = 0;
	sideb = 0;
	sidec = 0;
	height = 0;
}

float triangle::perimeter(float sidea, float sideb, float sidec)
{
	return (sidea + sideb + sidec);
}

float triangle::bharea(float sidea, float height)
{
	return (0.5f * sidea * height);
}

float triangle::karea(float sidea, float sideb, float sidec)
{
	float s = ((sidea + sideb + sidec) / 2.0f);
	return (float(sqrt(s * (s - sidea) * (s - sideb) * (s - sidec))));
}

int main()
{
	triangle t1;
	float sidea, sideb, sidec, height = 0.0f;
	float peri, bharea, karea = 0.0f;
	int ans, ans2;

	do
	{
		system("CLS");
		cout << "What do you want to find? " << endl << endl;
		cout << "1. Perimeter of a triangle " << endl;
		cout << "2. Area of a triangle " << endl;
		cout << "3. Exit" << endl;
		cout << endl << "Please enter the number of your choice:   ";
		cin >> ans;

		if (ans == 1)
		{
			system("CLS");
			cout << endl << "What is the length of side a? ";
			cin >> sidea;
			cout << endl << "What is the length of side b? ";
			cin >> sideb;
			cout << endl << "What is the length of side c? ";
			cin >> sidec;
			
			peri = t1.perimeter(sidea, sideb, sidec);
			system("CLS");
			cout << endl << "The perimeter is: " << peri << endl;
		}

		if (ans == 2)
		{
			system("CLS");
			ans2 = 0;
			while (ans2 != 3)
			{
				cout << "What do you have? " << endl << endl;
				cout << "1. Three sides" << endl;
				cout << "2. Base and Height" << endl;
				cout << "3. I want to go back" << endl;
				cout << endl << "Your choice?     ";
				cin >> ans2;

				if(ans2 == 1)
				{
					system("CLS");
					cout << "Enter side a: ";
					cin >> sidea;
					cout << endl << "Enter side b: ";
					cin >> sideb;
					cout << endl << "Enter side c: ";
					cin >> sidec;

					karea = t1.karea(sidea, sideb, sidec);
					system("CLS");
					cout << "The area is: " << karea << endl << endl;
				}

				if(ans2 == 2)
				{
					system("CLS");
					cout << "Enter the base: ";
					cin >> sidea;
					cout << endl << "Enter the height: ";
					cin >> height;

					bharea = t1.bharea(sidea, height);
					system("CLS");
					cout << "The area is: " << bharea << endl << endl;
				}
			}
	
		}
	}
	while (ans != 3);

	return 0;
}
