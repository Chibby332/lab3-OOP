#include <iostream>
#include "Rectangle.h"
using namespace std;

Rectangle* MakeRectangle(Point* center, double length, double width) {
	Rectangle* rectangle = new Rectangle();
	SetCenter(*rectangle, center);
	SetLength(*rectangle, length);
	SetWidth(*rectangle, width);
	return rectangle;
}

void SetLength(Rectangle& rectangle, double length) {
	if (length <=0) {
		throw exception("Длина не может быть отрицательной");
	}
	else {
		rectangle.Length = length;
	}
}
void SetWidth(Rectangle& rectangle, double width) {
	
	if (width <= 0) {
		throw exception("Ширина не может быть отрицательной");
	}
	else {
		rectangle.Width = width;
	}
}
void SetCenter(Rectangle& rectangle, Point* center) {
	rectangle.Center = center;
}

void DemoRectangleWithPoint() {
	const int rectanglesCount = 5;
	Rectangle rectangles[rectanglesCount];
	
	rectangles[0] = *MakeRectangle(MakePoint(2.3,6.4), 3.3, 4.4);
	rectangles[1] = *MakeRectangle(MakePoint(2.2, 2.2), 2.2, 2.2);
	rectangles[2] = *MakeRectangle(MakePoint(3.3, 3.3), 3.3, 3.3);
	rectangles[3] = *MakeRectangle(MakePoint(4.4, 4.4), 4.4, 4.4);
	rectangles[4] = *MakeRectangle(MakePoint(5.5, 5.5), 5.5, 5.5);

	for (int i = 0; i < rectanglesCount; i++) {
		WriteRectangleToConsole(rectangles[i]);
	}
	
	cout << "Среднее значения центра: " << endl;
	cout << "X = " << FindAverageCenterX(rectangles, rectanglesCount) << "; Y = " << FindAverageCenterY(rectangles, rectanglesCount);
}

void WriteRectangleToConsole(Rectangle& rectangle) {
	cout << "X = " << rectangle.Center->X << "; Y = " << rectangle.Center->Y << "; Length = " << rectangle.Length << "; Width = " << rectangle.Width << endl;
}

double FindAverageCenterX(Rectangle* rectangles, int rectanglesCount) {
	double res = 0;
	for (int i = 0; i < rectanglesCount; i++) {
		res = res + rectangles[i].Center->X;
	}
	res = res / rectanglesCount;
	return res;
}
double FindAverageCenterY(Rectangle* rectangles, int rectanglesCount) {
	double res = 0;
	for (int i = 0; i < rectanglesCount; i++) {
		res = res + rectangles[i].Center->Y;
	}
	res = res / rectanglesCount;
	return res;
}