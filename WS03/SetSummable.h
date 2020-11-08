/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini
gmatsumoto-tommasini@mysenca.ca
2020/10/09

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#pragma once

#include "Set.h"

namespace sdds {
	template<typename T, size_t N>
	class SetSummable : public Set<T, N> {
	public:
		//"The only += overload should be in pairsummable. - Hong Huang"		
		T accumulate(const std::string& filter) const {
			T temp(filter);
			for (size_t i = 0; i < N; i++) {
				temp += (*this)[i];
			}
			return temp;
		}
	};
}
