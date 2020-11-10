#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include "util.h"

using namespace std;

namespace sdds {
#define WSTR 25 //width for Title, Artist and album
#define WNUM 5	//width for numbers
	struct Song {
		string	artist;
		string	title;
		string	album;
		double	m_price;
		size_t	releaseYear;
		size_t	lenght;

		Song();
		Song(string& in);
		//size_t getLenght(){ return songLength; }
	};

	class SongCollection {
		vector<Song> songs; //list or vector?

	public:
		~SongCollection();
		SongCollection();
		SongCollection(char*);
		SongCollection(SongCollection&);
		SongCollection(SongCollection&&) noexcept;
		SongCollection operator=(SongCollection&);
		SongCollection operator=(SongCollection&&) noexcept;

		//Song& createSong(string);
		void display(std::ostream& out) const;//DO NOT USE MANUAL LOOPS
		void sort(const std::string);
		void cleanAlbum();
		bool inCollection(const std::string) const;
		std::list<Song> getSongsForArtist(const std::string) const;
		
	};

	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}