#include <fstream>
using namespace std;
ifstream fin("fence3.in");
ofstream fout("fence3.out");
const int maxN = 100 + 1;

class point 
{
public:
	double x,y;
	friend double crossProduct(point& a, point& b)
	{
		return a.x * b.y - a.y * b.x;
	}
	
};

class line
{
public:
	point p1,p2;
	double distance(point& c)
	{
		double x,y;
		x = (p1.x - c.x);
		y = (p1.y - c.y);
		
		
		
	}
}l[maxN] = {0};


int n;

int main()
{
	int i,j;
	fin >> n;
	for(i=0;i<n;i++)
		fin >> l[i].p1.x >> l[i].p1.y >> l[i].p2.x >> l[i].p2.y;
	
	
	
	return 0;
}
	
