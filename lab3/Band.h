#pragma once
#include <iostream>
#include "Album.h"
#include "Genre.h"
using namespace std;

struct Band {
	string Name;
	string Description;
	int AlbumsCount;
	Album* Albums[30];
};

Band* MakeBand(string name, string description, int albumcounts, Album* albums);
void SetBandName(Band& band, string name);
void SetBandDesription(Band& band, string desctription);
void SetBandAlbumsCount(Band& band, int albumcounts);
void SetBandAlbums(Band& band, Album* albums);

Song* FindSong(Band* band, string songTitle);

Album* FindAlbum(Band& band, Song* song);

Song* GetAllSongs(Band* band, int& allSongsCount);

void DemoBand();