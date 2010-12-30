/*
ID: interne4
PROG: telecow
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <list>
#include <vector>
#include <cstring>
using namespace std;
ifstream fin("telecow.in");
ofstream fout("telecow.out");
const int maxN = 100 + 1;

//int map[maxN][maxN] = {0};
list<int> adj[maxN];
list<int> wcs;
vector<int> ansl;
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
	for(i=1;i<=n;i++)
		adj[i].sort();
}


void greedy()
{
	int i,j;
	int minS;
	int s;
	int total;
	int ma[maxN] = {0};
	int ar[maxN] = {0};
	list<int>::iterator it,it2,nextc;
	
	for(it2 = adj[c2].begin(); it2 != adj[c2].end(); it2 ++)
		ine[*it2] = 1;
		
	total = 1;
	wcs.push_front(c1);
	while(!wcs.empty())
	{
		minS = 0x7fffffff;
		memset(ma,0x7f,sizeof(ma));
		for(it = wcs.begin(); it != wcs.end(); it ++)
		{
			s = -1;
			//fout << *it << ' ';
			for(it2 = adj[*it].begin(); it2 != adj[*it].end(); it2 ++)
			{
				if(!v[*it2] && !inw[*it2])
				{
					s ++;
					ar[s] = *it2;
				}
			}
			if(s < minS)
			{
				minS = s;
				nextc = it;
			}
			else if(s == minS)
			{
				int t = 0;
				for(i = 0; i <= s ; i ++)
					if(ma[i] > ar[i])
					{
						t = 1;
						break;
					}
					else if(ma[i] < ar[i])
						break;
				if(t)
				{
					for(i = 0; i <= s ; i ++)
						ma[i] = ar[i];
					nextc = it;// 加入答案最小 
				}
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
		if(total == 3)
		{
			for(i = 1; i <= n; i ++)
				if(inw[i])
					fout << i << ' ';
			fout << endl;
		}
		if(total < ans)
		{
			ansl.clear();
			for(i = 0; i <= n; i ++)
				if(inw[i])
					ansl.push_back(i);
			ans = total;
		}
		else if(total == ans)
		{
			j = 0;
			int t = 0;
			for(i = 0; i < ansl.size(); i ++)
			{
				for(; j < ansl[i]; j ++)
					if(inw[j])
					{
						t = 1;
						break;
					}
				if(inw[ansl[i]] != 1)
					break;
			}
			if(t)
			{
				ansl.clear();
				for(i = 0; i <= n; i ++)
					if(inw[i])
						ansl.push_back(i);
			}
		}
	}
}

int main()
{
	init();
	greedy();
	fout << ans << endl;
	int i;
	for(i = 0; i < ansl.size() - 1; i ++)
		fout << ansl[i] << ' ';
	if(!ansl.empty())
	{
		fout << ansl[ansl.size() - 1];
		fout << endl;
	}
}
