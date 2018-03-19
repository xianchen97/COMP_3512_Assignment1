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
	Matrix(const Matrix&);
	~Matrix();
	inline void set_value(std::string user_input, std::ifstream file);
	inline int get_value(int, int) const;
	void clear();
	friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);
	Matrix& operator=(Matrix rhs);
	friend void swap(Matrix& lhs, Matrix& rhs);

	//File reading items
	void open_file(std::string);
	
};