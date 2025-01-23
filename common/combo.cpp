#include "combo.h"
#include <cassert>
#include <vector>
#include <algorithm>
#include <unordered_map>


namespace combo {

std::unordered_map<int, int> count(const std::vector<card::Card>& cards) {
	std::unordered_map<int, int> res;
	for (card::Card card : cards) {
		res.emplace(card.value, 0).first->second++;
	}
	return res;
}

bool all_same_value(const std::vector<card::Card>& cards, const std::unordered_map<int, int>& counts) {
	return counts.at(cards[0].value) == cards.size();
}

std::vector<int> sorted_frequencies(const std::unordered_map<int, int> counts) {
	std::vector<int> frequencies;
	frequencies.reserve(counts.size());
	for (auto [_, freq] : counts) {
		frequencies.push_back(freq);
	}
	std::sort(frequencies.begin(), frequencies.end());
	return frequencies;
}

bool is_sequential(std::vector<int> values) {
	std::sort(values.begin(), values.end());

	int last = values.at(0);

	for (int i = 1; i < values.size(); i++) {
		int cur = values.at(i);
		if (cur != last + 1) {
			return false;
		}
		last = cur;
	}
	return true;
}


Combo::Combo(const std::vector<card::Card>& cards) {
	std::unordered_map<int, int> counts = count(cards);
	std::vector<int> frequencies = sorted_frequencies(counts);

	if (cards.size() == 1) {
		combo_type = single;
		rank_value = cards[0].value;
		return;
	}

	else if (cards.size() == 2 && all_same_value(cards, counts)) {
		if (cards[0].suit == card::joker) {
			combo_type = rocket;
			rank_value = cards[0].value;
			return;
		}
		combo_type = pair;
		rank_value = cards[0].value;
		return;
	}

	else if (cards.size() == 3 && all_same_value(cards, counts)) {
		combo_type = triplet;
		rank_value = cards[0].value;
		return;
	}

	else if (cards.size() == 4 && all_same_value(cards, counts)) {
		combo_type = bomb;
		rank_value = cards[0].value;
		return;
	}

	else if (cards.size() == 4 && frequencies == std::vector{1, 3}) {
		combo_type = triplet_with_single;
		for (const card::Card& card : cards) {
			if (counts[card.value] == 3) {
				rank_value = card.value;
				break;
			}
		}
		return;
	}

	else if (cards.size() == 5 && frequencies == std::vector{2, 3}) {
		combo_type = triplet_with_pair;
		for (const card::Card& card : cards) {
			if (counts[card.value] == 3) {
				rank_value = card.value;
				break;
			}
		}
		return;
	}

	else if (cards.size() == 5 && frequencies == std::vector{1, 1, 1, 1, 1}) {
		// check if sequencial
		combo_type = sequence;
		return;
	}

	combo_type = invalid;
}

bool Combo::beats(const Combo& other) {
	assert(combo_type != invalid && other.combo_type != invalid);

	// have a rocket
	if (combo_type == rocket && other.combo_type != rocket) {
		return true;
	}

	// have a bomb
	if (combo_type == bomb && other.combo_type != rocket && other.combo_type != rocket) {
		return true;
	}

	// different combo
	if (combo_type != other.combo_type) {
		return false;
	}

	// other person has rocket or bomb
	if (other.combo_type == bomb || other.combo_type == rocket) {
		return false;
	}

	return rank_value > other.rank_value;
}

}
