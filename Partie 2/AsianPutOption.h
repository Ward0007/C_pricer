#pragma once
#include "AsianOption.h"
#include <iostream>
#include <vector>


class AsianPutOption :public AsianOption {
private:
	double _strike;
	std::vector<double> _time;
public:
	AsianPutOption(std::vector<double> times, double strikes);
	optionType GetOptionType() override;
	double getStrike() const override;
	double payoff(double) override;
	double payoffPath(std::vector<double> prices);
};