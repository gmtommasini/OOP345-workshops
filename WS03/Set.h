/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini
gmatsumoto-tommasini@mysenca.ca
2020/10/09

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#pragma once

namespace sdds {
	template<typename T, size_t N>
	class Set {
		T collection[N]{};
		size_t stored{ 0 };
	public:
		size_t size() const {
			return stored;
		}
		const T& operator[](size_t idx) const {
			return collection[idx];
		}
		void operator+=(const T& item) {
			if (stored < N ) {
				collection[stored++] = item;
			}
		}
	};
}
