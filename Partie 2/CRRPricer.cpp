#include "CRRPricer.h"
#include <cmath>
#include <stdexcept>

CRRPricer::CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate) 
	:option(option), N(depth), S_0(asset_price), U(up), D(down), R(interest_rate) {
	if (option->isAsianOption()) {
        throw std::invalid_argument("CRRPricer ne prend pas en charge les options asiatiques.");
    }
	if (!( down < interest_rate && interest_rate <up )) {
		throw std::invalid_argument( "ERROR : Arbitrage is possible" );
	}
	tree.setDepth(N + 1);
}

void CRRPricer::compute() {
	double q = (R - D) / (U - D);
	tree.setDepth(N);
	for (int i = 0; i <= N; i++) {
		double stock_price = S_0;
		for(int j=0; j<i;j++)
		{
			stock_price*=(1+U);
		}
		for ( int j=0; j<(N-1);j++)
		{
			stock_price*=(1+D);
		}
	
		tree.setNode(N, i, option->payoff(stock_price));
	}
	for (int n = N - 1; n >= 0; n--) {
		for (int i = 0; i <= n; i++) {
			tree.setNode(n, i, (q * tree.getNode(n + 1, i + 1) + (1 - q) * tree.getNode(n + 1, i)) / (1 + R));
		}
	}

}

double CRRPricer::get(int n, int i) const {
    return tree.getNode(n, i);
}

double CRRPricer::operator()(bool closed_form) {
    if (closed_form) {
        double q = (R - D) / (U - D);
        double H_0_0 = 0;

        for (int i = 0; i <= N; i++) {
            double up_factor = std::pow(U + 1, i);
            double down_factor = std::pow(D + 1, N - i);
            double stock_price = S_0 * up_factor * down_factor;
            H_0_0 += tgamma(N + 1) * pow(q, i) * pow(1 - q, N - i) * option->payoff(stock_price) / (tgamma(i + 1) * tgamma(N - i + 1));
        }
        H_0_0 = H_0_0 * (1 / pow(1 + R, N));
        return H_0_0;
    } else {
		compute();
        return get(0,0);
    }
}

CRRPricer::~CRRPricer(){}