#include <fstream>
using namespace std;
ifstream fin("fence3.in");
ofstream fout("fence3.out");
const int maxN = 100 + 1;

class vector
{
public:
	double x,y;
	friend double crossProduct(vector& a, vector& b)
	{
		return a.x * b.y - a.y * b.x;
	}
	
	vector& operator - (vector& p)
	{
		vector pp;
		pp.x = x - p.x;
		pp.y = y - p.y;
		return pp;
	}
	
	vector& vertical()
	{
		vector p;
		p.x = y;
		p.y = x;
		return p;
	}
	
};

class line
{
public:
	vector p1,p2;
	double distance(point& c)
	{
		vector n1;
		n1 = p1 - p2;
		
		
		
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
	
