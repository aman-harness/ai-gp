
/*
ID: interne4
PROG: fc
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <list>
using namespace std;
ifstream fin("fc.in");
ofstream fout("fc.out");
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

const int maxN = 10000 + 1;
point<double> p[maxN];
point<double> center;
list< point<double> > l;
int n;

int comp(const void *p,const void *q)
{
	if(direction(*(point<double>*)p, *(point<double>*)q, center) > 0)
		return 1;
	else
		return -1;
}

bool specialpoint()
{
	if(n == 0 || n == 1)
	{
		fout << "0.00" << endl;
		return true;
	}
	else if(n == 2)
	{
		fout  << fixed << setprecision(2) << dist(p[0],p[1])*2  << endl;
		return true;
	}
	return false;
}

int main()
{
	int i,j;
	center.x = center.y = 0;
	fin >> n;
	for(i=0;i<n;i++)
	{
		fin >> p[i].x >> p[i].y;
		center.x += p[i].x;
		center.y += p[i].y;
	}
	center.x /= n;
	center.y /= n;
	qsort(p,n,sizeof(p[0]),comp);
	
	if(specialpoint())
		return 0;
	
	for(i=0;i<n;i++)
		l.push_back(p[i]);
		
	point<double> p2;
	
	list< point<double> >::iterator it,fir,sec;
	it = l.begin();
	it ++;it ++;
	while(it != l.end())
	{
		sec = it;
		sec --;
		fir = sec;
		fir --;
		if(direction(*sec,*it,*fir) > 0)
		{
			l.erase(sec);
		}
		it ++;
	}
	
	while(1)
	{
		sec = l.begin();
		fir = l.end();
		fir --;
		it = sec;
		it ++;
		
		if(direction(*sec,*it,*fir) > 0)
		{
			l.erase(sec);
		}
		else
			break;
	}
	
	double ans = 0;
	for((it = l.begin())++; it != l.end(); it ++)
	{
		fir = it;
		fir --;
		ans += dist(*it,*fir);
	}
	fir ++;
	it = l.begin();
	ans += dist(*it,*fir);
	fout << fixed << setprecision(2) << ans << endl;
    return 0;
}
