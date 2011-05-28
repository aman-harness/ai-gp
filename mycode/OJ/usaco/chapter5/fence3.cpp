/*
ID: interne4
PROG: fence3
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <memory.h>
#include <iomanip>
#include <cmath>
using namespace std;
ifstream fin("fence3.in");
ofstream fout("fence3.out");

struct point
{
	double x,y;
};

double dict(point a,point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

struct rect
{
	double l,r,t,b;
	point center()
	{
		point a;
		a.x = (l + r)/2;
		a.y = (t + b)/2;
		return a;
	}

};

const int maxN = 200 + 1;
point l[maxN][2];

int n;


double dict(point c)
{
	int i;
	double d;
	d = 0.0;
	for(i=1;i<=n;i++)
	{
		
		if(l[i][0].x == l[i][1].x)
		{
			if(c.y <= l[i][1].y && c.y >= l[i][0].y)
			{
				d += abs(c.x - l[i][0].x);
			}
			else if(c.y > l[i][1].y)
			{
				d += dict(c, l[i][1]);
			}
			else
			{
				d += dict(c, l[i][0]);
			}
		}
		else
		{
			if(c.x <= l[i][1].x && c.x >= l[i][0].x)
			{
				d += abs(c.y - l[i][0].y);
			}
			else if(c.x > l[i][1].x)
			{
				d += dict(c, l[i][1]);
			}
			else
			{
				d += dict(c, l[i][0]);
			}
		}
	}
	return d;
}

const int divideNum = 4;
double s[divideNum + 1][divideNum + 1] = {0},md;

rect dichotomy(rect r)
{
	int i,j;
	double ax,ay,nx,ny;
	double d;
	rect dr;
	
	ax = (r.r - r.l)/divideNum;
	ay = (r.t - r.b)/divideNum; 
	
	nx = r.l;
	ny = r.b;
	
	md = 1000000.0;
	for(i=0;i<divideNum;i++)
	{
		ny = r.b;
		for(j=0;j<divideNum;j++)
		{
			rect nr;
			nr.l = nx;
			nr.b = ny;
			nr.r = nx + ax;
			nr.t = ny + ay;
			d = dict(nr.center());
			if(d < md)
			{
				md = d;
				dr.l = max(nx - ax, 0.0);
				dr.b = max(ny - ay, 0.0);
				dr.r = min(nx + ax * 2, 100.0);
				dr.t = min(ny + ay * 2, 100.0);
			}
			ny += ay;
		}
		nx += ax;
	}
	return dr;
}


int main()
{
	int i,j;
	fin >> n;
	for(i=1;i<=n;i++)
	{
		fin >> l[i][0].x >> l[i][0].y;
		fin >> l[i][1].x >> l[i][1].y;
		if(l[i][0].x > l[i][1].x)
			swap(l[i][0].x, l[i][1].x);
		if(l[i][0].y > l[i][1].y)
			swap(l[i][0].y, l[i][1].y);
	}
	
	double d;
	rect r;
	r.l = 0.0;
	r.b = 0.0;
	r.r = 100.0;
	r.t = 100.0;
	fout << fixed << setprecision(1);
	while(1)
	{
		r = dichotomy(r);
		d = md;
		//fout << r.l << ' ' << r.b << ' ' << r.r << ' ' << r.t << ' ' << d << endl;
		if(r.r - r.l < 0.01)
			break;
	}
	fout << r.l << ' ' << r.b << ' ' << d << endl;
    return 0;
}
