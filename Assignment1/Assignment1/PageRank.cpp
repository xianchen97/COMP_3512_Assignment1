#include "PageRank.hpp"
#include <vector>

PageRank::PageRank(std::string user_input)
{
	Matrix a = Matrix(user_input);
	user_matrix = a;
	probability_matrix = user_matrix;
	dynamical_matrix = Matrix(user_matrix.get_dimension());
}

void PageRank::print_prob_matrix() {
	std:: cout << user_matrix;
}

void PageRank::importance()
{
	std::vector<double> sums;
	int col_sum;
	int dim = user_matrix.get_dimension();
	for (int i = 0; i < user_matrix.get_dimension(); ++i) {
		col_sum = 0;
		for (int j = 0; j < user_matrix.get_dimension(); ++j) {
			col_sum += user_matrix.get_value(j, i);
		}
		sums.push_back(col_sum);	
	}

	for (int k = 0; k < user_matrix.get_dimension(); ++k) {
		for (int q = 0; q < user_matrix.get_dimension(); ++q) {
			if(sums[q] == 0){
				double val = 1 / (double)user_matrix.get_dimension();
				user_matrix.set_value(k, q, val);
			}
			else {
				user_matrix.set_value(k, q, user_matrix.get_value(k, q) / sums[q]);
			}
		}
	}
}

void PageRank::generateQ() {
	Matrix q = user_matrix;
	for (int k = 0; k < q.get_dimension(); ++k) {
		for (int q = 0; q < q.get_dimension(); ++q) {
			double val = 1 / (double)q.get_dimension();
			user_matrix.set_value(k, q, val);
		}
	}
}

