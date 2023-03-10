#pragma once
#include "Time.h"
#include <iostream>
using namespace std;

struct Flight {
	int Number;
	string Departure;
	string Arrival;
	Time* DeparutreTime;
	Time* ArrivalTime;
};

Flight* MakeFlight(int number, string departure, string arrival, Time* departuretime, Time* arrivaltime);
void SetNumber(Flight& flight, int number);
void SetDeparture(Flight& flight, string departure);
void SetArrival(Flight& flight, string arrival);
void SetDeparutreTime(Flight& flight, Time* departuretime);
void SetArrivalTime(Flight& flight, Time* arrivaltime);
void DemoFlightWithTime();
void WriteFlightToConsole(Flight& flight);
int GetFlightTimeMinutes(Flight& flight);
