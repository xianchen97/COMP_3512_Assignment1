#include "Matrix.hpp"
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>


/*
Default constructor creates a matrix of dimension 1 with value 0.
*/
Matrix::Matrix() : dimension{ 1 }
{
	contents = new double[1];
	clear();
}


/*
Matrix Constructor that accepts an integer for the size of the array.
Accepts the size of the matrix and defaults all values to zero.
PRECONDITION:   DIMENSION HAS TO BE GREATER THAN ZERO
POSTCONDITION:  ARRAY IN MATRIX CLASS INITIALIZED FOR THE SPECIFIC SIZE
*/
Matrix::Matrix(int dimension) : dimension{ dimension }
{
	contents = new double[dimension * dimension];
	clear();

}

/*
Takes an array with it's dimension and creates with given values.
PRECONDITION:  ARRAY MUST BE GREATER THAN ZERO, DIMENSIONS A SQUARE VALUE
POSTCONDITION: MATRIX OF SIZE dim created with values from given array
*/
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


/*
Takes a reference of a Matrix and assigns it's values to the current matrix
PRECONDITION:  MATRIX MUST ATLEAST BE OF SIZE 1
POSTCONDTION:  MATRIX WITH THE SAME VALUES OF THE REVERENCE MATRIX.
*/
Matrix::Matrix(const Matrix & other) : dimension{ other.dimension }
{
	contents = new double[dimension * dimension];
	for (int i = 0; i < dimension * dimension; ++i) {
		contents[i] = other.contents[i];
	}
}

/*
Changes values at a specific row and col.
PRECONDITION:   ROW AND COL START AT ZERO, VALUES DO NOT GO OUT OF BOUNDS
POSTCONDITION:  VALUE IS CHANGED AT THE POSITION
RETURN:         VOID
*/
void Matrix::set_value(int row, int column, double value)
{
	int index = row * dimension + column;
	contents[index] = value;
}

/*
Returns value at a specific row and col.
PRECONDITION:   ROW AND COL START AT ZERO, VALUES DO NOT GO OUT OF BOUNDS
POSTCONDITION:  RETURNS VALUE AT THE POSITION
RETURN:         VOID
*/
 double Matrix::get_value(int row, int column) const
{
	return contents[row * dimension + column];
}


/*
Get the dimension of the matrix.
*/
int Matrix::get_dimension()
{
	return dimension;
}

/*
Sets matrix to be zero
PRECONDITION:  Matrix has to be atleast of size 1.
POSTCONDITION: All values of the Matrix has been intiaized to zero.
*/
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

/*
Increment all the values in the array using prefix
PRECONDITION: Array of at least size 1
POSTCONDITION: Values in the array incremented by one.
*/
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

/*
Increment all the values in the array using postfix.
PRECONDITION: Array of at least size 1
POSTCONDITION: Values in the array incremented by one.
*/
Matrix Matrix::operator++(int)
{
	Matrix temp(*this);
	operator++();
	return temp;
}

/*
Decrement all the values in the array using prefix.
PRECONDITION: Array of at least size 1
POSTCONDITION: Values in the array decremented by one.
*/
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

/*
Decrement all the values in the array using postfix.
PRECONDITION: Array of at least size 1
POSTCONDITION: Values in the array decremented by one.
*/
Matrix Matrix::operator--(int)
{
	Matrix temp(*this);
	operator--();
	return temp;
}

/*
Assignment operator for a matrix.
PRECONDITION:  Matrix has to be initialized.
POSTCONDITION: Matrix on LHS has all the properties on the Matrix on the RHS.
*/
Matrix & Matrix::operator=(Matrix rhs)
{
	swap(*this, rhs);
	return *this;
}

/*
Operator adds array values from RHS Matrix and assigns the new value to the LHS Matrix.
PRECONDTION:   Both matrices are greater than size 1.
POSTCONDITION: Matrix has been assigned added values.
*/
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

/*
The operator multiples the matrix with a double.
PRECONDITION: Matrix has to be greater than size 1.
POSTCONDITION: Returns a matrix where all the values are multiplied by the constant p.
*/
Matrix & Matrix::operator*=(const double p)
{
	for (int i = 0; i < dimension; ++i) {
		for (int j = 0; j < dimension; ++j) {
			double val = contents[i * dimension + j] * p;
			contents[i * dimension + j] = val;
		}
	}
	return *this;
}

/*
Operator subtracts array values from RHS Matrix and assigns the new value to the LHS Matrix.
PRECONDTION:   Both matrices are greater than size 1.
POSTCONDITION: Matrix has been assigned subtracted values.
*/
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

/*
Prints out Matrix object as a matrix.
PRECONDITION:   Matrix of at least size 1.
POSTCONIDTION:  Values of the 1D array outputted as a 2D array.
*/
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

/*
Checks whether matrices are of same size.
If equal return true, otherwise return false.
PRECONDITION:  Matrix of atleast size 1.
POSTCONDITION: Boolean value returned if sizes are equal.
*/
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

/*
Checks whether matrices are not of the same size.
If equal return true, otherwise return false.
PRECONDITION:  Matrix of atleast size 1.
POSTCONDITION: Boolean value returned if sizes are not equal.
*/
bool operator!=(const Matrix& lhs, const Matrix& rhs)
{
	return !operator==(lhs, rhs);
}

/*
Checks whether a matrix is of smaller size than another matrix.
If smaller return true, otherwise return false.
PRECONDITION:  Matrix of atleast size 1.
POSTCONDITION: Boolean value returned if sizes are equal or SMALLER.
*/
bool operator<(const Matrix & lhs, const Matrix & rhs)
{
	return lhs.dimension < rhs.dimension;
}

/*
Checks whether a matrix is of greater size than another matrix.
If greater return true, otherwise return false.
PRECONDITION:  Matrix of atleast size 1.
POSTCONDITION: Boolean value returned if sizes are equal or greater.
*/
bool operator>(const Matrix& lhs, const Matrix& rhs)
{
	return operator<(rhs, lhs);
}

/*
Checks whether a matrix has equal or a smaller size than another matrix.
If equal or smaller return true, otherwise return false.
PRECONDITION:  Matrix of atleast size 1.
POSTCONDITION: Boolean value returned if sizes are equal or SMALLER.
*/
bool operator<=(const Matrix& lhs, const Matrix& rhs)
{
	return !operator> (lhs, rhs);
}


/*
Swap two Matrix objects.
PRECONIDTION:  Both Matrix objects are intialized.
POSTCONDITION: Matrix object properties are swapped with eachother.
*/
void swap(Matrix & lhs, Matrix & rhs)
{
	using std::swap;
	swap(lhs.dimension, rhs.dimension);
	swap(lhs.contents, rhs.contents);
}

/*
Operator adds array values from RHS Matrix to LHS matrix
PRECONDTION:   Both matrices are greater than size 1.
POSTCONDITION: Returns a matrix with added values.
*/
Matrix operator+(Matrix lhs, const Matrix & rhs)
{
	lhs += rhs;
	return lhs;
}

/*
The operator multiples the matrix with a double.
PRECONDITION: Matrix has to be greater than size 1.
POSTCONDITION: Returns a matrix where all the values are multiplied by the constant p.
*/
Matrix operator*(Matrix lhs, const double p) {
	lhs *= p;
	return lhs;
}

/*
Operator subtracts values from RHS to LHS matrix.
PRECONDITION:  Matrix of the same size.
POSTCONDITION: Returns a matrix with subtracted values.
*/
Matrix operator-(Matrix lhs, const Matrix & rhs)
{
	lhs -= rhs;
	return lhs;
}

/*
Checks whether a matrix has equal or a greater size than another matrix.
If equal or greater return true, otherwise return false.
PRECONDITION:  Matrix of atleast size 1.
POSTCONDITION: Boolean value returned if sizes are equal or greater.
*/
bool operator>=(const Matrix& lhs, const Matrix& rhs)
{
	return !operator< (lhs, rhs);
}
