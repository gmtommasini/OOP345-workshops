#pragma once

#include<string>
#include<iostream>
#include <fstream>
#include <list>
#include <iomanip>
#include <algorithm>
#include"util.h"

using namespace std;

namespace sdds {
#define WSTR 25 //width for Title, Artist and album
#define WNUM 5	//width for numbers
	struct Song {
		string	artist;
		string	title;
		string	album;
		double	price;
		size_t	releaseYear;
		size_t	songLength;

		Song();
		Song(string& in);
	};

	class SongCollection {
		list<Song> songs;

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

	};

	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}