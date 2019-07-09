#ifndef  _VECTOR3_H_
#define  _VECTOR3_H_
#include <iostream>
using namespace std;

class Vector3
{
	double x, y, z;
public:
	Vector3(double x, double y, double z);
	Vector3& operator+=(const Vector3& rhs);
	Vector3& operator-=(const Vector3& rhs);
	Vector3 normal(); // vector normalization
	double length(); // the length of a vector
	friend Vector3 operator*(const Vector3& lhs, const Vector3& rhs); // Cross Product
	friend Vector3 operator+(const Vector3& lhs, const Vector3& rhs); // Vector addition
	friend Vector3 operator-(const Vector3& lhs, const Vector3& rhs); // Vector subtraction
	friend Vector3 operator*(const Vector3& lhs, const double& rhs);  // Scalar-vector multiplication
	friend Vector3 operator*(const Vector3& lhs, const Vector3& rhs); // Cross Product
	friend ostream& operator<<(ostream& out, const Vector3& v);
};

ostream& operator<<(ostream& out, const Vector3& v);
Vector3 operator*(const Vector3& lhs, const Vector3& rhs); // Cross Product
Vector3 operator+(const Vector3& lhs, const Vector3& rhs); // Vector addition
Vector3 operator-(const Vector3& lhs, const Vector3& rhs); // Vector subtraction
Vector3 operator*(const Vector3& lhs, const double& rhs);  // Scalar-vector multiplication
Vector3 operator*(const Vector3& lhs, const Vector3& rhs); // Cross Product

#endif
