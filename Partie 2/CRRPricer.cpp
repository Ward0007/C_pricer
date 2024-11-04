#include "CRRPricer.h"
#include "BinaryTree.h"
#include "BinaryTree.cpp"
#include "Option.h"
#include "cmath"

CRRPricer::CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate) 
	:option(option), N(depth), S_0(asset_price), U(up), D(down), R(interest_rate) {
	if (asset_price <= 0 || down<-1 || down > up || interest_rate <= -1 || interest_rate > up) {
		std::cout << "Arbitrage is possible" << std::endl;
	}
	else if (option->isAsianOption()) {
		throw std::runtime_error("ERROR");
	}
}

void CRRPricer::compute() {
	double q = (R - D) / (U - D);
	tree.setDepth(N);
	for (int i = 0; i <= N; i++) {
		double stock_price = S_0 * std::pow(1 + D, N - i) * std::pow(1 + U, i);
		tree.setNode(N, i, option->payoff(stock_price));
	}
	for (int j = N - 1; j >= 0; j--) {
		for (int i = 0; i <= j; i++) {
			tree.setNode(j, i, (q * tree.getNode(j + 1, i + 1) + (1 - q) * tree.getNode(j + 1, i)) / (1 + R));
		}
	}

}

int CRRPricer::get(int n, int i) {
	compute;
	tree.getNode(n, i);
}

int CRRPricer::operator()(bool closed_form) {
	if (closed_form == true) {
		double q = (R - D) / (U - D);
		double H_0_0 = 0.0;
		for (int i = 0; i <= N; i++) {
			double stock_price = S_0 * std::pow(1 + D, N - i) * std::pow(1 + U, i);
			H_0_0+=std::tgamma(N+1)*std::pow(q,i)*std::pow(1-q,N-i+1)*option->payoff(stock_price)/std::tgamma(i+1)*std::tgamma(N-i+1);
		}
		H_0_0 = H_0_0 / std::pow(1 + R, N);
		return H_0_0;
	}
	else {
		get(0, 0);
	}

}