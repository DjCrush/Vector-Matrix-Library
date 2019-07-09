#include "Vector3.h"

Vector3::Vector3(double x = 0, double y = 0, double z = 0) : x{ x }, y{ y }, z{ z } {}

Vector3 Vector3::operator+(const Vector3& rhs) // Vector addition
{
	return{ x + rhs.x, y + rhs.y, z + rhs.z };
}
Vector3& Vector3::operator+=(const Vector3& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}
Vector3 Vector3::operator-(const Vector3& rhs) // Vector subtraction
{
	return{ x - rhs.x, y - rhs.y, z - rhs.z };
}
Vector3& Vector3::operator-=(const Vector3& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}
Vector3 Vector3::operator*(const double& rhs)  // Scalar-vector multiplication
{
	return{ x * rhs, y * rhs, z * rhs };
}
Vector3 Vector3::operator*(const Vector3& rhs) // Cross Product
{
  return { y * rhs.z - z * rhs.y, z *rhs.x - x * rhs.z, x * rhs.y - y * rhs.x };
}
Vector3 Vector3::normal() // vector normalization
{
	double len = length();
	return{ x / len, y / len, z / len };
}
double Vector3::length() // the length of a vector
{
	return sqrt(x * x + y * y + z * z);
}
ostream& operator<<(ostream& out, const Vector3& v)
{
	out << "( " << v.x << ", " << v.y << ", " << v.z << " )";
	return out;
}
Vector3 operator*(const Vector3& lhs, const Vector3& rhs) // Cross Product
{
  return{ lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x };
}
