#ifndef OPTION_H
#define OPTION_H

#pragma once

class Option
{
protected:
    double _expiry;
    double getExpiry(){
        return _expiry;
    }
    virtual double payoff(double) =0;
public:
    Option();
    Option(double _Expiry):_expiry(_Expiry){};
    ~Option(){};
};

#endif