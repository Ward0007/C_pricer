#ifndef PUTOPTION_H
#define PUTOPTION_H
#include "EuropeanVanillaOption.h"
#pragma once

class PutOption : public EuropeanVanillaOption {
public:
    PutOption(double _Expiry, double _Strike) : EuropeanVanillaOption(_Expiry, _Strike) {}
    double payoff(double z) {
        if (_strike >= z){
        return _strike-z;
        }
        else{return 0;}
    }

    override optionType GetOptionType(){
        return put;
    }
};
#endif