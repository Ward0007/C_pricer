#ifndef OPTION_H
#define OPTION_H

#pragma once

class Option
{
private:
    double _expiry;

public:
    virtual double payoff(double) const= 0;
    Option();
    Option(double);
    virtual ~Option(); 
    double getExpiry() const;  
};

#endif
#include "Option.cpp"
