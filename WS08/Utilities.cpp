/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini
gmatsumoto-tommasini@mysenca.ca
2020/11/20

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include <memory>
#include <algorithm>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers

		for (size_t i = 0; i < desc.size(); i++) {
			bool found = false;
			for (size_t j = 0; j < price.size() && !found; j++) {
				if (desc[i].code == price[j].code) {
					found = true;
					Product * temp = new Product(desc[i].desc, price[j].price); //Prints C [1]
					temp->validate();
					priceList += temp; //prints CC [2] from [1]
					delete temp;
				}
			}
		}


		return priceList;
	}
}