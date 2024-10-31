#ifndef EUROPEANVANILLAOPTION_H
#define EUROPEANVANILLAOPTION_H

#include "Option.h"
#include <stdexcept>

#pragma once

class EuropeanVanillaOption : protected Option {
protected:
    double _strike;   
    virtual optionType GetOptionType();
    optionNature GetOptionNature() override;
    friend class BlackScholesPricer;

public:
    EuropeanVanillaOption();
    EuropeanVanillaOption(double, double);
    virtual ~EuropeanVanillaOption();
    virtual double payoff(double ) = 0;
};

#endif
#include "EuropeanVanillaOption.cpp"
