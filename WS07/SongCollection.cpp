/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini
gmatsumoto-tommasini@mysenca.ca
2020/11/1

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

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
				//util::trim(line); //NO TRIM!!- pass the white spaces too
				this->songs.push_back(std::move(Song(line)));
			}
		}
	}

	SongCollection::SongCollection(SongCollection& src) { *this = src; }
	SongCollection::SongCollection(SongCollection&& src) noexcept { *this = std::move(src); }
	SongCollection SongCollection::operator=(SongCollection& src) {
		this->songs = src.songs;
		return *this;
	}
	SongCollection SongCollection::operator=(SongCollection&& src) noexcept {
		this->songs = std::move(src.songs);
		return *this;
	}

	//Song& SongCollection::createSong(string in) {
	//	Song song(in);
	//	return song;
	//}

	void SongCollection::display(std::ostream& out) const {
		size_t totalLenght = 0;
		// without the accumulate
		//for_each(this->songs.begin(), this->songs.end(),
		//	[&](Song s){ 
		//		out << s<<std::endl; 
		//		totalLenght += s.lenght;
		//	} );
		for_each(this->songs.begin(), this->songs.end(),
			[&](Song s) { out << s << std::endl; });

		//accumulate written for educational purposes
		totalLenght = std::accumulate(
			songs.begin(), songs.end(), 0
			, [](size_t lenght, const Song& s) {
				return s.lenght + lenght;
			}
		);
		int h = totalLenght / 3600;
		int m = (totalLenght - h * 3600) / 60;
		int s = (totalLenght - m * 60) % 60;
		out << std::setw(89) << std::setfill('-') << "\n";
		out << "|" << std::setfill(' ') << std::right << std::setw(80)
			<< " Total Listening Time: " + std::to_string(h) + ":"
			<< std::setw(2) << std::setfill('0') << m << ":"
			<< std::setw(2) << std::setfill('0') << s << " |" << std::endl;
		//		printf("%2d:%2d", m, s); //much easier lol
	}

	void SongCollection::sort(std::string sortby) {
		//this works with vector<> but not with list<>
		std::sort(songs.begin(), songs.end(),
			[&](const Song& s1, const Song& s2) {
				if (sortby == "album") 
					return s1.album < s2.album;
				else  if (sortby == "length") 
					return s1.lenght < s2.lenght;
				else  if (sortby == "year")
					return s1.releaseYear < s2.releaseYear;
				else  if (sortby == "price")
					return s1.m_price < s2.m_price;
				else if (sortby == "title") 
					return s1.title < s2.title; 
				else //default
					return s1.artist < s2.artist;
			});

		/* //first crazy attempt //works
		bool (*comp[3])(const Song & s1, const Song & s2) = {
			[](const Song& s1, const Song& s2) {return s1.title < s2.title; },
			[](const Song& s1, const Song& s2) {return s1.album < s2.album; },
			[](const Song& s1, const Song& s2) {return s1.lenght < s2.lenght; }
		};
		int criteria =-1;
		if (sortby == "title") criteria = 0;
		else if (sortby == "album") criteria = 1;
		else if (sortby == "length") criteria = 2;
		else throw "Error: unrecognized sort criteria. ";
		std::sort(songs.begin(), songs.end(), comp[criteria]);
		*/

		/*
		// this if for lis<> version
		this->songs.sort([&](const Song& s1, const Song& s2) {
			if (sortby == "title") return s1.title < s2.title;
			else if (sortby == "album") return s1.album < s2.album;
			else if (sortby == "length") return s1.lenght < s2.lenght;
			});
		*/
		//both "old" versions kept for educational purposes
	}

	void SongCollection::cleanAlbum() {
		std::vector<Song> temp(this->songs.size());
		std::transform(
			songs.begin(), songs.end(),
			songs.begin(),
			[](Song& s) {
				s.album = s.album != "[None]" ? s.album : "";
				return s;
			});
	}

	bool SongCollection::inCollection(const std::string artist) const {
		return std::any_of(songs.begin(), songs.end(),
			[&](const Song s) { return s.artist == artist; });
	}

	std::list<Song> SongCollection::getSongsForArtist(const std::string artist) const {
		std::list<Song> temp(this->songs.size());
		auto qnt = std::copy_if(
			songs.begin(), songs.end(),
			temp.begin(),
			[&](const Song s) { return s.artist == artist; });
		temp.resize(std::distance(temp.begin(), qnt));
		return temp;
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong) {
		out << left << "| " << std::setw(20) << setfill(' ') << theSong.title
			; out << " | " << std::setw(15) << theSong.artist
			; out << " | " << std::setw(20) << theSong.album
			; out << " | " << std::setw(6) << right << (theSong.releaseYear > 0 ? to_string(theSong.releaseYear) : "")
			; out << " | " << theSong.lenght / 60 << ":"
			; out << std::setw(2) << setfill('0') << theSong.lenght % 60
			; out << " | " << fixed << std::setprecision(2) << theSong.m_price
			; out << " |";
		return out;
	}

}


//Songs
namespace sdds {
	Song::Song() {
		this->album = "";
		this->artist = "";
		this->m_price = { 0 };
		this->releaseYear = { 0 };
		this->lenght = { 0 };
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
		if (album.empty()) album = "[None]";
		ipos += WSTR;
		//cout << album.length();

		try { releaseYear = std::stoi(in.substr(ipos, WNUM)); }
		catch (...) { releaseYear = 0; }
		ipos += WNUM;

		try { lenght = std::stoi(in.substr(ipos, WNUM)); }
		catch (...) { cout << "ERROR!!"; }
		ipos += WNUM;

		try { m_price = std::stod(in.substr(ipos, WNUM)); }
		catch (...) { cout << "ERROR!!"; }
	}


}