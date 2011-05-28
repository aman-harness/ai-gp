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
int f[maxN][maxN] = {0};
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
		fout << x << ' ' << y << endl;
		m[x][y] = m[y][x] = 1;
	}
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j] = -1;
	f[1][1] = 0;
}

int main()
{
	int i, j, k, l;
	init();
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(k = 1; k < i; k ++)
			{
				if(m[k][i])
					for(l = 1; l < j; l ++)
					{
						if(m[l][j] && (l != k || (l == 1 && k == 1 && i != j) )&& f[k][l] != -1)
							f[i][j] = max(f[k][l] + 2, f[i][j]);
					}
			}
			for(k = 1; k < i; k ++)
			{
				if(m[k][i] && (k != j || (j == 1 && k == 1 && i != j)) && f[k][j] != -1)
					f[i][j] = max(f[k][j] + 1, f[i][j]);
			}
			
			for(l = 1; l < j; l ++)
			{
				if(m[l][j] && (l != i || (l == 1 && i == 1 && i != j)) && f[i][l] != -1)
					f[i][j] = max(f[i][l] + 1, f[i][j]);
			}
			fout << f[i][j] << ' ';
		}
		fout << endl;
	}
	int ma = 0;
	for(i=1;i<=n;i++)
		if(f[i][i] > ma)
			ma = f[i][i];
	fout << ma << endl;
	return 0;
}
