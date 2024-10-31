#include "DigitalPutOption.h"

DigitalPutOption::DigitalPutOption() {}

DigitalPutOption::DigitalPutOption(double _Expiry, double _Strike) :EuropeanDigitalOption(_Expiry, _Strike) {}

double DigitalPutOption::payoff(double z) {
	if (z <= _strike) {
		return 1;
	}
	else {
		reutrn 0;
	}
}
DigitalPutOption::optionType DigitalPutOption::GetOptionType() {
	return optionType::DigitalCall;
}

DigitalPutOption::~DigitalPutOption() {}