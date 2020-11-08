#include "SongCollection.h"

using namespace std;

namespace sdds {

	SongCollection::~SongCollection() {}

	SongCollection::SongCollection() {}

	SongCollection::SongCollection(char* fileName) {
		std::ifstream file(fileName);
		if (!file) {
			std::cerr << "ERROR: Cannot open file [" << fileName << "].\n";
			return;
		}
		while (file) {
			string line;
			getline(file, line); //geting one record from file
			if (file) { //checks if the getline() was successful
				//util::trim(line); //no trim - pass the white spaces too
				this->songs.push_back(std::move(Song(line)));
			}
		}
	}

	SongCollection::SongCollection(SongCollection& src) { *this = src; }

	SongCollection::SongCollection(SongCollection&& src) noexcept { *this = std::move(src); }

	SongCollection SongCollection::operator=(SongCollection& src) {
		return *this;
	}

	SongCollection SongCollection::operator=(SongCollection&& src) noexcept {
		return *this;
	}

	//Song& SongCollection::createSong(string in) {
	//	Song song(in);
	//	return song;
	//}

	void SongCollection::display(std::ostream& out) const {
		for_each(this->songs.begin(), this->songs.end(),
			[&](Song s){ out << s; } );
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong) {
		//cout << theSong.artist.length();
		//cout << theSong.title.length();
		//cout << theSong.album.length();
		out << left << "| " << std::setw(20) << setfill(' ') << theSong.title
			; out << " | " << std::setw(15) << theSong.artist
			; out << " | " << std::setw(20) << theSong.album
			; out << " | " << std::setw(6) << right << (theSong.releaseYear > 0 ? to_string(theSong.releaseYear) : "")
			; out << " | " << theSong.songLength / 60 << ":"
			; out << std::setw(2) << setfill('0') << theSong.songLength % 60
			; out << " | " << fixed << std::setprecision(2) << theSong.price
			; out << " |" << std::endl;
		return out;
	}

	Song::Song() {
		this->album = "";
		this->artist = "";
		this->price = { 0 };
		this->releaseYear = { 0 };
		this->songLength = { 0 };
		this->title = "";
	}

	Song::Song(string& in) {
		size_t ipos = 0;
		title = in.substr(ipos, WSTR);
		util::trim(title);
		//cout << title.length();
		ipos += WSTR;

		artist = in.substr(ipos, WSTR);
		util::trim(artist);
		ipos += WSTR;
		//cout << artist.length();

		album = in.substr(ipos, WSTR);
		util::trim(album);
		ipos += WSTR;
		//cout << album.length();

		try { releaseYear = std::stoi(in.substr(ipos, WNUM)); }
		catch (...) { releaseYear = 0; }
		ipos += WNUM;

		try { songLength = std::stoi(in.substr(ipos, WNUM)); }
		catch (...) { cout << "ERROR!!"; }
		ipos += WNUM;

		try { price = std::stod(in.substr(ipos, WNUM)); }
		catch (...) { cout << "ERROR!!"; }
	}

}