#include <iostream>
using namespace std;

class Point
{
private:
	double x;
	double y;
	void display() const;
	static bool isEqual(const Point& point1, const Point& point2);
	static Point add(const Point& point1, const Point& point2);
	static Point mult(const Point& point, double value);
	static Point mult(const Point& point, double value);
	static Point mult(const Point& point, double value);

};
int main()
{
	int count;
	cin >> count;
	Point* points = new Point[count];
}