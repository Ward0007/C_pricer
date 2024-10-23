#ifndef PUTOPTION_H
#define PUTOPTION_H
#include "EuropeanVanillaOption.h"
#pragma once

class PutOption : public EuropeanVanillaOption {
public:
    PutOption(double expiry, double strike) : EuropeanVanillaOption(expiry, strike) {}
    double payoff(double z) {
        return (z < _strike) ? (_strike - z) : 0.0;
    }

    optionType GetOptionType(){
        return optionType::put;
    }
};
#endif