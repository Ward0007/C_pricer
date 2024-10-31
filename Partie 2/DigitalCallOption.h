#pragma once

#include "EuropeanDigitalOption.h"

class DigitalCallOption : public EuropeanDigitalOption {
public:
	DigitalCallOption();
	DigitalCallOption(double, double);
	double payoff(double) override;
	optionType GetOptionType() override;
	~DigitalCallOption();
};