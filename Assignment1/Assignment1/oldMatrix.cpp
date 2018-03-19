#include "Matrix.hpp"
#include <cmath>
#include <sstream>

Matrix::Matrix(std::string file_name) {
	int var;
	Matrix::open_file(file_name);
	while (file >> var) {
		contents.push_back(var);
	}	
	int size = contents.size() / 2;
	if (size*size != contents.size()) {
		std::cerr << "Incorrect Matrix size";
	}
	dimension = size;

}

Matrix::Matrix(int dimension) : dimension{ dimension } {
};

Matrix::Matrix(const Matrix & other) : dimension{ other.dimension }
{
	for (int i = 0; i < dimension * dimension; ++i) {
		contents.push_back(other.contents[i]);
	}
}


inline int Matrix::get_dimension()
{
	return dimension;
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

inline void Matrix::set_value(int row, int column, int value)
{
	int index = row * dimension + column;
	contents[index] = value;
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

