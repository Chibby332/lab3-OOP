#include <iostream>
#include "Album.h"
using namespace std;

Album* MakeAlbum(string name, int year, int songscount, Song* songs) {
	Album* album = new Album();
	SetAlbumName(*album, name);
	SetAlbumYear(*album, year);
	SetAlbumSongsCount(*album, songscount);
	SetAlbumSongs(*album, songs);
	return album;
}
void SetAlbumName(Album& album, string name) {
	album.Name = name;
}
void SetAlbumYear(Album& album, int year) {
	if (year <= 0 || year > 2023) {
		throw exception();
	}
	else {
		album.Year = year;
	}
}
void SetAlbumSongsCount(Album& album, int songscount) {
	if (songscount<0 || songscount > 30) {
		throw exception();
	}
	else {
		album.SongsCount = songscount;
	}
}
void SetAlbumSongs(Album& album, Song* songs) {
	for (int i = 0; i < album.SongsCount; i++) {
		album.Songs[i]->Length = songs[i].Length;
		album.Songs[i]->Name = songs[i].Name;
		album.Songs[i]->Genre = songs[i].Genre;
	}
}