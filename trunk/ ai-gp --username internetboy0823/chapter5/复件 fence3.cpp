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
using namespace std;
ifstream fin("fence3.in");
ofstream fout("fence3.out");

struct point
{
	float x,y;
};

float distan

struct rect
{
	float l,r,t,b;
	point center()
	{
		point a;
		a.x = (l + r)/2;
		a.y = (t + b)/2;
	}

};

const int maxN = 200 + 1;
point l[maxN][2];

int n;


float dict(point c)
{
	int i;
	float d;
	d = 0;
	for(i=1;i<=n;i++)
	{
		
		if(l[i][0].x == l[i][1].x)
		{
			if(c.y <= l[i][1].y && c.y >= l[i][0].y)
			{
				if(l[i][0].x - c.x < 0)
					d += c.x - l[i][0].x;
				else
					d += l[i][0].x - c.x;
			}
			else if(c.y >= l[i][1].y)
			{
				
			}
		}
			
	}
}

const int divideNum = 2;
float s[divideNum + 1][divideNum + 1] = {0};

void dichotomy(rect r)
{
	int i,j;
	float ax,ay,nx,ny;
	ax = (r.r - r.l)/divideNum;
	ay = (r.t - r.b)/divideNum; 
	
	nx = r.l;
	ny = r.b;
	
	for(i=1;i<=divideNum;i++)
	{
		for(j=1;j<=divideNum;j++)
		{
			rect nr;
			nr.l = nx;
			nr.b = ny;
			nr.r = nx + ax;
			nr.t = ny + ay;
			
			ny += ay;
		}
		nx += ax;
	}
		
}


int main()
{
	int i,j;
	fin >> n;
	for(i=1;i<=n;i++)
	{
		fin >> l[i][0].x >> l[i][0].y;
		fin >> l[i][1].x >> l[i][1].y;
	}
	
	float l,r,t,b;
	l = 0;
	b = 0;
	r = 100;
	t = 100;
	while(1)
	{
		
	}
	
    return 0;
}
