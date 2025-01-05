#pragma once

#include <ostream>

namespace card {

enum Suit {
	clubs,
	diamonds,
	hearts,
	spades,
	joker,
};

class Card {
public:
	const int value;
	const Suit suit;

	Card(int value, Suit suit);
};


std::ostream& operator<<(std::ostream& os, const Card& card);

}
