#ifndef OPTION_H
#define OPTION_H

#pragma once

class Option
{
private:
    double _expiry;
protected:
    virtual double payoff(double) = 0;  
public:
    Option();
    Option(double);
    double getExpiry();
    virtual ~Option(); 
};

#endif
#include "Option.cpp"
