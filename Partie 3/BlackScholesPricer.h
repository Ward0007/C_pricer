#ifndef BLACKSCHOLESPRICER_H
#define BLACKSCHOLESPRICER_H
#include "EuropeanVanillaOption.h"
#pragma once

class BlackScholesPricer
{
public:
    BlackScholesPricer(EuropeanVanillaOption* , double, double, double);
    ~BlackScholesPricer();
    double operator()();
    double delta();

protected:
    EuropeanVanillaOption* Option_;
    double Asset_price_;
    double Interest_rate_;
    double Volatility_;



};

#endif