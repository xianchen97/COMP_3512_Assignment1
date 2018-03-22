#pragma once

#include "Matrix.hpp"

class PageRank {
	Matrix probability_matrix;
	Matrix dynamical_matrix;
	Matrix user_matrix;
	Matrix matrix_Q;
	Matrix matrix_M;
	Matrix trans;

	int matrix_dim;
	double * dynamical;
	double * dynamicalMult;


public:
	static constexpr double p = 0.85;
	PageRank(std::string user_input);
	void print_prob_matrix();
	void print_matrix_Q();
	void importance();
	void generateQ();
	Matrix transition();
	void multiply();
	void print_dynamical();

	void print_percent();

	
};
