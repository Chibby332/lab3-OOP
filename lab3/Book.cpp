#pragma once
#include <iostream>
#include "Book.h"
using namespace std;



//3.2.2 - 3.2.x

void DemoBook() {
    const int bookCount = 2;
    string author;
    Book book[bookCount];
    for (int i = 0; i < bookCount; i++) {
        cout << "Заполните книгу номер " << i+1 << ": " << endl;
        ReadBookFromConsole(book[i]);
    }
    for (int i = 0; i < bookCount; i++) {
        WriteBookToConsole(book[i]);
        cout << endl;
    }
    cout << "Введите автора для поиска книги: ";
    cin >> author;
    if (FindBookByAuthor(book, bookCount, author) > -1) {
        WriteBookToConsole(book[FindBookByAuthor(book, bookCount, author)]);
    }
    else {
        cout << "Нет такой книги...";
    }
}

//3.2.3

void ReadBookFromConsole(Book& book) {
    cout << "Введите название книги: ";
    cin >> book.Name;   
    cout << "Введите год издания: ";
    cin >> book.Year;
    while (book.Year < 0 || book.Year > 2023) {
        cout << "Некорректный ввод, повторите попытку: ";
        cin >> book.Year;
    } 
    cout << "Введите кол-во страниц: ";
    cin >> book.Page;
    while (book.Page < 0 ) {
        cout << "Некорректный ввод, повторите попытку: ";
        cin >> book.Page;
    } 
    cout << "Введите кол-во авторов (не больше 10): ";
    cin >> book.AutorsCount;
    while (book.AutorsCount <= 0 || book.AutorsCount > 10) {
        cout << "Некорректный ввод, повторите попытку: ";
        cin >> book.AutorsCount;
    }
    for (int i = 0; i < book.AutorsCount; i++) {
        cout << "Введите автора #" << i+1 <<": ";
        cin >> book.Autors[i];
    }
}

//3.2.4

void WriteBookToConsole(Book& book) {
    for (int i = 0; i < book.AutorsCount; i++) {
        if (i == book.AutorsCount - 1) {
            cout << book.Autors[i] << ". " << book.Name << ". " << book.Year << ". - " << book.Page << "c.";
        }
        else {
            cout << book.Autors[i] << ", ";
        }
    }
}

int FindBookByAuthor(Book* books, int booksCount, string author) {
    for (int i = 0; i < booksCount; i++) {
        for (int j = 0; j < books[i].AutorsCount; j++) {
            if (books[i].Autors[j] == author) {
                return i;
            }
        }  
    }
    return -1;
}