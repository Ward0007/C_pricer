#pragma once
#include 'Option.h'
#include <iostream>
#include <vector>

class AsianOtpion :public Option {
private:
	std::vector<double> _time;
public:
	AsianOtpion(std::vector<double> times);
	virtual optionType GetOptionType();
	optionNature GetOptionNature() override;
	double getExpiry() const override;
	double getStrike() const;
	vector<double> getTimeSteps() override;
	bool isAsianOption() const override;
};