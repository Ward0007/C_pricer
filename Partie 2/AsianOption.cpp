#include "AsianOption.h"
#include <numeric>      
#include <stdexcept>   

AsianOption::AsianOption() : _strike(0.0) {}

AsianOption::AsianOption(double expiry, double strike, const std::vector<double>& time_steps)
    : Option(expiry), _strike(strike), Time_steps(time_steps) {}

AsianOption::~AsianOption() {}

double AsianOption::getStrike() const {
    return _strike;
}

const std::vector<double>& AsianOption::getTimeSteps() const {
    return Time_steps;
}

double AsianOption::payoffPath(std::vector<double>& prices) const {
    if (prices.empty()) {
        throw std::invalid_argument("Empty list");
    }
    double sum = 0.0;
    for (double price : prices) {
        sum += price;  
    }
    double average_price = sum / prices.size(); 
    return payoff(average_price); 
}
bool AsianOption::isAsianOption() const {
    return true;
}
