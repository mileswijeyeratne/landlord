#include "card.h"

namespace card {

Card::Card(int value, Suit suit) : value(value), suit(suit) {}


std::ostream& operator<<(std::ostream& os, const Card& card) {
	if (card.suit == joker) {
		switch (card.value) {
			case 1: os << "Red"; break;
			case 2: os << "Black"; break;
			default: os << "Bad val: " << card.value; break;
		}
		os << " Joker";
		return os;
	}

	switch (card.value) {
		case 3: os << "Three"; break;
		case 4: os << "Four"; break;
		case 5: os << "Five"; break;
		case 6: os << "Six"; break;
		case 7: os << "Seven"; break;
		case 8: os << "Eight"; break;
		case 9: os << "Nine"; break;
		case 10: os << "Ten"; break;
		case JACK: os << "Jack"; break;
		case QUEEN: os << "Queen"; break;
		case KING: os << "King"; break;
		case ACE: os << "Ace"; break;
		case TWO: os << "Two"; break;
		default: os << "Bad val: " << card.value; break;
	}

	os << " of ";

	switch (card.suit) {
		case clubs: os << "clubs"; break;
		case diamonds: os << "diamonds"; break;
		case hearts: os << "hearts"; break;
		case spades: os << "spades"; break;
		default: os << "invalid"; break;
	}

	return os;
}

}
