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
//list<int> adj[maxN];
//list<int> wcs;
//vector<int> ansl;
bool v[maxN * 2] = {0};
//bool inw[maxN * 2] = {0};
//bool ine[maxN * 2] = {0};
int ans = 0x7fffffff;
int n, m, c1, c2;
int vl[maxN * 2][maxN * 2] = {0};
int map[maxN * 2][maxN * 2] = {0};
int q[maxN * 4] = {0};
int tb[maxN * 4] = {0};

void init()
{
	int i,a,b;
	fin >> n >> m >> c1 >> c2;
	for(i=1;i<=n;i++)
	{
		map[2 * i - 1][2 * i] = 1;
		//adj[2 * i - 1].push_front(2 * i);
	}
	
	for(i=1;i<=m;i++)
	{
		fin >> a >> b;
		map[2 * a][2 * b - 1] = 1;
		map[2 * b][2 * a - 1] = 1;
		//adj[2 * a].push_front(2 * b - 1);
		//adj[2 * b].push_front(2 * a - 1);
	}
}

int bfs()
{
        int i,now,s;
        int op,cl;
        s = 0;
        op = 0;
        cl = 1;
        q[op] = c1 * 2;
        tb[op] = -1;
        do
        {
                now = q[op ++];
                if(now == c2 * 2 - 1)
                {
                        break;
                }
                for(i = 1; i <= n * 2; i ++)
                {
                        if(map[now][i] && !v[i] && vl[now][i] >= 0)
                        {
                                tb[cl] = op - 1;
                                q[cl ++] = i;
                                v[i] = 1;
                        }
                }
                s ++;
        }while(op < cl);
        
        op --;
        
        if(now == c2 * 2 - 1)
        {
                while(tb[op] >= 0)
                {
                        vl[q[tb[op]]][q[op]] = -1;
                        vl[q[op]][q[tb[op]]] = 1;
                        op = tb[op];
                		fout << op << ' ' ;
                }
        fout << endl;
                return s;
        }
        else
        {
                return -1;
        }
}
 
int maxflow()
{
	int i, s;
	i = 0;
	s = 0;
	while(bfs() >= 0)
	{
		memset(v,0,sizeof(v));
		i ++;
	}
	fout << i << endl;
		
	int ans[maxN],ansN = 0;
	for(i=1;i<=n;i++)
	{
		if(v[i * 2])
		for(int j = 1; j <= n * 2; j ++)
			if(map[i * 2][j] && !v[j])
			{
				ans[ansN ++] = i;
				break;
			}
	}
		
	for(i = 0; i < ansN - 1; i ++)
		fout << ans[i] << ' ';
	if(ansN >= 1)
		fout << ans[ansN - 1] << endl;
	return 0;
}
 
int main()
{
        int i,j;
        init();
        maxflow();
        return 0;
    
}
