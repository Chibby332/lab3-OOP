#include <iostream>
#include "Time.h"
using namespace std;



Time* MakeTime(int year, int month, int day, int hour, int min) {
	Time* time = new Time();
	SetYear(*time, year);
	SetMonth(*time, month);
	SetDay(*time, day);
	SetHour(*time, hour);
	SetMin(*time, min);
	return time;
}

void SetYear(Time& time, int year) {
	if (year < 0) {
		throw exception("Год не может быть отрицательным");
	}
	else {
		time.Year = year;
	}
}
void SetMonth(Time& time, int month) {
	if (month < 0 || month > 12) {
		throw exception("Ограничения месяца");
	}
	else {
		time.Month = month;
	}
}
void SetDay(Time& time, int day) {
	if (day < 0 || day >= 30) {
		throw exception("Ограничения");
	}
	else {
		time.Day = day;
	}
}
void SetHour(Time& time, int hour) {
	if (hour < 0 || hour >=24) {
		throw exception("Ограничения");
	}
	else {
		time.Hour = hour;
	}
}
void SetMin(Time& time, int min) {
	if (min < 0 || min >= 60) {
		throw exception("Ограничения");
	}
	else {
		time.Min = min;
	}
}
