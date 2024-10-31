#include "EuropeanDigitalOption.h"
#include <stdexcept>
#include <string>
#include <iostream>

optionNature EuropeanDigitalOption::GetOptionNature() { return optionNature::digital; }

EuropeanDigitalOption::EuropeanDigitalOption(): _strike(0){}


EuropeanDigitalOption::EuropeanDigitalOption(double expiry, double strike) : Option(expiry), _strike(strike) {
    if (expiry < 0) {
        throw std::invalid_argument("ERROR : Expiry " + std::to_string(expiry) + "is negative.");
    }
    if (strike < 0) {
        throw std::invalid_argument("ERROR : Strike " + std::to_string(strike) + " is negative.");
    }
}
EuropeanDigitalOption::optionType EuropeanDigitalOption::GetOptionType() {
    throw std::logic_error("GetOptionType is not implemented for EuropeanVanillaOption");
}
EuropeanDigitalOption::~EuropeanDigitalOption() {}