#include "AsianPutOption.h"
#include <iostream>
#include <vector>

AsianPutOption::AsianPutOption(std::vector<double> times, double strikes) : AsianOption(times), _strike(strikes) {
	if (_strike < 0.0) {
		throw std::invalid_argument("ERROR: Strike negative");
	}
}

optionType AsianPutOption::GetOptionType() {
	return optionType::put;
}

double AsianPutOption::getStrike() {
	return _strike;
}
double AsianPutOption::payoffPath(std::vector<double> prices) {
	double price = 0;
	for (size_t i = 0; i < prices.size(); i++) {
		price += prices[i];
	}
	if (price / prices.size() <= GetStrike()) {
		return getStrike() - (price / prices.size());
	}
	else { 
		return 0.0;
	}
}



