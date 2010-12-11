/*
ID: interne4
PROG: agrinet
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("agrinet.in");
ofstream fout("agrinet.out");

const int maxD = 100000000,maxRows = 100;
int n,s;
int adj[maxRows + 1][maxRows + 1]={0};	 		//a symmetric "adjacency" matrix 
int q[maxRows + 1]={0},closed=0;
int dist[maxRows + 1]={0};
//int source[maxRows + 1]={0};
bool intree[maxRows + 1]={0};
bool inq[maxRows + 1]={0};
int ans;

void prim()
{
	int i,j;
	int now;
	now = 1;
	s = 1;
	intree[now] = 1;
	ans = 0;
	while(s < n)
	{
		for(i=1;i<=n;i++)
			if(now != i && !intree[i] && adj[now][i] != maxD)
			{
				if(!inq[i])
				{
					q[closed++] = i;
					dist[i] = adj[now][i];
					inq[i] = 1;
				}
				else if(dist[i] > adj[now][i])
					dist[i] = adj[now][i];
			}
		int minQ = maxD;
		for(i=0;i<closed;i++)
		{
			if(intree[q[i]])continue;
			if(dist[q[i]] < minQ)
			{
				minQ = dist[q[i]];
				now = q[i];
			}
			//fout << q[i] << ' ' << dist[q[i]] << endl;
		}
		//fout << now <<endl;
		intree[now] = 1;
		ans += dist[now];
		s++;
	}
}

void work()
{
	prim();
}

void init()
{
	int i,j;	
	//input
	fin >> n;
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		fin >> adj[i][j];
	}
	//init
}

int main()
{
	init();
	work();
	fout << ans << endl;
    return 0;
}
