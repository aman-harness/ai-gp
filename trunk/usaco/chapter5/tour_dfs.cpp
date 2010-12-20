/*
ID: interne4
PROG: tour
LANG: C++
DATA: 2010.12.17
ALGO: Dynamic Programming
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("tour.in");
ofstream fout("tour.out");

const int maxN = 100 + 1;
int n, v;
int m[maxN][maxN] = {0};
int adj[maxN][maxN] = {0},adjn[maxN] = {0};
int f[maxN][maxN] = {0};
int ans[maxN] = {0};
string c[maxN];


void init()
{
	fin >> n >> v;
	for(int i = 1; i <= n; i ++)
	{
		fin >> c[i];
	}
	string a, b;
	int x, y;
	for(int i = 1; i <= v; i ++)
	{
		fin >> a >> b;
		for(int j = 1; j <= n; j++)
		{
			if(a == c[j])
			{
				x = j;
				break;
			}
		}
		for(int j = 1; j <= n; j++)
		{
			if(b == c[j])
			{
				y = j;
				break;
			}
		}
		m[x][y] = m[y][x] = 1;
		adj[x][adjn[x] ++] = y;
		adj[y][adjn[y] ++] = x;
	}
	
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j++)
			f[i][j] = -1;
}

void expand(int x,int y,int l,int s)
{
	int i,j;
	if(f[x][y] < s)
		f[x][y] = s;
	else
		return ;
	//fout << x << ' ' << y << ' ' << s << endl;
	for(i = 0; i < adjn[x]; i ++)
	{
		if(adj[x][i] < x)
			continue;
		if(adj[x][i] < y)
			expand(adj[x][i], y, l, s + 1);
		else if(adj[x][i] > y)
			expand(y, adj[x][i], x, s + 1);
		else if(x != l)
			ans[y] = max(ans[y], s + 1);
		
	}
}

int main()
{
	int i, j, k, l;
	init();
	ans[n] = 1;
	expand(1,1,1,0);
	fout << ans[n] << endl;
	return 0;
}
