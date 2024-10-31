#include "CallOption.h"

CallOption::CallOption() {}

CallOption::CallOption(double _Expiry, double _Strike) : EuropeanVanillaOption(_Expiry, _Strike) {}

double CallOption::payoff(double z) {
    if (z >= _strike) {
        return z - _strike;
    } else {
        return 0;
    }
}

CallOption::optionType CallOption::GetOptionType() {
    return optionType::call;
}

CallOption::~CallOption() {}
