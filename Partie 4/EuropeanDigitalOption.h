#ifndef EUROPEANDIGITALOPTION_H
#define EUROPEANDIGITALOPTION_H

#include "Option.h"
#include <stdexcept>

#pragma once

class EuropeanDigitalOption : public Option {
private:
    double _strike;
protected:
    enum class optionType { call, put };
    virtual optionType GetOptionType() = 0;  // Méthode virtuelle pure pour obtenir le type d'option
    double getStrike() const;
    friend class BlackScholesPricer;

public:
    EuropeanDigitalOption();
    EuropeanDigitalOption(double strike, double expiry);
    virtual ~EuropeanDigitalOption();
    friend class BlackScholesPricer;
};

#endif
#include "EuropeanDigitalOption.cpp"
