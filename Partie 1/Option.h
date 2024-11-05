#ifndef OPTION_H
#define OPTION_H

#pragma once

class Option
{
private:
    double _expiry;
protected:
    virtual double payoff(double) const= 0;
    double getExpiry() const;  
public:
    Option();
    Option(double);
    virtual ~Option(); 
};

#endif
#include "Option.cpp"
