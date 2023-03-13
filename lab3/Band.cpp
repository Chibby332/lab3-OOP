#include <iostream>
#include "Band.h"
using namespace std;

Band* MakeBand(string name, string description, int albumcounts, Album* albums) {
	Band* band = new Band();
	SetBandName(*band, name);
	SetBandDesription(*band, description);
	SetBandAlbumsCount(*band, albumcounts);
	SetBandAlbums(*band, albums);
	return band;
}
void SetBandName(Band& band, string name) {
	band.Name = name;
}
void SetBandDesription(Band& band, string desctription) {
	band.Description = desctription;
}
void SetBandAlbumsCount(Band& band, int albumcounts) {
	if (albumcounts < 0 || albumcounts > 30) {
		throw exception();
	}
	else {
		band.AlbumsCount = albumcounts;
	}
}
void SetBandAlbums(Band& band, Album* albums) {
	for (int i = 0; i < band.AlbumsCount; i++) {
		band.Albums[i] = &albums[i];
	}
}

Song* FindSong(Band* band, string songTitle) {
	int i = 0;
	int j = 0;
	Song* song = nullptr;
	for (i = 0; i < band->AlbumsCount; i++) {
		for (j = 0; j < band->Albums[i]->SongsCount; j++) {
			if (band->Albums[i]->Songs[j]->Name == songTitle) {
				song = band->Albums[i]->Songs[j];
				return song;
			}
		}
	}
	return song;
}
Album* FindAlbum(Band& band, Song* song) {
	Album* album = nullptr;
	for (int i = 0; i < band.AlbumsCount; i++) {
		for (int j = 0; j < band.Albums[i]->SongsCount; j++) {
			if (band.Albums[i]->Songs[i] == song) {
				album = band.Albums[i];
				return album;
			}
		}
	}
	return album;
}

Song* GetAllSongs(Band* band, int& allSongsCount) {
	int songsCount = 0;
	int f = 0;
	for (int i = 0; i < band->AlbumsCount; i++) {
		for (int j = 0; j < band->Albums[i]->SongsCount; j++) {
			songsCount++;
		}
	}
	allSongsCount = songsCount;
	Song* song = new Song[allSongsCount];
	for (int i = 0; i < band->AlbumsCount; i++) {
		for (int j = 0; j < band->Albums[i]->SongsCount; j++) {
			song[f] = *band->Albums[i]->Songs[j];
			f++;
		}
	}
	return song;
}

void DemoBand() {
	Song* song1[5];
	Song* song2[5];
	Song* song3[5];
    Album* album[3];
	Song* FoundSong;

	song1[0] = MakeSong("Song11", 100, Genre::Jazz);
	song1[1] = MakeSong("Song12", 200, Genre::Jazz);
	song1[2] = MakeSong("Song13", 300, Genre::Jazz);
	song1[3] = MakeSong("Song14", 400, Genre::Jazz);
	song1[4] = MakeSong("Song15", 500, Genre::Jazz);

	song2[0] = MakeSong("Song21", 100, Genre::Rap);
	song2[1] = MakeSong("Song22", 200, Genre::Rap);
	song2[2] = MakeSong("Song23", 300, Genre::Rap);
	song2[3] = MakeSong("Song24", 400, Genre::Rap);
	song2[4] = MakeSong("Song25", 500, Genre::Rap);

	song3[0] = MakeSong("Song31", 100, Genre::RnB);
	song3[1] = MakeSong("Song32", 200, Genre::RnB);
	song3[2] = MakeSong("Song33", 300, Genre::RnB);
	song3[3] = MakeSong("Song34", 400, Genre::RnB);
	song3[4] = MakeSong("Song35", 500, Genre::RnB);
	
	album[0] = MakeAlbum("Album1", 1999, 5, *song1);
	album[1] = MakeAlbum("Album2", 1998, 5, *song2);
	album[2] = MakeAlbum("Album3", 1997, 5, *song3);

	Band* band = MakeBand("Band","WereCool", 3, *album);

	FoundSong = FindSong(band, "Song21");
	cout << FoundSong->Length;
}