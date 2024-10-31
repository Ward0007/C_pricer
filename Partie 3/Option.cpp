#include "Option.h"

Option::Option() : _expiry(0) {}

Option::Option(double _Expiry) : _expiry(_Expiry) {}

double Option::getExpiry() {
    return _expiry;
}

Option::~Option() {}