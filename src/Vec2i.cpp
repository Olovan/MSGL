#include <MSGL/MSGL_CORE/Vec2i.h>

using msgl::core::Vec2i;

Vec2i::Vec2i() : x(0), y(0)
{
}
Vec2i::Vec2i(int x, int y): x(x), y(y)
{
}
Vec2i::Vec2i(const Vec2i &copy) : x(copy.x), y(copy.y)
{
}

Vec2i Vec2i::operator+(const Vec2i &other)
{
	return Vec2i(x + other.x, y + other.y);
}
Vec2i Vec2i::operator-(const Vec2i &other)
{
	return Vec2i(x - other.x, y - other.y);
}
Vec2i Vec2i::operator*(const Vec2i &other)
{
	return Vec2i(x * other.x, y * other.y);
}
Vec2i Vec2i::operator/(const Vec2i &other)
{
	return Vec2i(x / other.x, y / other.y);
}

bool Vec2i::isPositive()
{
	if(x >= 0 && y >= 0)
		return true;
	return false;
}
