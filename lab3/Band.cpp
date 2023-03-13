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