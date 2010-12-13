/*
ID: interne4
PROG: schlnet
LANG: C++
DATA: 2010.12.11
ALGO: search gragh
PROV: 
if a school is receiving school, it must can be called by other school.
Else it must receive a copy of the new software.
So we just need to count the number of unreceiving school in order for
Subtask A.

To finish the Subtask B, we should prove a obvious but important fact.
if an extension have to be made, the receiving school of the school 
which has the extension can has this extension and make more schools
can introduce the software to these new schools, which this extension 
causes.
So if we want to compute the minimal number of extensions,
we should use the extensions on the school which doesn't have a 
distribution list of the school hasn't been introduced. Then make a 
program compute which school should has some extensions. Finally, we 
solved this problem.
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <memory.h>
using namespace std;
ifstream fin("schlnet.in");
ofstream fout("schlnet.out");
const int maxN = 100 + 1;
int adj[maxN][maxN] = {0};
int nadj[maxN][maxN] = {0};
int link[maxN] = {0};
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
			fin >> adj[i][++adj[i][0]];
		}while(adj[i][adj[i][0]] > 0);
		adj[i][0] --;
	}
}

void addE(int f,int x)
{
	int i;
	for(i = 1; i <= nadj[f][0]; i ++)
		if(nadj[f][i] == x)
			return;
	nadj[f][++nadj[f][0]] = x;
}

bool v[maxN] = {0};
bool isA[maxN] = {0};
int s,ans;


void tarjan(int i)
{
	int j;
	DFN[i]=LOW[i]=++Dindex;
	instack[i]=true;
	Stap[++Stop]=i;
	for (edge *e=V[i];e;e=e->next)
	{
		j=e->t;
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

void expand(int sch)
{
	int i;
	v[sch] = 1;
	isA[sch] = 1;
	fout << sch << endl;
	
	for(i = 1; i <= adj[sch][0]; i ++)
	{
		if(!v[adj[sch][i]])
		{
			expand(adj[sch][i]);
		}
	}
}

int origin;

void expandD(int sch)
{
	int i;
	bool isE = 0;
	
	v[sch] = 1;
	fout << sch << endl;
	
	for(i = 1; i <= adj[sch][0]; i ++)
	{
		if(!v[adj[sch][i]])
		{
			isE = 1;
			expand(adj[sch][i]);
		}
	}
	
	if(isE)
	{
		for(i = 1; i <= nadj[origin][0]; i ++)
		{
			if(nadj[origin][i] == sch)
				break;
		}
		if(i > nadj[origin][0])
		{
			ans ++;
		}
	}
}


int main()
{
	int i,j;
	init();
	for(i = 1; i <= n; i ++)
	{
		memset(v,0,sizeof(v));
		memset(isA,0,sizeof(isA));
		expand(i);
		for(j = 1; j <= n; j ++)
		{
			if(isA[j])
				fout << j << ' ';
			if(isA[j] && j == link[i])
				break;
		}
		fout << endl;
		
		if(j <= n)
			addE(j,i);
		else if(link[i] == 0)
		{
			for(j = 1; j <= n; j ++)
				if(isA[j])
					link[j] = i;
		}
	}
	
	s = 0;
	for(i = 1; i <= n; i ++)
	{
		fout << i << ' ' << link[i] << endl;
		if(!isRe[link[i]])
		{
			isRe[link[i]] = 1;
			s ++;
		}
	}
	
	fout << s << endl;
	
	ans = 0;
	for(i = 1; i <= n; i ++)
	{
		if(isRe[i])
		{
			origin = i;
			expandD(i);
		}
	}
	
	fout << ans << endl;
	return 0;
}
