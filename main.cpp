#include "pch.h"
#include <iostream>
#include <initializer_list>
using namespace std;

class Vector3
{
public:
	Vector3(double x = 0, double y = 0, double z = 0) : x{ x }, y{ y }, z{ z }
	{}
	Vector3 operator+(const Vector3& rhs) // Vector addition
	{
		return { x + rhs.x, y + rhs.y, z + rhs.z };
	}
	Vector3& operator+=(const Vector3& rhs)
	{
		x += rhs.x; 
		y += rhs.y; 
		z += rhs.z;
		return *this;
	}
	Vector3 operator-(const Vector3& rhs) // Vector subtraction
	{
		return { x - rhs.x, y - rhs.y, z - rhs.z };
	}
	Vector3& operator-=(const Vector3& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		return *this;
	}
	Vector3 operator*(const double& rhs)  // Scalar-vector multiplication
	{
		return { x * rhs, y * rhs, z * rhs };
	}
/*	Vector3 operator*(const Vector3& rhs) // Cross Product
	{
		return { y * rhs.z - z * rhs.y, z *rhs.x - x * rhs.z, x * rhs.y - y * rhs.x };
	}
	*/
	friend Vector3 operator*(const Vector3& lhs, const Vector3& rhs);
	Vector3 normal() // vector normalization
	{
		double len = length();
		return { x / len, y / len, z / len };
	}
	double length() // the length of a vector
	{
		return sqrt(x * x + y * y + z * z);
	}
	friend ostream& operator<<(ostream& out, const Vector3& v);
private:
	double x, y, z;
};

Vector3 operator*(const Vector3& lhs, const Vector3& rhs) // Cross Product
{
	
	return { lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x };
}

ostream& operator<<(ostream& out, const Vector3& v)
{
	out << "( " << v.x << ", " << v.y << ", " << v.z << " )";
	return out;
}

class Matrix
{
public:
	Matrix() : a{}
	{
		cout << "000000000000000" << endl;
	}
	Matrix(std::initializer_list<double> a, std::initializer_list<double> b, std::initializer_list<double> c)
		: a{ {*(a.begin()), *(a.begin() + 1), *(a.begin() + 2) },
			{*(b.begin()), *(b.begin() + 1), *(b.begin() + 2) },
			{*(c.begin()), *(c.begin() + 1), *(c.begin() + 2) } }

	{
		cout << "initial" << endl;
	}
	Matrix(double a[][3]) : a{{a[0][0], a[0][1], a[0][2]}, {a[1][0],a[1][1],a[1][2]}, a[2][0], a[2][1],a[2][2]}
	{}
	Matrix operator+(const Matrix& rhs)
	{
		cout << "+++++++++++++++++++++++++++++" << endl;
		return { {a[0][0] + rhs.a[0][0], a[0][1] + rhs.a[0][1], a[0][2] + rhs.a[0][2]},
				 {a[1][0] + rhs.a[1][0], a[1][1] + rhs.a[1][1], a[1][2] + rhs.a[1][2]},
				 {a[2][0] + rhs.a[2][0], a[2][1] + rhs.a[2][1], a[2][2] + rhs.a[2][2]} };
	}

	Matrix& operator+=(const Matrix& rhs)
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

	Matrix& operator-=(const Matrix& rhs)
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

	Matrix operator*(const double& rhs)
	{
		return { {a[0][0] * rhs, a[0][1] * rhs, a[0][2] * rhs},
				 {a[1][0] * rhs, a[1][1] * rhs, a[1][2] * rhs},
				 {a[2][0] * rhs, a[2][1] * rhs, a[2][2] * rhs} };
	}
	Matrix operator=(const Matrix& rhs)
	{
		if (this == &rhs) 
		{
			return *this;
		}
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				a[i][j] = rhs.a[i][j];
			}
		}
		return *this;
	}
	Matrix operator*(const Matrix& rhs)
	{
		return { {a[0][0] * rhs.a[0][0] + a[0][1] * rhs.a[1][0] + a[0][2] * rhs.a[2][0],
				  a[0][0] * rhs.a[0][1] + a[0][1] * rhs.a[1][1] + a[0][2] * rhs.a[2][1],
				  a[0][0] * rhs.a[0][2] + a[0][1] * rhs.a[1][2] + a[0][2] * rhs.a[2][2]},
				 {a[1][0] * rhs.a[0][0] + a[1][1] * rhs.a[1][0] + a[1][2] * rhs.a[2][0],
				  a[1][0] * rhs.a[0][1] + a[1][1] * rhs.a[1][1] + a[1][2] * rhs.a[2][1],
				  a[1][0] * rhs.a[0][2] + a[1][1] * rhs.a[1][2] + a[1][2] * rhs.a[2][2]},
				 {a[2][0] * rhs.a[0][0] + a[2][1] * rhs.a[1][0] + a[2][2] * rhs.a[2][0],
				  a[2][0] * rhs.a[0][1] + a[2][1] * rhs.a[1][1] + a[2][2] * rhs.a[2][1],
				  a[2][0] * rhs.a[0][2] + a[2][1] * rhs.a[1][2] + a[2][2] * rhs.a[2][2]} };
	}
	Matrix operator-(const Matrix& rhs)
	{
		return { {a[0][0] - rhs.a[0][0], a[0][1] - rhs.a[0][1], a[0][2] - rhs.a[0][2]},
				 {a[1][0] - rhs.a[1][0], a[1][1] - rhs.a[1][1], a[1][2] - rhs.a[1][2]},
				 {a[2][0] - rhs.a[2][0], a[2][1] - rhs.a[2][1], a[2][2] - rhs.a[2][2]} };
	}
	friend ostream& operator<<(ostream& out, const Matrix& m);
private:
	double a[3][3];
};

ostream& operator<<(ostream& out, const Matrix& m)
{
	out <<  "/ " << m.a[0][0] << ' ' << m.a[0][1] << ' ' << m.a[0][2] << " \\" << endl;
	out <<  "| " << m.a[1][0] << ' ' << m.a[1][1] << ' ' << m.a[1][2] << " |" << endl;
	out <<  "\\ " << m.a[2][0] << ' ' << m.a[2][1] << ' ' << m.a[2][2] << " /" << endl;
	return out;
}


int main()
{
	Matrix a={ {100,200,300},{400,500,600},{700,800,900} };
	Matrix b;
	b = b + a;
	b = b * 5;
	cout << b;
	return 0;
}
