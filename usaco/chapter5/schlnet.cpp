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
using namespace std;
ifstream fin("schlnet.in");
ofstream fout("schlnet.out");
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
			fin >> adj[i][++adj[i][0]];
			isRe[adj[i][adj[i][0]]] = 1;
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
bool inp[maxN] = {0};
int s,ans;

void expand(int sch)
{
	int i;
	fout << sch << endl;
	bool isE = 1;
	for(i = 1; i <= adj[sch][0]; i ++)
	{
		if(!v[adj[sch][i]])
		{
			isE = 0;
			inp[adj[sch][i]] = 1;
			v[adj[sch][i]] = 1;
			expand(adj[sch][i]);
			inp[adj[sch][i]] = 0;
		}
		else if(!inp[adj[sch][i]])
		{
			isE = 0;
		}
	}
	if(isE)
		ans += s;
}

int main()
{
	int i,j;
	s = 0;
	init();
	for(i = 1; i <= n; i ++)
	{
		if(!isRe[i])
			s ++;
	}
	if(s < 1)
		s = 1;
	fout << s << endl;
	
	ans = 0;
	for(i = 1; i <= n; i ++)
	{
		v[i] = 1;
		inp[i] = 1;
		expand(i);
		inp[i] = 0;
	}
	fout << ans << endl;
	return 0;
}
