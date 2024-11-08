#ifndef ASIANPUTOPTION_H
#define ASIANPUTOPTION_H

#include "AsianOption.h"

#pragma once

class AsianPutOption : public AsianOption {
public:
    AsianPutOption();
    AsianPutOption(double, double, const std::vector<double>& );
    double payoff(double) const override;  
    optionType GetOptionType() const override;   
    ~AsianPutOption();
};

#endif
#include "AsianPutOption.cpp"
