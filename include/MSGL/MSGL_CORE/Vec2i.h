#ifndef VEC2I_H_QDBODWSJ
#define VEC2I_H_QDBODWSJ


namespace msgl { namespace core {

class Vec2i
{
public:
	int x;
	int y;

	Vec2i ();
	Vec2i (int x, int y);
	Vec2i (const Vec2i &copy);

	Vec2i operator+(const Vec2i &other);
	Vec2i operator-(const Vec2i &other);
	Vec2i operator*(const Vec2i &other);
	Vec2i operator/(const Vec2i &other);

	bool isPositive();

private:
	/* data */
};

}} //NameSpace


#endif /* end of include guard: VEC2I_H_QDBODWSJ */
