#ifndef OPTION_H
#define OPTION_H

#pragma once
enum class optionType {
    call,
    put 
};
enum class optionNature {
    digital,
    vanille
};
class Option
{
private:
    double _expiry;
protected:
    virtual double payoff(double) = 0;
    friend class BlackScholesPricer
public:
    Option();
    Option(double);
    double getExpiry();
    virtual optionNature GetOptionNature();
    virtual optionType GetOptionType();
    virtual ~Option(); 
};

#endif
#include "Option.cpp"
