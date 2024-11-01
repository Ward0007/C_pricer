#ifndef OPTION_H
#define OPTION_H
#pragma once
#include <iostream>
#include <vector>
enum class optionType {
    call,
    put 
};
enum class optionNature {
    digital,
    vanille,
    asian
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
    virtual double getStrike();
    double payoffPath(std::vector<double> prices);
    virtual std::vector<double> getTimeSteps();
    virtual optionNature GetOptionNature();
    virtual optionType GetOptionType();
    virtual bool isAsianOption() const;
    virtual ~Option(); 
};

#endif
#include "Option.cpp"
