#include "BlackScholesPricer.h"
using namespace std;
#include <math.h> 
BlackScholesPricer::BlackScholesPricer(EuropeanVanillaOption* option, double asset_price, double interest_rate, double volatility)
:Option_(option), Asset_price_(asset_price), Interest_rate_(interest_rate), Volatility_(volatility)
{

}

BlackScholesPricer::~BlackScholesPricer()
{}
double BlackScholesPricer::operator()() {
    double S = Asset_price_;
    double K = Option_->_strike;  
    double r = Interest_rate_;
    double T = Option_->getExpiry();
    double sigma = Volatility_;
    double d1, d2, prix;
    d1= (1/(sigma * sqrt(T)))*(log(S / K) + (r + 0.5 * sigma*sigma) * T) ;
    d2 = d1 - sigma *sqrt(T);
    if (Option_->GetOptionType() == EuropeanVanillaOption::optionType::call) {
        prix = S*(1-0.5 * erfc(d1/sqrt(2))) - K * exp(-r * T) * (1-0.5 *erfc(d2 /sqrt(2)));
    } 
    else {
        prix = -S*(1-0.5 * erfc(-d1/sqrt(2))) + K * exp(-r * T) * (1-0.5 *erfc(-d2 /sqrt(2)));
    }
    
    return prix;
}
double BlackScholesPricer::delta(){
    double S = Asset_price_;
    double K = Option_->_strike;  
    double r = Interest_rate_;
    double T = Option_->getExpiry();
    double sigma = Volatility_;
    double d,Delta;
    d= (log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma *sqrt(T));
    if (Option_->GetOptionType() == EuropeanVanillaOption::optionType::call) {
        Delta = 1-0.5 * erfc(d/sqrt(2));
    } 
    else {
        Delta = -0.5 * erfc(d/sqrt(2));
    }
    
    return Delta;
    }