#include <fstream>
#include <list>
using namespace std;
ifstream fin("telecow.in");
ofstream fout("telecow.out");
const int maxN = 100 + 1;

//int map[maxN][maxN] = {0};
list<int> adj[maxN];
list<int> wcs;
list<int> ansl;
bool v[maxN] = {0};
bool inw[maxN] = {0};
bool ine[maxN] = {0};
int ans = 0x7fffffff;
int n, m, c1, c2;
//int vl[maxN][maxN] = {0};
//int q[maxN * 2] = {0};
//int tb[maxN * 2] = {0};

void init()
{
	int i,a,b;
	fin >> n >> m >> c1 >> c2;
	for(i=1;i<=m;i++)
	{
		fin >> a >> b;
		//map[a][b] = 1;
		adj[a].push_front(b);
		adj[b].push_front(a);
	}
}


void greedy()
{
	int i,j;
	int minS, ;
	int s;
	int total;
	list<int>::iterator it,it2,nextc;
	
	for(it2 = adj[c2].begin(); it2 != adj[c2].end(); it2 ++)
		ine[*it2] = 1;
		
	total = 1;
	wcs.push_front(c1);
	while(!wcs.empty())
	{
		minS = 0x7fffffff;
		for(it = wcs.begin(); it != wcs.end(); it ++)
		{
			s = -1;
			//fout << *it << ' ';
			for(it2 = adj[*it].begin(); it2 != adj[*it].end(); it2 ++)
			{
				if(!v[*it2] && !inw[*it2])
				{
					s ++;
				}
			}
			if(s < minS)
			{
				minS = s;
				nextc = it;
			}
		}
		//fout << endl;
		for(it2 = adj[*nextc].begin(); it2 != adj[*nextc].end(); it2 ++)
		{
			if(!v[*it2] && !inw[*it2])
			{
				if(!ine[*it2])
					wcs.push_front(*it2);
				inw[*it2] = 1;
			}
		}
		wcs.erase(nextc);
		v[*nextc] = 1;
		inw[*nextc] = 0;
		total += minS;
		if(total < ans)
		{
			ansl.clear();
			for(i = 0; i <= n; i ++)
				if(inw[i])
					ansl.push_front(i);
			ans = total;
		}
	}
}

int main()
{
	init();
	greedy();
	fout << ans << endl;
	list<int>::iterator it;
	for(it = ansl.begin(); it != ansl.end(); it ++)
		fout << *it << ' ';
	if(!ansl.empty())
		fout << endl;
}
/*
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
    
}*/
