#pragma once
#include "Matrix.hpp"
class PageRank {


	Matrix user_matrix;
	Matrix connectivity;
	Matrix dynamical;

	void create_connectivity();

	void create_dynamical();
};