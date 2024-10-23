#ifndef CALLOPTION_H
#define CALLOPTION_H
#include "EuropeanVanillaOption.h"
#pragma once

class CallOption : protected EuropeanVanillaOption {
public:
    CallOption(double _Expiry, double _Strike) : EuropeanVanillaOption(_Expiry, _Strike) {}
    double payoff(double z) {
        if (z >= _Strike){
        return 
        }
    }
    optionType GetOptionType() {
        return optionType::call;
    }
};

#endif