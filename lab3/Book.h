#pragma once
#include <iostream>
using namespace std;

struct Book {
	string Name;
	int Year;
	int Page;
	string Autors[10];
	int AutorsCount;
};

void DemoBook();
void ReadBookFromConsole(Book& book);
void WriteBookToConsole(Book& book);
int FindBookByAuthor(Book* books, int booksCount, string author);