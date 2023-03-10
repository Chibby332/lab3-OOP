#pragma once
#include <iostream>
using namespace std;

struct Time {
	int Year;
	int Month;
	int Day;
	int Hour;
	int Min;
};

Time* MakeTime(int year, int month, int day, int hour, int min);

void SetYear(Time& time, int year);
void SetMonth(Time& time, int month);
void SetDay(Time& time, int day);
void SetHour(Time& time, int hour);
void SetMin(Time& time, int min);
