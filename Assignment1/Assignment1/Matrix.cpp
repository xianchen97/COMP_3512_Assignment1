#include "Matrix.hpp"
#include <cmath>
#include <iostream>

Matrix::Matrix() : dimension{ 1 }
{
	contents = new int[1];
	clear();
}

Matrix::Matrix(int dimension) : dimension{ dimension }
{
	contents = new int[dimension * dimension];
	clear();

}

Matrix::Matrix(int an_array[], int size)
{
	dimension = (int)sqrt(size);
	if (dimension * dimension != size) {
		std::cout << "Invalid array size" << std::endl;
	}
	contents = new int[size];
	for (int i = 0; i < size; ++i) {
		contents[i] = an_array[i];
	}
}

Matrix::Matrix(std::string user_input) {

}

Matrix::Matrix(const Matrix & other) : dimension{ other.dimension }
{
	contents = new int[dimension * dimension];
	for (int i = 0; i < dimension * dimension; ++i) {
		contents[i] = other.contents[i];
	}
}

inline void Matrix::set_value(int row, int column, int value)
{
	int index = row * dimension + column;
	contents[index] = value;
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
			out << matrix.contents[i * matrix.dimension + j];
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

Matrix operator-(Matrix lhs, const Matrix & rhs)
{
	lhs -= rhs;
	return lhs;
}

bool operator>=(const Matrix& lhs, const Matrix& rhs)
{
	return !operator< (lhs, rhs);
}
