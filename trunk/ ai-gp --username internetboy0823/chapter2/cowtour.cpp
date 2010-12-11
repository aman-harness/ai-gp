/*
ID: interne4
PROG: cowtour
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;
ifstream fin("cowtour.in");
ofstream fout("cowtour.out");

typedef struct Point
{
	double x;
	double y;
};

double distanceCppSB(Point& a,Point& b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

const double maxD = 100000000.0;
int n;
Point vextex[200]={0};				//pasture's position
double adj[200][200]={0};			//a symmetric "adjacency" matrix 
double dist[200]={0};				//max distance from the pasture in a field
double ans;

void init();

void work()
{
	int i,j,k;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if (i!=j && adj[i][j] > adj[i][k] + adj[k][j])
					adj[i][j] = adj[i][k] + adj[k][j];
	
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if (adj[i][j] != maxD && adj[i][j] > dist[i])
				dist[i] = adj[i][j];
		
	double x;
	ans = maxD;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i != j && adj[i][j] == maxD)
			{
				x = dist[i] + dist[j] + distanceCppSB(vextex[i],vextex[j]);
				if(x < ans)
				{
					d = i;
					dd = j;
					ans = x;
				}
			}
	for(i=1;i<=n;i++)
		if(dist[i] > ans)
			ans = dist[i];
}


int main()
{
	init();
	work();
	fout << setprecision(6) << setiosflags(ios::fixed  | ios::showpoint) << ans << endl;
	return 0;
}


void init()
{
	int i,j;
	char ch;
	
	fin >> n;
	//input
	for(i=1;i<=n;i++)
		fin >> vextex[i].x >> vextex[i].y;
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		fin >> ch;
		adj[i][j] = maxD;
		if(ch == '1')
			adj[i][j] = distanceCppSB(vextex[i],vextex[j]);
		if(i == j)
			adj[i][j] = 0;
	}
	//init
}

/* distanceCppSB 函数原来叫 distance 但编译不过，害得我不轻。
原来是与STL库中的 distance 重名了
*/

