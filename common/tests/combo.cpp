#include "card.h"
#include "combo.h"
#include <iostream>
#include <vector>

using namespace combo;
using namespace card;

int main() {
	bool all_passed = true;

	Combo single_two(std::vector{Card(TWO, Suit::clubs)});
	Combo single_ace(std::vector{Card(ACE, Suit::clubs)});
	if (!single_two.beats(single_ace)) {
		std::cout << "High two should beat high ace: " << single_two.beats(single_ace) << "\n";
		all_passed = false;
	}

	std::cout.flush();

	return all_passed ? 0 : 1;
}
