#include "combo.h"
#include <vector>

using namespace combo;

Combo::Combo(std::vector<card::Card>) {
	// TODO evaluate combo
	
	// dummy values for now
	combo_type = single;
	rank_value = 1;
}

bool Combo::beats(const Combo& other) {
	return combo_type == other.combo_type && rank_value > other.rank_value;
}
