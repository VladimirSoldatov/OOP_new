#include <iostream>
using namespace std;
class Point
{
public:
	int x;
	int y;

//public:
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	Point() :Point(0, 0){}
	friend Point operator-(const Point& point1, const Point& point2);
	Point operator* (const Point& point1)
	{
		return Point(this->x * point1.x, this->y * point1.y);
	}
	static const Point devide(const Point& point1, const Point& point2)
	{
		return Point(point1.x / point2.x, point1.y / point2.y);
	}
};
	Point operator-(const Point& point1, const Point& point2)
{
	return Point(point1.x - point2.x, point1.y - point2.y);
}
	ostream& operator<<(ostream& out, const Point& p)
	{
		return out << "X: " << p.x << ", " << "Y: " << p.y << endl;
	}
Point operator+(const Point& point1, const Point& point2) 
{
	return Point(point1.x + point2.x, point1.y + point2.y);
}
int main()
{
	Point p1(10, 20);
	Point p2(2, 2);
	Point p3 = Point::devide(p1, p2);
	cout << p3;
}