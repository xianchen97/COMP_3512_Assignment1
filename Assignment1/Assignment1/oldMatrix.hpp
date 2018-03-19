#pragma once

#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>

class Matrix
{
	int dimension;
	std::vector <int> contents;
	std::ifstream file;

public:
	Matrix(std::string);
	Matrix(int dimension);
	Matrix(const Matrix&);
	~Matrix();
	void set_value(int row, int column, int value);
	inline int get_dimension();
	inline int get_value(int, int) const;
	void clear();
	friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);
	Matrix& operator=(Matrix rhs);
	friend void swap(Matrix& lhs, Matrix& rhs);

	//File reading items
	void open_file(std::string);
	
};