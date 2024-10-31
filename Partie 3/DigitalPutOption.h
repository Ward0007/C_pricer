#pragma once
#include "EuropeanDigitalOption.h"

class DigitalPutOption : public EuropeanDigitalOption {
public:
	DigitalPutOption();
	DigitalPutOption(double, double);
	double payoff(double) override;
	optionType GetOptionType() override;
	~DigitalPutOption();
};