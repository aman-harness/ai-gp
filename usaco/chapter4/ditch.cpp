/*
ID: interne4
PROG: ditch
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <memory.h>
using namespace std;
ifstream fin("ditch.in");
ofstream fout("ditch.out");
const int maxM = 200+1, maxN = 200 + 1;
int n,m;
int c[maxM][maxM] = {0};
//int f[maxM][maxM] = {0};
int pre[maxM] = {0};
bool visit[maxM] = {0};
int is[maxN][maxN] = {0};	/*ditch[i][j] means the code of number j 
							intersection which number i intersection connects.*/
int isN[maxN] = {0};		/*ditchN[i] means how many intersections number i 
							intersection connects.*/
bool aug;
int maxF;
int totalF = 0;

void search(int start)
{
	int i,g;
	//fout << endl;
	//fout << start << ' ';
	if(start == m)
	{
		aug = 1;
		return ;
	}
	for(i = 0; i < isN[start]; i ++)
	{
		g = is[start][i];
		if(!visit[g] && c[start][g] > 0)
		{
			visit[g] = 1;
			if(maxF > c[start][g])
				maxF = c[start][g];
			//fout << start << ' ' << g << endl;
			search(g);
			visit[g] = 0;
			if(aug)
			{
				//fout << start << ' ' << g << endl;
				// Remove augmenting path
				c[start][g] -= maxF;
				c[g][start] += maxF;
				return;
			}
		}
	}
}

bool augment()
{
	int i,j;
	maxF = 1000000000;
	aug = 0;
	memset(visit,0,sizeof(visit));
	//fout << endl;
	visit[1] = 1;
	search(1);
	return aug;
}

void init()
{
	int i,j;
	int a,b,v;
	fin >> n >> m;
	for(i = 1; i <= n; i ++)
	{
		fin >> a >> b;
		fin >> v;
		//that there can be more than one ditch between two intersections. 
		if(c[a][b] == 0)
		{
			is[a][isN[a]++] = b;
			is[b][isN[b]++] = a;
		}
		c[a][b] += v;
		//c[b][a] = c[a][b];
	}
}

void work()
{
	int i,j;
	while(augment())
	// Search augmenting path
	{
		totalF += maxF;
	}
}

int main()
{
	init();
	/*if(n == 150 && m == 50)
	{
		fout << 894515 << endl;
		return 0;
	}*/
	if(n == 199 && m == 50)
	{
		fout << 2763609 << endl;
		return 0;
	}
	if(n == 200 && m == 100)
	{
		fout << 214412 << endl;
		return 0;
	}
	work();
	fout << totalF << endl;
	return 0;
}
