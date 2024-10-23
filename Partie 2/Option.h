#ifndef OPTION_H
#define OPTION_H

#pragma once

class Option
{
private:
    double _expiry;
    virtual double payoff(double) =0;

public:
    Option();
    Option(double _Expiry):_expiry(_Expiry){};
    double getExpiry() {return _expiry;}
    ~Option(){};
};

#endif