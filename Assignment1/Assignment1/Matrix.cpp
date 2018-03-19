#include "Matrix.hpp"
#include <cmath>
#include <sstream>

Matrix::Matrix(std::string file_name) {
	int line;
	Matrix::open_file(file_name);
	while (file >> var) {
		if (!isdigit(line)) {
			std::cerr << "Your matrix should only contain numbers";
		}
		contents.push_back(var);
	}
	if()

}

Matrix::Matrix(const Matrix & other) : dimension{ other.dimension }
{
	for (int i = 0; i < dimension * dimension; ++i) {
		contents.push_back(other.contents[i]);
	}
}


inline int Matrix::get_value(int row, int column) const
{
	return contents[row * dimension + column];
}

void Matrix::clear()
{
	for (int i = 0; i < dimension * dimension; ++i) {
		contents[i] = 0;
	}
}



Matrix & Matrix::operator=(Matrix rhs)
{
	swap(*this, rhs);
	return *this;
}

void Matrix::open_file(std::string user_input)
{
	file.open(user_input);
	if (!file) {
		std::cerr << "Unable to open file";
	}
}

Matrix::~Matrix()
{

}

std::ostream & operator<<(std::ostream & out, const Matrix & matrix)
{
	for (int i = 0; i < matrix.dimension; ++i) {
		for (int j = 0; j < matrix.dimension; ++j) {
			out << matrix.contents[i * matrix.dimension + j];
		}
		out << "\n";
	}
	return out;
}


void swap(Matrix & lhs, Matrix & rhs)
{
	using std::swap;
	swap(lhs.dimension, rhs.dimension);
	swap(lhs.contents, rhs.contents);
}

