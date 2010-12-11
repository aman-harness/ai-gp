/*
ID: interne4
PROG: race3
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
ifstream fin("race3.in");
ofstream fout("race3.out");

//#define DEBUG_MODE
#ifdef DEBUG_MODE
#endif
const int maxN = 50 + 1, maxM = 100 + 1;
int s[maxN][maxN] = {0};	/*point i to point s[i][j],s[i][0] means how many 
							streets do it have */
bool m[maxN][maxN] = {0};	/*the adjacency matrix*/
bool v[maxN] = {0};			/*which nodes have been visited*/
int q[maxN] = {0};			/*the queue of bfs*/
int n;

int ua[maxN] = {0};			/*the set of unavoidable points. ua[0] means 
							the total*/
int sp[maxN] = {0};			/*the det of splitting points. sp[0] means
							the total*/
int re[maxN] = {0};			/*the record of visited points.*/
int canA;
int task = 1;

void bfs(int sta,int end)
{
	int i = 0;
	int op,cl;
	memset(v,0,sizeof(v));
	op = 1;
	cl = 0;
	q[cl] = sta;
	v[sta] = 1;
	canA = 0;
	do
	{
		int t = q[cl];
#ifdef DEBUG_MODE
			fout << t << ' ';
#endif
		if(task == 2 && re[t])
		{
			canA = 1;
			return;
		}
		if(t == end)
		{
			canA = 1;
			return;
		}
		for(i = 1; i <= s[t][0]; i ++)
		{
			if(!v[s[t][i]])
			{
				q[op ++] = s[t][i];
				v[s[t][i]] = 1;
			}
		}
		cl ++;
	}while(op > cl);
	
	
}

void work()
{
	int i,j;
	int t;
	for(i = 1; i < n - 1; i ++)
	{
		t = s[i][0];
		s[i][0] = 0;
		bfs(0,n-1);
		s[i][0] = t;
		
		if(!canA)
			ua[++ ua[0]] = i;
	}
	/*for(i = 0; i < n; i ++)
		for(j = 0; j < n; j ++)
			if(m[i][j])
				s[j][++ s[j][0]] = i;*/
	for(i = 1; i <= ua[0]; i ++)
	{
		task = 1;
		/*t = s[ua[i]][0];
		s[ua[i]][0] = 0;
		bfs(0,n-1);
		s[ua[i]][0] = t;
		if(!canA)
		{*/
			t = s[ua[i]][0];
			s[ua[i]][0] = 0;
			bfs(0,-1);
			s[ua[i]][0] = t;
			for(j=0;j<n;j++)
				re[j] = v[j];
			re[ua[i]] = 0;
			task = 2;
			bfs(ua[i], -1);
			if(!canA)
				sp[++ sp[0]] = ua[i];
#ifdef DEBUG_MODE
	fout << endl;
#endif
		//}
	}
}

void init()
{
	int i,j;
	int r;
	i = 0;
	do
	{
		do
		{
			fin >> r;
			if(r != -2 && r != -1)
				s[i][++ s[i][0]] = r, m[i][r] = 1;
		}while(r != -2 && r != -1);
		i ++;
	}while(r != -1);
	n = i - 1;			
}

void output()
{
	int i;
	fout << ua[0];
	for(i = 1; i <= ua[0]; i ++)
		fout << ' ' << ua[i];
	fout << endl;
	fout << sp[0];
	for(i = 1; i <= sp[0]; i ++)
		fout << ' ' << sp[i];
	fout << endl;
}

int main()
{
	init();
	work();
	output();
    return 0;
}
