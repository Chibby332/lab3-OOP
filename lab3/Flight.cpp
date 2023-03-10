#include "Flight.h"
#include <iostream>
using namespace std;

Flight* MakeFlight(int number, string departure, string arrival, Time* departuretime, Time* arrivaltime) {
	Flight* flight = new Flight();
	SetNumber(*flight, number);
	SetDeparture(*flight, departure);
	SetArrival(*flight, arrival);
	SetDeparutreTime(*flight, departuretime);
	SetArrivalTime(*flight, arrivaltime);
	return flight;
}

void SetNumber(Flight& flight, int number) {
	if (number < 0) {
		throw exception();
	}
	else {
		flight.Number = number;
	}
}
void SetDeparture(Flight& flight, string departure) {
	flight.Departure = departure;
}
void SetArrival(Flight& flight, string arrival) {
	flight.Arrival = arrival;
}
void SetDeparutreTime(Flight& flight, Time* departuretime) {
	flight.DeparutreTime = departuretime;
}
void SetArrivalTime(Flight& flight, Time* arrivaltime) {
	if (arrivaltime->Year > flight.DeparutreTime->Year) {
		flight.ArrivalTime = arrivaltime;
		return;
	}
	else if(arrivaltime->Year == flight.DeparutreTime->Year) {

		if (arrivaltime->Month > flight.DeparutreTime->Month) {
			flight.ArrivalTime = arrivaltime;
			return;
		}
		else if (arrivaltime->Month == flight.DeparutreTime->Month) {

			if (arrivaltime->Day > flight.DeparutreTime->Day) {
				flight.ArrivalTime = arrivaltime;
				return;
			}
			else if (arrivaltime->Day == flight.DeparutreTime->Day) {

				if (arrivaltime->Hour > flight.DeparutreTime->Hour) {
					flight.ArrivalTime = arrivaltime;
					return;
				}
				else if (arrivaltime->Hour == flight.DeparutreTime->Hour) {
					if (arrivaltime->Min > flight.DeparutreTime->Min) {
						flight.ArrivalTime = arrivaltime;
						return;
					}
					else if (arrivaltime->Min == flight.DeparutreTime->Min) {
						throw exception("");
					}
					else {
						throw exception("");
					}
				}
				else {
					throw exception("");
				}

			}
			else {
				throw exception("");
			}

		}
		else {
			throw exception("");
		}

	}
	else {
		throw exception("");
	}
}

void DemoFlightWithTime() {
	const int flightsCount = 5;
	Flight flights[flightsCount];

	flights[0] = *MakeFlight(100, "Moskow", "Tomsk", MakeTime(2003, 12, 2, 1, 10), MakeTime(2003, 12, 2, 2, 20));
	flights[1] = *MakeFlight(200, "Tomsk", "Novosibirsk", MakeTime(1999, 10, 20, 21, 20), MakeTime(1999, 10, 21, 20, 20));
	flights[2] = *MakeFlight(300, "Berlin", "Paris", MakeTime(2012, 3, 4, 3, 30), MakeTime(2012, 3, 4, 20, 20));
	flights[3] = *MakeFlight(400, "Dublin", "Lima", MakeTime(2034, 4, 4, 4, 40), MakeTime(2034, 4, 4, 15, 20));
	flights[4] = *MakeFlight(500, "Los Angeles", "New York", MakeTime(1997, 5, 5, 5, 15), MakeTime(1997, 5, 5, 5, 45));

	for (int i = 0; i < flightsCount; i++) {
		WriteFlightToConsole(flights[i]);
	}
	for (int i = 0; i < flightsCount; i++) {
		cout << "Время полета рейса №" << flights[i].Number << " в минутах: " << GetFlightTimeMinutes(flights[i]) << endl;
	}
}

void WriteFlightToConsole(Flight& flight) {
	cout << "Рейс №" << flight.Number << ": " << flight.Departure << " - " << flight.Arrival << " Вылет: " << flight.DeparutreTime->Year << " " << flight.DeparutreTime->Month
		<< "." << flight.DeparutreTime->Day << " " << flight.DeparutreTime->Hour << ":" << flight.DeparutreTime->Min << " Прилет:  " << flight.ArrivalTime->Year << " " << 
		flight.ArrivalTime->Month << "." << flight.ArrivalTime->Day << " " << flight.ArrivalTime->Hour << ":" << flight.ArrivalTime->Min << endl;
}

int GetFlightTimeMinutes(Flight& flight) {
	int min;
	int hour = 0;
	int day;
	if (flight.ArrivalTime->Day == flight.DeparutreTime->Day) {
		if (flight.ArrivalTime->Min >= flight.DeparutreTime->Min) {
			min = flight.ArrivalTime->Min - flight.DeparutreTime->Min + (flight.ArrivalTime->Hour - flight.DeparutreTime->Hour) * 60;
			return min;
		}
		else {
			min = flight.ArrivalTime->Min - flight.DeparutreTime->Min + 60 + (flight.ArrivalTime->Hour - flight.DeparutreTime->Hour - 1) * 60;
			return min;
		}
	}
	else {
		min = ((23 - flight.DeparutreTime->Hour) * 60 + (60 - flight.DeparutreTime->Min)) + (flight.ArrivalTime->Hour * 60 + flight.ArrivalTime->Min);
		return min;
		
	}
}