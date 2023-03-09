#pragma once
#include <iostream>
using namespace std;

struct Route {
	int Number;
	int Time;
	int Interval;
	string BusStops[20];
	int BusStopsCount;
};

void DemoRoute();
void ReadRouteFromConsole(Route& route);
void WriteRouteToConsole(Route& route);
int FindRouteByAuthor(Route* route, int routesCount, string busStop);
