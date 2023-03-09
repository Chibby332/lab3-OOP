#pragma once
#include <iostream>
#include "Book.h"
using namespace std;

int main()
{
    
}

void DemoBook() {
    Book book;
    book.Name = "Harry Potter I";
    book.Year = 2002;
    book.Page = 399;
    book.Autors[0] = "JK Rowling";
    book.Autors[1] = "Matvey Chibrkov";
    book.Autors[2] = "Matvey Chibrkov";
    book.AutorsCount = 3;
}
