#ifndef CALLOPTION_H
#define CALLOPTION_H
#include "EuropeanVanillaOption.h"
#pragma once

class CallOption : protected EuropeanVanillaOption {
public:
    CallOption(double expiry, double strike) : EuropeanVanillaOption(expiry, strike) {}
    double payoff(double z) {
        if (z > getst)
        return () ? (z - _strike) : 0.0;
    }
    optionType GetOptionType() {
        return optionType::call;
    }
};

#endif