#include <iostream>
#include "Song.h"
using namespace std;

Song* MakeSong(string name, int length, Genre genre) {
	Song* song = new Song();
	SetSongName(*song, name);
	SetSongLength(*song, length);
	SetSongGenre(*song, genre);
	return song;
}
void SetSongName(Song& song, string name) {
	song.Name = name;
}
void SetSongLength(Song& song, int length) {
	if (length <= 0) {
		throw exception();
	}
	else {
		song.Length = length;
	}	
}
void SetSongGenre(Song& song, Genre genre) {
	song.Genre = genre;
}