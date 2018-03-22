#include "PageRank.hpp"
#include <vector>


/*
Constructor initialize all matrixes to have their base sizes.
*/
PageRank::PageRank(std::string user_input)
{
	Matrix a = Matrix(user_input);
	user_matrix = a;
	probability_matrix = user_matrix;
	dynamical_matrix = Matrix(user_matrix.get_dimension());
	matrix_Q = user_matrix;
	matrix_dim = user_matrix.get_dimension();
	dynamical = new double[matrix_dim];
	dynamicalMult = new double[matrix_dim];
	for (int i = 0; i < matrix_dim; i++) {
		dynamical[i] = 1;
	}
}

/* Prints out the probability matrix. */
void PageRank::print_prob_matrix() {
	std:: cout << probability_matrix;
}

/* Prints out Matrix Q. */
void PageRank::print_matrix_Q() {
	std::cout << matrix_Q;
}

/* 
Calculates the importance and generates the transition matrix.
Precondition: A user_matrix exists.
Postcondition: transition matrix created.*/
void PageRank::importance()
{
	std::vector<double> sums;
	int col_sum;
	for (int i = 0; i < matrix_dim; ++i) {
		col_sum = 0;
		for (int j = 0; j < matrix_dim; ++j) {
			col_sum += user_matrix.get_value(j, i);
		}
		sums.push_back(col_sum);	
	}

	for (int k = 0; k < matrix_dim; ++k) {
		for (int q = 0; q < matrix_dim; ++q) {
			if(sums[q] == 0){
				double val = 1 / (double)user_matrix.get_dimension();
				probability_matrix.set_value(k, q, val);
			}
			else {
				probability_matrix.set_value(k, q, user_matrix.get_value(k, q) / sums[q]);
			}
		}
	}

	
}

/*
Generates Matrix_Q.
Each element if the matrix is 1/dim.
Precondition: Matrix dimensions are initialized.
Postconidtion: Creates a matrix where each element in the matrix is 1/dim.
*/
void PageRank::generateQ() {
	for (int k = 0; k < matrix_dim; ++k) {
		for (int q = 0; q < matrix_dim; ++q) {
			double val = 1 / (double)matrix_Q.get_dimension();
			matrix_Q.set_value(k, q, val);
		}
	}
}


/*
Creates the transition matrix_m.
Precondition: probability_matrix and matrix_Q created.
Postconditon: Transition matrix is created.
Return: The transtion matrix.
*/
Matrix PageRank::transition()
{
	std::cout << "------------Transition----------- \n";
	Matrix m = (probability_matrix*p) + (matrix_Q*(1-p));
	std::cout << "Probability Matrix: \n" << probability_matrix * p << std::endl;
	std::cout << "Matrix_Q: \n" << matrix_Q * (1-p) << std::endl;
	std::cout << "Transition Matrix: \n" << m << std::endl;
	trans = m;
	return m;
}

/*
Multiplies the transition matrix.
PRECONDITION: Both Matrixes initialized
POSTCONDITION: Matrix multiplied with
*/
void PageRank::multiply() {
	double sum = 0.0;
	double * m = new double(matrix_dim);
	bool equals = false;
	do {
		bool currEquals = true;
		for (int i = 0; i < matrix_dim; i++) {
			for (int j = 0; j < 1; j++) {
				for (int k = 0; k < matrix_dim; k++) {
					sum = sum + (trans.get_value(i, k) * dynamical[k * 1 + j]);

				}
				dynamicalMult[(i * 1) + j] = sum;
				if (dynamical[(i * 1) + j] != dynamicalMult[(i * 1) + j]) {
					currEquals = false;
				}
				equals = currEquals;
				sum = 0;
			}
		}

		for (int i = 0; i < matrix_dim; i++) {
			dynamical[i] = dynamicalMult[i];
		}
	} while (equals == false);
}

void PageRank::print_dynamical() {
	std::cout << "The dynamical matrix: \n";
	for (int i = 0; i < matrix_dim; i++) {
		std::cout << dynamical[i] << std::endl;
	}
}

void PageRank::print_percent(){
	double sum = 0.0;
	for (int i = 0; i < matrix_dim; i++) {
		sum += dynamical[i];
	}
	std::cout << "\nRANK : " << std::endl;
	for (int i = 0; i < matrix_dim; i++) {
		std::cout << dynamical[i] << "/" << sum << " = " << dynamical[i]/sum << std::endl; 
	}

}


