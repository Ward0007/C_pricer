#pragma once
#include <iostream>
#include "BinaryTree.h"
#include "BinaryTree.cpp"
#include "Option.h"

class CRRPricer {
private:
	Option* option;
	int N;
	double S_0;
	double U;
	double D;
	double R;
	BinaryTree<double> tree;

public:
	CRRPricer(Option*, int, double, double, double, double);
	void compute();
	double get(int n, int i) const;
	int operator()(bool closed_form=false);


	~CRRPricer();
};
#include "CRRPricer.cpp"