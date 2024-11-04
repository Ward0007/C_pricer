#include "AsianOption.h"
#include <vector>
#include <iostream>

optionNature AsianOption::GetOptionNature() { return optionNature::asian; }

AsianOption::AsianOption(std::vector<double> times, double strike) : _time(times), _strike(strike) {}

std::vector<double> AsianOption::getTimeSteps() { return _time; }

double AsianOption::getExpiry() {return 0.0;}

double AsianOption::getStrike() { return 0.0; }

bool AsianOption::isAsianOption() {
    return true;
}