#ifndef _MATRIX_H
#define _MATRIX_H
#include <initializer_list>
#include <iostream>

using namespace std;

class Matrix
{
public:
	Matrix();
	Matrix(std::initializer_list<double> a, std::initializer_list<double> b, std::initializer_list<double> c);
	Matrix(double a[][3]);
	Matrix operator+(const Matrix& rhs);
	Matrix& operator+=(const Matrix& rhs);
	Matrix& operator-=(const Matrix& rhs);
	Matrix operator*(const double& rhs);
	Matrix operator=(const Matrix& rhs);
	Matrix operator*(const Matrix& rhs); // Matrix multiplication 
	Matrix operator-(const Matrix& rhs);
private:
	friend ostream& operator<<(ostream& out, const Matrix& m);
	double a[3][3];
};

ostream& operator<<(ostream& out, const Matrix& m);

#endif // !_MATRIX_H
