#include "PageRank.hpp"

void PageRank::create_connectivity()
{
	int num_of_elements;
	connectivity = Matrix(user_matrix);
	for (int i = 0; i < user_matrix.get_dimension(); ++i) {
		num_of_elements = 0;
		for (int j = 0; j < user_matrix.get_dimension(); ++j) {
			if (user_matrix.get_value(j,i) != 0) {
				num_of_elements++;
			}
		}
	}
}

