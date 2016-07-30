#include <MSGL/MSGL_CORE/Vec2.h>

using msgl::core::Vec2;

Vec2::Vec2() : x(0), y(0)
{
}
Vec2::Vec2(float x, float y): x(x), y(y)
{
}
Vec2::Vec2(const Vec2 &copy) : x(copy.x), y(copy.y)
{
}

Vec2 Vec2::operator+(const Vec2 &other)
{
	return Vec2(x + other.x, y + other.y);
}
Vec2 Vec2::operator-(const Vec2 &other)
{
	return Vec2(x - other.x, y - other.y);
}
Vec2 Vec2::operator*(const Vec2 &other)
{
	return Vec2(x * other.x, y * other.y);
}
Vec2 Vec2::operator/(const Vec2 &other)
{
	return Vec2(x / other.x, y / other.y);
}

bool Vec2::isPositive()
{
	if(x >= 0 && y >= 0)
		return true;
	return false;
}
