#pragma once
#include <iostream>
#include "Point.h"
using namespace std;

struct Rectangle {
	double Length;
	double Width;
	Point* Center;
};

Rectangle* MakeRectangle(Point* center, double length, double width);

void SetLength(Rectangle& rectangle, double length);
void SetWidth(Rectangle& rectangle, double width);
void SetCenter(Rectangle& rectangle, Point* center);

void DemoRectangleWithPoint();
void WriteRectangleToConsole(Rectangle& rectangle);

double FindAverageCenterX(Rectangle* rectangles, int rectanglesCount);
double FindAverageCenterY(Rectangle* rectangles, int rectanglesCount);