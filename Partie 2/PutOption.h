#ifndef PUTOPTION_H
#define PUTOPTION_H

#include "EuropeanVanillaOption.h"
#pragma once

class PutOption : public EuropeanVanillaOption {
public:
    PutOption();
    PutOption(double, double);
    double payoff(double) override;
    optionType GetOptionType() override;
    ~PutOption();
};

#endif 
#include "PutOption.cpp"
