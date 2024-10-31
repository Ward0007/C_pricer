#include "PutOption.h"

PutOption::PutOption() {}

PutOption::PutOption(double _Expiry, double _Strike) : EuropeanVanillaOption(_Expiry, _Strike) {}

double PutOption::payoff(double z) {
    if (_strike >= z) {
        return _strike - z;
    } else {
        return 0;
    }
}

optionType PutOption::GetOptionType() {
    return optionType::put;
}
PutOption::~PutOption() {}
