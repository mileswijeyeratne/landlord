#include "card.h"
#include "combo.h"
#include <iostream>
#include <vector>

using namespace combo;
using namespace card;

int main() {
	Combo single_two(std::vector{Card(TWO, Suit::clubs)});
	Combo single_ace(std::vector{Card(ACE, Suit::clubs)});
	std::cout << "High two should beat high ace: " << single_two.beats(single_ace) << "\n";

	std::cout.flush();
}
