#include 'AsianCallOption.h'
#include <iostream>
#include <vector>

AsianCallOption::AsianCallOption(vector<double> times, double strikes) : AsianOption(times), _strike(strikes) {
	if (_strike < 0.0) { 
		throw invalid_argument("ERROR: Strike negative"); 
	}
}

optionType AsianCallOption::GetOptionType() {
    return optionType::call;
}

double AsianCallOption::getStrike() { 
	return _strike; 
}
double AsianCallOption::payoffPath(vector<double> prices) {
	double price = 0;
	for (size_t i = 0; i < prices.size(); i++) {
		price += prices[i];
	}

	if (price / prices.size() >= getStrike()) {
		return price / prices.size() - getStrike();
	}
	else { 
		return 0.0; 
	}
}



