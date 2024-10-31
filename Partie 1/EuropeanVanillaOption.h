#ifndef EUROPEANVANILLAOPTION_H
#define EUROPEANVANILLAOPTION_H

#include "Option.h"
#include <stdexcept>

#pragma once

class EuropeanVanillaOption : protected Option {
protected:
    double _strike;  
    enum class optionType {call, put};  
    virtual optionType GetOptionType();  

public:
    EuropeanVanillaOption();
    EuropeanVanillaOption(double, double);
    virtual ~EuropeanVanillaOption();
    virtual double payoff(double ) = 0;
};

#endif
#include "EuropeanVanillaOption.cpp"
