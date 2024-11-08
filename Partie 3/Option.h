#ifndef OPTION_H
#define OPTION_H

#pragma once

class Option
{
private:
    double _expiry;
    
public:
    Option();
    Option(double);
    virtual double payoff(double) const= 0;
    virtual ~Option(); 
    double getExpiry() const;  
};

#endif
#include "Option.cpp"
