#pragma once
#include <iostream>
#include "Genre.h"
using namespace std;


struct Song {
	string Name;
	int Length;
	Genre Genre;
};

Song* MakeSong(string name, int length, Genre genre);
void SetSongName(Song& song, string name);
void SetSongLength(Song& song, int length);
void SetSongGenre(Song& song, Genre genre);