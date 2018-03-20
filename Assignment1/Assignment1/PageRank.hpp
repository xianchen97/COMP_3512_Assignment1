#pragma once

#include "Matrix.hpp"

class PageRank {
	Matrix probability_matrix;
	Matrix dynamical_matrix;
	Matrix user_matrix;
	Matrix matrix_Q;


public:
	static const int p = 0.85;
	PageRank(std::string user_input);
	void print_prob_matrix();
	void importance();
	void generateQ();
};
