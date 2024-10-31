#include "DigitalCallOption.h"

DigitalCallOption::DigitalCallOption(){}

DigitalCallOption::DigitalCallOption(double _Expiry,double _Strike):EuropeanDigitalOption(_Expiry,_Strike){}

double DigitalCallOption::payoff(double z){
	if (z >= _strike) {
		return 1;
	}
	else {
		reutrn 0;
	}
}
DigitalCallOption::optionType DigitalCallOption::GetOptionType() {
	return optionType::DigitalCall;
}

DigitalCallOption::~DigitalCallOption() {}