#ifndef EUROPEANVANILLAOPTION_H
#define EUROPEANVANILLAOPTION_H
#include "Option.h"
#include <stdexcept>
#pragma once

class EuropeanVanillaOption: protected Option{
    
    private:
        double _strike;

    public:
        EuropeanVanillaOption(){}
        EuropeanVanillaOption(double expiry, double strike) : Option(expiry), _strike(strike)
    {
        if (expiry < 0) {
            throw std::invalid_argument("ERROR : Expiry value is negative.");
        }
        if (strike < 0) {
            throw std::invalid_argument("ERROR : Strike value is negative.");
        }
    }
        ~EuropeanVanillaOption();


};

#endif
