#include "AsianCallOption.h"

AsianCallOption::AsianCallOption() : AsianOption() {}

AsianCallOption::AsianCallOption(double expiry, double strike, const std::vector<double>& time_steps)
    : AsianOption(expiry, strike, time_steps) {}

double AsianCallOption::payoff(double price) const {
    double payoff_value = price - getStrike();
    if (payoff_value > 0.0) {
        return payoff_value;  
    } else {
        return 0.0;           
    }
}

AsianOption::optionType AsianCallOption::GetOptionType() const {
    return optionType::call;
}

AsianCallOption::~AsianCallOption() {}
