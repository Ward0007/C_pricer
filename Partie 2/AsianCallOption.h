#pragma once
#include "AsianOption.h"
#include <iostream>
#include <vector>


class AsianCallOption :public AsianOption {
private:
	double _strike;
	std::vector<double> _time;
public:
	AsianCallOption(std::vector<double> times, double strikes);
	optionType GetOptionType() override;
	double getStrike() const override;
	double payoff(double) override;
	double payoffPath(std::vector<double> prices);
};