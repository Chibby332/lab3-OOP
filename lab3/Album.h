#pragma once
#include <iostream>
#include "Song.h"
using namespace std;

struct Album {
	string Name;
	int Year;
	int SongsCount;
	Song* Songs[30];
};

Album* MakeAlbum(string name, int year, int songscount, Song* songs);
void SetAlbumName(Album& album, string name);
void SetAlbumYear(Album& album, int year);
void SetAlbumSongsCount(Album& album, int songscount);
void SetAlbumSongs(Album& album, Song* songs);
