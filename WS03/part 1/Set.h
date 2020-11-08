#pragma once

//#include<iostream>
using namespace std;
namespace sdds {


	template<typename T = int, size_t N = 0>
	class Set {
		T collection[N]{};
		size_t stored{ 0 };
	public:
		size_t size() {
			return stored;
		}
		const T& operator[](size_t idx) const {
			int i = 0;
			++i;
			++++i;

			return collection[idx];
		}
		void operator+=(const T& item) {
			if (stored < N ) {
				collection[stored++] = item;
			}
		}

	};
}