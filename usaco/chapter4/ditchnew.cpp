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
int src[maxM] = {0};
int cap[maxM] = {0};
bool visit[maxM] = {0};
int maxF;
int totalF = 0;

bool augment()
{
	int lv,mloc,t;
	memset(visit,0,sizeof(visit));
	memset(cap, 0, sizeof(cap));

  	cap[1] = 2000000000;
  	while (1)
  	{
		/* find maximum unvisited node */
		maxF = 0;
		mloc = -1;
		for (lv = 1; lv <= m; lv++)
			if (!visit[lv] && cap[lv] > maxF)
			{
				maxF = cap[lv];
				mloc = lv;
			}
		if (mloc == -1) return 0;
		if (mloc == m) break; /* max is the goal, we're done */

		visit[mloc] = 1; /* mark as visited */
	
			/* update neighbors, if going through this node improves the
			capacity */
		for (lv = 1; lv <= m; lv++)
			if (c[mloc][lv] > cap[lv] && maxF > cap[lv])
				{
					cap[lv] = c[mloc][lv];
					if (cap[lv] > maxF) cap[lv] = maxF;
					src[lv] = mloc;
				}
	}
	maxF = cap[m];

	/* augment path, starting at end */
	for (lv = m; lv > 1; lv = src[lv])
	{
		t = src[lv];
		c[t][lv] -= maxF;
		c[lv][t] += maxF;
	}

	return 1;
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
	work();
	fout << totalF << endl;
	return 0;
}
