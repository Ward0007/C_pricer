#include "Option.h"

Option::Option() : _expiry(0) {}

Option::Option(double _Expiry) : _expiry(_Expiry) {}

double Option::getExpiry() {
    return _expiry;
}
double Option::payoffPath(std::vector<double> prices) {
    double price = 0.0;
    for (i = 0; i < prices.size(); i++) {
        price+=prices[i]
    }
    if (price / prices.size() >= getStrike()) {
        return price / prices.size() - getStrike();
    }
    else {
        return 0.0
    }
}
std::vector<double> Option::getTimeSteps() { 
    return std::vector<double> {0.0}; 
}
bool Option::isAsianOption() const {
    return false;
}

Option::~Option() {}
