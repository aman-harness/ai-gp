/*
ID: interne4
PROG: butter
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;
ifstream fin("butter.in");
ofstream fout("butter.out");

const int MaxV = 800 + 1, MaxE = 1450 + 1;
int N,P,C;
unsigned int cow[50000],d[MaxV][MaxV]={0},visited[MaxV]={0},adj[MaxV][MaxV]={0},edge[MaxV]={0},source[MaxV]={0};
unsigned int ans = 0xffffffff;

struct node
{
	int id;
	friend bool operator < (node n1, node n2)
    {
        return source[n1.id] < source[n2.id];
    }
	    
	friend bool operator > (node n1, node n2)
    {
        return source[n1.id] > source[n2.id];
    }
    
};

void init()
{
	int i,a,b,c;
	fin >> N >> P >> C;
	for(i = 1; i <= N; i++)
		fin >> cow[i];
	for(i = 1; i <= C; i++)
	{
		fin >> a >> b >> c;
		d[a][b] = c;
		d[b][a] = c;
		adj[a][edge[a]++] = b;
		adj[b][edge[b]++] = a;
	}
}


void dijkstra(int parent)
{
	priority_queue<node,vector<node>,greater<node> > q;
	memset(source,0xff,sizeof(source));
	memset(visited,0,sizeof(visited));
	node s;
	visited[parent] = 1;
	source[parent] = 0;
	s.id = parent;
	q.push(s);
	do
	{
		int id = q.top().id;
		int i,target;
		q.pop();
		
		visited[id] = 1;
		for(i = 0; i < edge[id]; i ++)
		{
			target = adj[id][i];
			if(!visited[target] && d[id][target] + source[id] < source[target])
			{
				source[target] = d[id][target] + source[id];
				node x;
				x.id = target;
				q.push(x);
			}
		}
		
	}while(!q.empty());
}

int sum()
{
	int s = 0;
	for(int i=1;i<=N;i++)
	{
		if(source[cow[i]] != 0xffffffff)
		{
			s += source[cow[i]];
		}
	}
	return s;
}

int main()
{
	int i,j;
	init();
	for(int i = 1; i <= P; i++)
	{
		dijkstra(i);
		if((j = sum()) < ans)
		{
			ans = j;
		}
	}
	fout << ans << endl;
    return 0;
}

