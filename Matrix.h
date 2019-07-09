#ifndef _MATRIX_H
#define _MATRIX_H
#include <initializer_list>
#include <iostream>
#include <iomanip>

using namespace std;

class Matrix
{
	double a[3][3];
public:
	Matrix(); // default constructor
	Matrix(std::initializer_list<double> a, std::initializer_list<double> b, std::initializer_list<double> c);
	Matrix(double a[][3]);
	Matrix& operator+=(const Matrix& rhs);
	Matrix& operator-=(const Matrix& rhs);
	Matrix operator=(const Matrix& rhs);
	friend ostream& operator<<(ostream& out, const Matrix& m);
	friend Matrix operator+(const Matrix& lhs, const Matrix& rhs);
	friend Matrix operator-(const Matrix& lhs, const Matrix& rhs);
	friend Matrix operator*(const Matrix& lhs, const Matrix& rhs);
	friend Matrix operator*(const Matrix& lhs, const double& rhs);
};

ostream& operator<<(ostream& out, const Matrix& m);
Matrix operator+(const Matrix& lhs, const Matrix& rhs);
Matrix operator-(const Matrix& lhs, const Matrix& rhs);
Matrix operator*(const Matrix& lhs, const Matrix& rhs);
Matrix operator*(const Matrix& lhs, const double& rhs);

#endif // !_MATRIX_H
