#pragma once

#include <vector>
#include "card.h"

namespace combo {

// https://www.pagat.com/climbing/doudizhu.html
enum ComboType {
	invalid,
	single,
	pair,
	triplet,
	triplet_with_single,
	triplet_with_pair,
	sequence,
	sequence_of_pairs,
	sequence_of_triplets,
	sequence_of_triplets_with_singles,
	sequence_of_triplets_with_pairs,
	quadplex_with_singles,
	quadplex_with_pairs,
	bomb,
	rocket,
};

class Combo {
public:
	ComboType combo_type;
	int rank_value;

	Combo(const std::vector<card::Card>& cards);

	bool beats(const Combo& other);
};

}
