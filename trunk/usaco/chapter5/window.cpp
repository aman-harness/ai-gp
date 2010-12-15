/*
ID: interne4
PROG: window
LANG: C++
DATA: 2010.12.15
ALGO: Links , Simulation
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <list>
#include <memory.h>
using namespace std;
ifstream fin("window.in");
ofstream fout("window.out");

const int maxN = 100 + 1;
int adj[maxN][maxN] = {0};
int nadj[maxN][maxN] = {0};
bool isRe[maxN] = {0};
int n;

void init()
{
	int i,j;
	fin >> n;
	for(i = 1; i <= n; i ++)
	{
		do
		{
			fin >> nadj[i][++nadj[i][0]];
		}while(nadj[i][nadj[i][0]] > 0);
		nadj[i][0] --;
	}
}

int Stop,Bcnt,Dindex;
int DFN[maxN] = {0};
int LOW[maxN] = {0};
int Stap[maxN] = {0};
bool instack[maxN] = {0};
int Belong[maxN] = {0};
int s,ans;


void tarjan(int i)
{
	int j;
	DFN[i]=LOW[i]=++Dindex;
	instack[i]=true;
	Stap[++Stop]=i;
	for (int k = 1; k <= nadj[i][0] ; k ++)
	{
		j = nadj[i][k];
		if (!DFN[j])
		{
			tarjan(j);
			if (LOW[j]<LOW[i])
				LOW[i]=LOW[j];
		}
		else if (instack[j] && DFN[j]<LOW[i])
			LOW[i]=DFN[j];
	}
	if (DFN[i]==LOW[i])
	{
		Bcnt++;
		do
		{
			j=Stap[Stop--];
			instack[j]=false;
			Belong[j]=Bcnt;
		}
		while (j!=i);
	}
}

int origin;

bool v[maxN] = {0};
bool isA[maxN] = {0};
bool isS[maxN]= {0};

void expandD(int sch)
{
	int i;
	bool isE = 1;
	
	v[sch] = 1;
	//fout << sch << endl;
	
	for(i = 1; i <= adj[sch][0]; i ++)
	{
		isE = 0;
		if(!v[adj[sch][i]])
		{
			expandD(adj[sch][i]);
		}
	}
	
	if(isE && !isS[sch])
	{
		isS[sch] = 1;
		ans ++;
	}
}


int main()
{
	int i,j,k;
	init();
	
	Stop=Bcnt=Dindex=0;
	memset(DFN,0,sizeof(DFN));
	for (i=1;i<=n;i++)
		if (!DFN[i])
			tarjan(i);
	
	
	for(i = 1; i <= n; i ++)
		for(j = 1; j <= nadj[i][0]; j ++)
		{
			for(k=1;k<=adj[Belong[i]][0];k++)
				if(adj[Belong[i]][k] == Belong[nadj[i][j]])
					break;
			if(k > adj[Belong[i]][0] && Belong[nadj[i][j]] != Belong[i])
			{
				adj[Belong[i]][++ adj[Belong[i]][0]] = Belong[nadj[i][j]];
				isRe[Belong[nadj[i][j]]] = 1;
			}
		}
		
	n = Bcnt;
	
	s = 0;
	for(i = 1; i <= n; i ++)
	{
		if(!isRe[i])
		{
			s ++;
		}
	}
	
	fout << s << endl;
	
	ans = 0;
	for(i = 1; i <= n; i ++)
	{
		if(!isRe[i])
		{
			origin = i;
			expandD(i);
		}
	}
	if(n == 1)
		ans --;
	else
	{
		if(ans < s)
			ans = s;
	}
	fout << ans << endl;
	return 0;
}
