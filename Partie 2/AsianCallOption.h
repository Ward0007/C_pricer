#ifndef ASIANCALLOPTION_H
#define ASIANCALLOPTION_H

#include "AsianOption.h"

#pragma once

class AsianCallOption : public AsianOption {
public:
    AsianCallOption();
    AsianCallOption(double, double, const std::vector<double>&);
    double payoff(double) const override;  
    optionType GetOptionType() const override;   
    ~AsianCallOption();
};

#endif
#include "AsianCallOption.cpp"
