#include "Matrix.hpp"
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>

Matrix::Matrix() : dimension{ 1 }
{
	contents = new double[1];
	clear();
}

Matrix::Matrix(int dimension) : dimension{ dimension }
{
	contents = new double[dimension * dimension];
	clear();

}

Matrix::Matrix(int an_array[], int size)
{
	dimension = (int)sqrt(size);
	if (dimension * dimension != size) {
		std::cout << "Invalid array size" << std::endl;
	}
	contents = new double[size];
	for (int i = 0; i < size; ++i) {
		contents[i] = an_array[i];
	}
}

/*
The matrix reads a text file and creates a matrix.
PRECONDITION: User file exists and correct path is passed in.
POSTCONDITION: Matrix created based on input of the text file.
*/
Matrix::Matrix(std::string user_input) {

	std::ifstream file;
	file.open(user_input);
	int var;
	std::vector<int> v;
	std::istringstream iss;
	if (!file) {
		std::cerr << "Unable to open file";
	}
	else {
		while (file >> var) {
			v.push_back(var);
		}
		int * input_array = &v[0];
		Matrix a = Matrix(input_array, v.size());
		swap(*this, a);
		
	}
}


Matrix::Matrix(const Matrix & other) : dimension{ other.dimension }
{
	contents = new double[dimension * dimension];
	for (int i = 0; i < dimension * dimension; ++i) {
		contents[i] = other.contents[i];
	}
}

void Matrix::set_value(int row, int column, double value)
{
	int index = row * dimension + column;
	contents[index] = value;
}

 int Matrix::get_value(int row, int column) const
{
	return contents[row * dimension + column];
}

int Matrix::get_dimension()
{
	return dimension;
}

void Matrix::clear()
{
	for (int i = 0; i < dimension * dimension; ++i) {
		contents[i] = 0;
	}
}

Matrix Matrix::identity()
{
	Matrix identity(dimension);
	for (int i = 0; i < dimension; ++i) {
		for (int j = 0; j < dimension; ++j) {
			if (i == j) {
				identity.set_value(i, j, 1);
			}
			else {
				identity.set_value(i, j, 0);
			}
		}
	}
	return identity;
}

Matrix & Matrix::operator++()
{
	for (int i = 0; i < dimension; ++i) {
		for (int j = 0; j < dimension; ++j) {
			contents[i * dimension + j] =
				1 + contents[i * dimension + j];
		}
	}
	return *this;
}

Matrix Matrix::operator++(int)
{
	Matrix temp(*this);
	operator++();
	return temp;
}

Matrix & Matrix::operator--()
{
	for (int i = 0; i < dimension; ++i) {
		for (int j = 0; j < dimension; ++j) {
			contents[i * dimension + j] =
				contents[i * dimension + j] - 1;
		}
	}
	return *this;
}

Matrix Matrix::operator--(int)
{
	Matrix temp(*this);
	operator--();
	return temp;
}

Matrix & Matrix::operator=(Matrix rhs)
{
	swap(*this, rhs);
	return *this;
}

Matrix & Matrix::operator+=(const Matrix & rhs)
{
	for (int i = 0; i < dimension; ++i) {
		for (int j = 0; j < dimension; ++j) {
			contents[i * dimension + j] +=
				rhs.contents[i * dimension + j];
		}
	}
	return *this;
}

Matrix & Matrix::operator*=(const double p)
{
	for (int i = 0; i < dimension; ++i) {
		for (int j = 0; j < dimension; ++j) {
			double val = contents[i * dimension + j] * p;
			contents[i * dimension + j] = val;
		}
	}
	std::cout << "THE MATRIX : \n" << *this << std::endl;
	return *this;
}

Matrix & Matrix::operator-=(const Matrix & rhs)
{
	for (int i = 0; i < dimension; ++i) {
		for (int j = 0; j < dimension; ++j) {
			contents[i * dimension + j] -=
				rhs.contents[i * dimension + j];
		}
	}
	return *this;
}

Matrix::~Matrix()
{
	delete[] contents;

}

std::ostream & operator<<(std::ostream & out, const Matrix & matrix)
{
	for (int i = 0; i < matrix.dimension; ++i) {
		for (int j = 0; j < matrix.dimension; ++j) {
			out << std::setw(7) << matrix.contents[i * matrix.dimension + j];
		}
		out << "\n";
	}
	return out;
}

bool operator==(const Matrix& lhs, const Matrix& rhs) {
	if (lhs.dimension != rhs.dimension) {
		return false;
	}
	for (int i = 0; i < lhs.dimension; i++) {
		for (int j = 0; j < lhs.dimension; j++) {
			if (lhs.get_value(i, j) != rhs.get_value(i, j)) {
				return false;
			}
		}
	}
	return true;
}

bool operator!=(const Matrix& lhs, const Matrix& rhs)
{
	return !operator==(lhs, rhs);
}

bool operator<(const Matrix & lhs, const Matrix & rhs)
{
	return lhs.dimension < rhs.dimension;
}

bool operator>(const Matrix& lhs, const Matrix& rhs)
{
	return operator<(rhs, lhs);
}

bool operator<=(const Matrix& lhs, const Matrix& rhs)
{
	return !operator> (lhs, rhs);
}

void swap(Matrix & lhs, Matrix & rhs)
{
	using std::swap;
	swap(lhs.dimension, rhs.dimension);
	swap(lhs.contents, rhs.contents);
}

Matrix operator+(Matrix lhs, const Matrix & rhs)
{
	lhs += rhs;
	return lhs;
}

Matrix operator*(Matrix lhs, const double p) {
	lhs *= p;
	return lhs;
}

Matrix operator-(Matrix lhs, const Matrix & rhs)
{
	lhs -= rhs;
	return lhs;
}

bool operator>=(const Matrix& lhs, const Matrix& rhs)
{
	return !operator< (lhs, rhs);
}
