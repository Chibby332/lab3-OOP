#pragma once
#include <iostream>
#include "Route.h"
using namespace std;
//3.2.6

void DemoRoute() {
    string busStop;
    const int routeCount = 3;
    Route route[routeCount];
    for (int i = 0; i < routeCount; i++) {
        cout << "��������� ������� ����� " << i + 1 << ": " << endl;
        ReadRouteFromConsole(route[i]);
    }
    for (int i = 0; i < routeCount; i++) {
        WriteRouteToConsole(route[i]);
        cout << endl;
    }
    cout << "������� ��������� ��� ������ ��������: ";
    cin >> busStop;
    if (FindRouteByAuthor(route, routeCount, busStop) > -1) {
        WriteRouteToConsole(route[FindRouteByAuthor(route, routeCount, busStop)]);
    }
    else {
        cout << "��� ������ ��������...";
    }
}
void ReadRouteFromConsole(Route& route) {
    cout << "������� ����� ��������: ";
    cin >> route.Number;
    while (route.Number <= 0) {
        cout << "������������ ����, ��������� �������: ";
        cin >> route.Number;
    }
    cout << "������� ����� ��������: ";
    cin >> route.Time;
    while (route.Time <= 0) {
        cout << "������������ ����, ��������� �������: ";
        cin >> route.Time;
    }
    cout << "������� �������� ����� ����������: ";
    cin >> route.Interval;
    while (route.Interval < 0) {
        cout << "������������ ����, ��������� �������: ";
        cin >> route.Interval;
    }
    cout << "������� ���-�� ��������� (�� ������ 20): ";
    cin >> route.BusStopsCount;
    while (route.BusStopsCount <= 0 || route.BusStopsCount > 20) {
        cout << "������������ ����, ��������� �������: ";
        cin >> route.BusStopsCount;
    }

    for (int i = 0; i < route.BusStopsCount; i++) {
        cout << "������� �������� ��������� #" << i + 1 << ": ";
        cin >> route.BusStops[i];
    }
}

void WriteRouteToConsole(Route& route) {
    cout << "�������: " << route.Number << " ����� � ����: " << route.Time << " �������� ����� ����������: " << 
        route.Interval << " ���-�� ���������: " << route.BusStopsCount << " ���������: " << endl;
    for (int i = 0; i < route.BusStopsCount; i++) {
        if (i == route.BusStopsCount - 1) {
            cout << route.BusStops[i] << ". ";
        }
        else {
            cout << route.BusStops[i] << ", ";
        }
    }
}

int FindRouteByAuthor(Route* route, int routesCount, string busStop) {
    for (int i = 0; i < routesCount; i++) {
        for (int j = 0; j < route[i].BusStopsCount; j++) {
            if (busStop == route[i].BusStops[j]) {
                return i;
            }
        }
    }
    return -1;
}
