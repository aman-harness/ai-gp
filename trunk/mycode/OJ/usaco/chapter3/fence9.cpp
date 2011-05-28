/*
ID: interne4
PROG: fence9
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("fence9.in");
ofstream fout("fence9.out");
/*
web:	http://www.n8lm.cn
This template code is writed by Alchemist.
*/
const double EP = 0.00000001;
const int LINE_SEG = 0xff;
const int LINE_SEG_INF = 0xff + 1;
template <class T = double>
class point
{
public:
	T x;
	T y;
	point()	{};
	point(T a,T b)
	{
		x = a;
		y = b;
	}
	
	point(const point<T>& a)
	{
		x = a.x;
		y = a.y;
	}
	
	point<T>& operator = (const point<T>& p)
	{
		x = p.x;
		y = p.y;
	}
	
	friend point<T> operator - (point<T>& p1, point<T>& p2)
    {
	    point<T> p(p1.x - p2.x, p1.y - p2.y);
	    return p;
    }
	
	friend T crossProduct(point<T> p1, point<T> p2)
	{
		return p1.x * p2.y - p1.y * p2.x;
	}
	
	friend T direction(point<T> p1, point<T> p2, point<T> pO)
	{
		return crossProduct(p1 - pO, p2 - pO);
	}
	
	friend bool operator == (point<T>& p1, point<T>& p2)
	{
		return (abs(p1.x - p2.x) < EP  && abs(p1.y - p2.y) < EP);
	}
	
	friend T dist(point<T> p1, point<T> p2)
	{
		return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
	}
	
	friend istream& operator >> (istream& input, point<T>& p)
	{
		input >> p.x;
		input >> p.y;
		return input;
	}
	
	friend ostream& operator << (ostream& output, point<T>& p)
	{
		output << p.x << ' ' << p.y;
		return output;
	}
};

template <class T = double>
class line
{
public:
	point<T> A;
	point<T> B;
	
	line(){};
	line(const point<T>& a,const point<T>& b):A(a),B(b) {};
	line(T a, T b, T c, T d):A(a,b),B(c,d) {};
	
	void setPoints(point<T> a, point<T> b)
	{
		A = a;
		B = b;
	}
	
	T length()
	{
		return dist(A,B);
	}
	
	friend bool intersect(line<T>& P, line<T>& Q ,int intersect_way)
	{
		if(intersect_way == LINE_SEG)
		{
			if(
			(max(Q.A.x,Q.B.x)>=min(P.A.x,P.B.x))&&
			(max(P.A.x,P.B.x)>=min(Q.A.x,Q.B.x))&&
			(max(Q.A.y,Q.B.y)>=min(P.A.y,P.B.y))&&
			(max(P.A.y,P.B.y)>=min(Q.A.y,Q.B.y))&&
			(crossProduct(P.A - Q.A , Q.B - Q.A ) * crossProduct( Q.B - Q.A , P.B - Q.A ) >= 0) &&
			(crossProduct(Q.A - P.A , P.B - P.A ) * crossProduct( P.B - P.A , Q.B - P.A ) >= 0) &&
			!(P.A == Q.A) &&
			!(P.A == Q.B) &&
			!(P.B == Q.A) &&
			!(P.B == Q.B) 
			)
				return true;
			else
				return false;
		}
		else if(intersect_way == LINE_SEG_INF)
		{
			if(
			(crossProduct(P.A - Q.A , Q.B - Q.A ) * crossProduct( Q.B - Q.A , P.B - Q.A ) > 0) &&
			!(P.A == Q.A) &&
			!(P.A == Q.B) &&
			!(P.B == Q.A) &&
			!(P.B == Q.B) 
			)
				return true;
			else
				return false;
		}
		return false;
	}
	
	friend point<T> intersection(line<T>& P, line<T>& Q)
	{
		point<T> crossPoint;
		T tempLeft,tempRight;
		
		//求x坐标
		tempLeft = (Q.B.x - Q.A.x) * (P.A.y - P.B.y) - (P.B.x - P.A.x) * (Q.A.y - Q.B.y);
		tempRight = (P.A.y - Q.A.y) * (P.B.x - P.A.x) * (Q.B.x - Q.A.x) + Q.A.x * (Q.B.y - Q.A.y) * (P.B.x - P.A.x) - P.A.x * (P.B.y - P.A.y) * (Q.B.x - Q.A.x);
    	crossPoint.x = tempRight / tempLeft;
		//求y坐标
		tempLeft = (P.A.x - P.B.x) * (Q.B.y - Q.A.y) - (P.B.y - P.A.y) * (Q.A.x - Q.B.x);
		tempRight = P.B.y * (P.A.x - P.B.x) * (Q.B.y - Q.A.y) + (Q.B.x- P.B.x) * (Q.B.y - Q.A.y) * (P.A.y - P.B.y) - Q.B.y * (Q.A.x - Q.B.x) * (P.B.y - P.A.y);
		crossPoint.y = tempRight / tempLeft;
		
		return crossPoint;
	}
		
	friend ostream& operator << (ostream& output, line<T>& l)
	{
		output << l.A << ' ' << l.B; 
		return output;
	}
	
};

int n,m,p;
int main()
{
	point<double> vextex, axis, origin(0,0);
	line<double> triA,triB;
	int p;
	fin >> vextex >> p;
	axis.x = p;
	axis.y = 0;
	triA.setPoints(origin,vextex);
	triB.setPoints(axis,vextex);
	
	point<double> cp1,cp2;
	int l, s;
	s = 0;
	l = int(vextex.y - 1);
	while(l != 0)
	{
		line<double> lx(0,l,10,l);
		cp1 = intersection(triA, lx);
		cp2 = intersection(triB, lx);
		if(floor(cp2.x) == cp2.x)
			cp2.x -= 1;
		if(ceil(cp1.x) == cp1.x)
			cp1.x += 1;
		if( floor(cp2.x) >= ceil(cp1.x) )
			s += int(floor(cp2.x) - ceil(cp1.x) + 1);
		l --;
	}
	fout << s << endl;
    return 0;
}

/*
At the first time of the test i forgot to write the sign '=' after '>'.
It's missed the point of unique feature.
*/
