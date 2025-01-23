#pragma once

#include <ostream>

namespace card {

const int JACK  = 11;
const int QUEEN = 12;
const int KING  = 13;
const int ACE   = 14;
const int TWO   = 15;

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
