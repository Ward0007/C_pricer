#include "CRRPricer.h"
#include "cmath"
#include "Option.h"
CRRPricer::CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate) 
	:option(option), N(depth), S_0(asset_price), U(up), D(down), R(interest_rate) {
	if (asset_price <= 0 || down<-1 || down > up || interest_rate <= -1 || interest_rate > up) {
		std::cout << "Arbitrage is possible" << std::endl;
	}
}

void CRRPricer::compute() {
	double q = (R - D) / (U - D);
	tree.setDepth(N);
	for (i = 0, i <= N, i++) {
		double stock_price = S_0 * std::pow(1 + D, n - i) * std::pow(1 + U, i);
		tree.setNode(N, i, option->payoff(stock_price));
	}
	for (int n = N - 1; n >= 0; n--) {
		for (int i = 0; i <= n; i++) {
			tree.setNode(n, i, (q * tree.getNode(n + 1, i + 1) + (1 - q) * tree.getNode(n + 1, i)) / (1 + R));
		}
	}

}

int CRRPricer::get(int n, int i) {
	compute;
	tree.getNode(int n, int i);
}

int CRRPricer::operator(bool closed_form) {
	if (closed_form == true) {
		double q = (R - D) / (U - D);
		double H_0_0 = 0.0;
		for (i = 0, i <= N, i++) {
			double stock_price = S_0 * std::pow(1 + D, n - i) * std::pow(1 + U, i);
			H_0_0+=std::tgamma(N+1)*std::pow(q,i)*std::pow(1-q,N-i+1)*option->payoff(stock_price)/std::tgamma(i+1)*std::tgamma(N-i+1)
		}
		H_0_0 = H_0_0 / std::pow(1 + R, N);
		return H_0_0;
	}
	else {
		get(0, 0);
	}

}