#include <fstream>
using namespace std;
ifstream fin("telecow");
ofstream fout("telecow");
const int maxN = 100 + 1;
int map[maxN][maxN] = {0};
int vl[maxN][maxN] = {0};
bool v[maxN][maxN] = {0};

int q[maxN * 2] = {0};
int tb[maxN * 2] = {0};

void init()
{
	int i,a,b;
	fin >> n >> m >> c1 >> c2;
	for(i=1;i<=m;i++)
	{
		fin >> a >> b;
		map[a][b] = 1;
	}
}

int bfs()
{
	int i,now,s;
	int op,cl;
	s = 0;
	op = 0;
	cl = 1;
	q[op] = c1;
	tb[op] = -1;
	do
	{
		now = q[op ++];
		if(now == c2)
		{
			break;
		}
		for(i = 1; i <= n; i ++)
		{
			if(map[now][i] && !v[i] && vl[now][i] >= 0)
			{
				tb[cl] = op;
				q[cl ++] = i;
				v[i] = 1;
			}
		}
		s ++;
	}while(op < cl);
	
	if(now == c2)
	{
		while(tb[op] >= 0)
		{
			vl[q[tb[op]]][q[op]] = -1;
			vl[q[op]][q[tb[op]]] = 1;
			op = tb[op];
		}
		return s;
	}
	else
	{
		return -1;
	}
}

int maxflow()
{
	int i;
	i = 0;
	while(bfs() >= 0) i ++;
	return 0;
}

int main()
{
	int i,j;
	init();
	
	maxflow();
	
	return 0;
    
}
