#pragma once

#include <iostream>
#include <string.h>

class Matrix
{
	int dimension;
	double * contents;

public:
	Matrix();
	Matrix(int);
	Matrix(int[], int);
	Matrix(const Matrix&);
	Matrix(std::string);
	~Matrix();
	void set_value(int, int, double);
	int get_value(int, int) const;
	int get_dimension();
	void clear();
	Matrix identity();
	friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);
	friend bool operator==(const Matrix& lhs, const Matrix& rhs);
	friend bool operator!=(const Matrix& lhs, const Matrix& rhs);
	friend bool operator<(const Matrix& lhs, const Matrix& rhs);
	friend bool operator>(const Matrix& lhs, const Matrix& rhs);
	friend bool operator>=(const Matrix& lhs, const Matrix& rhs);
	friend bool operator<=(const Matrix& lhs, const Matrix& rhs);
	Matrix& operator++();
	Matrix operator++(int);
	Matrix& operator--();
	Matrix operator--(int);
	Matrix& operator=(Matrix rhs);
	friend void swap(Matrix& lhs, Matrix& rhs);
	Matrix& operator+=(const Matrix& rhs);
	friend Matrix operator*(Matrix lhs, const double p);
	Matrix& operator*=(const double p);
	friend Matrix operator+(Matrix lhs, const Matrix& rhs);
	Matrix& operator-=(const Matrix& rhs);
	friend Matrix operator-(Matrix lhs, const Matrix& rhs);


};