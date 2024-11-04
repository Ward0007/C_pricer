#pragma once
#include "Option.h"
#include <iostream>
#include <vector>

class AsianOtpion :public Option {
private:
	std::vector<double> _time;
	double _strike;
public:
	AsianOtpion(std::vector<double> times, double strike);
	virtual optionType GetOptionType();
	optionNature GetOptionNature() override;
	double getExpiry() const override;
	double getStrike() const;
	virtual std::vector<double> getTimeSteps();
	bool isAsianOption() const override;
};