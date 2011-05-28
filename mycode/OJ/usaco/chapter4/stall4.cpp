/*
ID: interne4
PROG: stall4
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("stall4.in");
ofstream fout("stall4.out");

const int maxN = 200 + 1;
int n,m;
int s;
int byre[maxN*2][maxN] = {0};
int adj[maxN*2][maxN*2] = {0};
int vis[maxN*2] = {0};
int tong[maxN*2] = {0};
bool augment(int x)
{
	int i;
	/*
	if(x <= n)
		fout << x << endl;
	else
		fout << x - n << endl;*/
	if(!tong[x])
	{
		tong[x] = 1;
		return true;
	}
	for(i = 1; i <= byre[x][0]; i++)
	{
		int g = byre[x][i];
		if(!vis[g] && adj[x][g] > 0)
		{
			vis[g] = 1;
			//fout << adj[x][g] << '{';
			if(augment(g))
			{
				adj[x][g] --;
				adj[g][x] ++;
				return true;
			}
		}
	}
	//fout << '}';
	return false;
}

int main()
{
	int a,i,j;
	fin >> n >> m;
	for(i=1;i<=n;i++)
	{
		fin >> s;
		for(j=0;j<s;j++)
		{
			fin >> a;
			a += n;
			byre[i][++byre[i][0]] = a;
			byre[a][++byre[a][0]] = i;
			adj[i][a] = 1;// = adj[a][i] = 1;
		}
		tong[i] = 1;
	}
	s = 0;
	for(i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		//fout << i << "  start" << endl;
		if(augment(i))
		{
			s ++;
		}
	}
	fout << s << endl;
    return 0;
}
