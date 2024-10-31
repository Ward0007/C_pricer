#pragma once
#include "Option.h"
#include <iostream>

class EuropeanDigitalOption: protected Option {
protected:
    double _strike;
    enum class optionType { DigitalCall, DigitalPut };
    virtual optionType GetOptionType();
public:
    EuropeanDigitalOption();
    EuropeanDigitalOption(double, double);
    virtual ~EuropeanDigitalOption();
    virtual double payoff(double) = 0;

};