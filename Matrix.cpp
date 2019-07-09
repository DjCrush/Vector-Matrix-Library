#include "Matix.h"

Matrix::Matrix() : a{} {}

Matrix::Matrix(std::initializer_list<double> a, std::initializer_list<double> b, std::initializer_list<double> c)
	: a{ { *(a.begin()), *(a.begin() + 1), *(a.begin() + 2) },{ *(b.begin()), *(b.begin() + 1), *(b.begin() + 2) },{ *(c.begin()), *(c.begin() + 1), *(c.begin() + 2) } } {}

Matrix::Matrix(double a[][3]) : a{ { a[0][0], a[0][1], a[0][2] },{ a[1][0],a[1][1],a[1][2] }, a[2][0], a[2][1],a[2][2] } {}

Matrix& Matrix::operator+=(const Matrix& rhs)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			a[i][j] += rhs.a[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& rhs)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			a[i][j] -= rhs.a[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator=(const Matrix& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				a[i][j] = rhs.a[i][j];
			}
		}
	}
	return *this;
}

ostream& operator<<(ostream& out, const Matrix& m)
{
	out << "/ " << setw(5) << m.a[0][0] << setw(5) << m.a[0][1] << setw(5) << m.a[0][2] << setw(5) << " \\" << endl;
	out << "| " << setw(5) << m.a[1][0] << setw(5) << m.a[1][1] << setw(5) << m.a[1][2] << setw(5) << " |" << endl;
	out << "\\ " << setw(5) << m.a[2][0] << setw(5) << m.a[2][1] << setw(5) << m.a[2][2] << setw(5) << " /" << endl;
	return out;
}

Matrix operator-(const Matrix& lhs, const Matrix& rhs)
{
	return{ { lhs.a[0][0] - rhs.a[0][0], lhs.a[0][1] - rhs.a[0][1], lhs.a[0][2] - rhs.a[0][2] },
	{ lhs.a[1][0] - rhs.a[1][0], lhs.a[1][1] - rhs.a[1][1], lhs.a[1][2] - rhs.a[1][2] },
	{ lhs.a[2][0] - rhs.a[2][0], lhs.a[2][1] - rhs.a[2][1], lhs.a[2][2] - rhs.a[2][2] } };
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs)
{
	return{ { lhs.a[0][0] + rhs.a[0][0], lhs.a[0][1] + rhs.a[0][1], lhs.a[0][2] + rhs.a[0][2] },
	{ lhs.a[1][0] + rhs.a[1][0], lhs.a[1][1] + rhs.a[1][1], lhs.a[1][2] + rhs.a[1][2] },
	{ lhs.a[2][0] + rhs.a[2][0], lhs.a[2][1] + rhs.a[2][1], lhs.a[2][2] + rhs.a[2][2] } };
}

Matrix operator*(const Matrix& lhs, const double& rhs)
{
	return{ { lhs.a[0][0] * rhs, lhs.a[0][1] * rhs, lhs.a[0][2] * rhs },
	{ lhs.a[1][0] * rhs, lhs.a[1][1] * rhs, lhs.a[1][2] * rhs },
	{ lhs.a[2][0] * rhs, lhs.a[2][1] * rhs, lhs.a[2][2] * rhs } };
}

Matrix operator*(const Matrix& lhs, const Matrix& rhs) // Matrix multiplication 
{
	return{ { lhs.a[0][0] * rhs.a[0][0] + lhs.a[0][1] * rhs.a[1][0] + lhs.a[0][2] * rhs.a[2][0], 
		lhs.a[0][0] * rhs.a[0][1] + lhs.a[0][1] * rhs.a[1][1] + lhs.a[0][2] * rhs.a[2][1], 
		lhs.a[0][0] * rhs.a[0][2] + lhs.a[0][1] * rhs.a[1][2] + lhs.a[0][2] * rhs.a[2][2] },
	{ lhs.a[1][0] * rhs.a[0][0] + lhs.a[1][1] * rhs.a[1][0] + lhs.a[1][2] * rhs.a[2][0], 
		lhs.a[1][0] * rhs.a[0][1] + lhs.a[1][1] * rhs.a[1][1] + lhs.a[1][2] * rhs.a[2][1], 
		lhs.a[1][0] * rhs.a[0][2] + lhs.a[1][1] * rhs.a[1][2] + lhs.a[1][2] * rhs.a[2][2] },
	{ lhs.a[2][0] * rhs.a[0][0] + lhs.a[2][1] * rhs.a[1][0] + lhs.a[2][2] * rhs.a[2][0], 
		lhs.a[2][0] * rhs.a[0][1] + lhs.a[2][1] * rhs.a[1][1] + lhs.a[2][2] * rhs.a[2][1], 
		lhs.a[2][0] * rhs.a[0][2] + lhs.a[2][1] * rhs.a[1][2] + lhs.a[2][2] * rhs.a[2][2] } };
}
