#include <iostream>
#include<cmath>
using namespace std;

class point
{
	static int counter;
	int x, y;
public:
	friend double dist(const point &p);
	point(int x, int y) : x(x), y(y)
	{
		counter++;
	}
	int getX()
	{
		return x;
	}
	~point()
	{
		--counter;
	}
	int getY()
	{
		return y;
	}
	void setX(int t)
	{
		x = t;
	}
	void setY(int t)
	{
		y = t;
	}
	static int getCount()
	{
		return counter;
	}
	void print()
	{
		cout << "X = " << getX() << "\tY = " << getY() << endl;
	}
	static void f(point &p)
	{
		int x, y;
		cout << "Input:";
		cin >> x >> y;
		p.setY(y);
		p.setX(x);

	}
	static double d(int x1, int y1,int x2, int y2)
	{
		double d = ((x1 - x2) *(x1 - x2) +(y1 - y2) *(y1 - y2));
		d =  sqrt(d);
		return d;
	}
	static void p(point q[4])
	{
		for (int i = 0; i < 4; i++)
			cout << q[i].getX() << "\t" << q[i].getY() << endl;
	}
	static void p(point**q)
	{
		for (int i = 0; i < 2; i++)
			cout << q[i]->getX() << "\t" << q[i]->getY() << endl;
	}
};
 inline double dist(const point &p)
{
	 return  sqrt(p.x + p.y);
}
int point::counter=0;

void main()
{
	point S(0, 0);
	{	point A(1, 2), B(3, 4), C(5, 6);
	cout << "counter = " << point::getCount() << endl;
	S.print();
	A.print();
	B.print();
	C.print();
	point::f(A); 
	A.print();
	cout << "LENGTH = " << point::d(A.getX(), A.getY(), B.getX(), B.getY())<<endl;
	point ar[4]{ {5,6},{10,11},{20,2},{-3,0} };
	point::p(ar);
	point *p = new point[4]{ {0,0},{6,1},{5,7},{2,2} };
	cout << "\n";
	point::p(p);
	delete[]p;
	cout << "\n";
	point **q = new point*[2]{ new point{4,7},new point{9 ,3} };
	point::p(q);
	delete []q;
	cout << "\n FR length = " << dist(B)<<endl;
	}
	//cout << "counter = " << point::getCount() << endl;
}