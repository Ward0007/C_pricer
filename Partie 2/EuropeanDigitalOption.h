#pragma once
#include "Option.h"
#include <iostream>

class EuropeanDigitalOption: protected Option {
protected:
    double _strike;
    virtual optionType GetOptionType();
    optionNature GetOptionNature() override;
    friend class BlackScholesPricer;
public:
    EuropeanDigitalOption();
    EuropeanDigitalOption(double, double);
    virtual ~EuropeanDigitalOption();
    virtual double payoff(double) = 0;

};