#pragma once
#include <iostream>
#include "BinaryTree.h"
#include "BinaryTree.cpp"

class CRRPricer {
private:
	Option* option;
	int N;
	double S_0;
	double U;
	double D;
	double R;
	BinaryTree<int> tree;

public:
	CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate);
	void compute();
	int get(int n, int i);
	int operator()(bool closed_form=false);


	~CRRPricer();
};