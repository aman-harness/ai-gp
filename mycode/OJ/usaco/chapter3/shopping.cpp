/*
ID: interne4
PROG: shopping
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <memory.h>
using namespace std;
ifstream fin("shopping.in");
ofstream fout("shopping.out");
const int MaxN = 5 + 1;
const int MaxS = 99 + 1;

struct Offer
{
	int n;
	int price;
	int c[MaxN];
	int k[MaxN];
}way[MaxS];

int s,n;
int p[MaxN],k[MaxN],c[MaxN];
int f[100000];				// Its size is more than MaxN ^ MaxN.
int dp[MaxN];

void init()
{
	int i,j;
	int code[10000] = {0}; // Convert the prodect code to the number of it.
	
	for(i=0;i<100000;i++)
		f[i] = 100000000;
	f[0] = 0;
	
	fin >> s;
	for(i=0;i<s;i++)
	{
		fin >> way[i].n;
		for(j=0;j<way[i].n;j++)
			fin >> way[i].c[j] >> way[i].k[j];
		fin >> way[i].price;
	}
	fin >> n;
	for(i=1;i<=n;i++)
	{
		fin >> c[i];
		fin >> k[i];
		fin >> p[i];
		code[c[i]] = i;
	}
	
	for(i=0;i<s;i++)
		for(j=0;j<way[i].n;j++)
			way[i].c[j] = code[way[i].c[j]];
			
	for(i=s;i<s+n;i++)
	{
		way[i].n = 1;
		way[i].price = p[i-s+1];
		way[i].k[0] = 1;
		way[i].c[0] = i-s+1;
	}
	s = s + n;
}

int Adp(int n,int dp[])
{
	int l = 0,g = 1;
	for(int i=1;i<=n;i++)
	{
		if(dp[i] < 0)
			return -1;
		l += g * dp[i];
		g *= MaxN;
	}
	return l;
}

void work(int d)
{
	int i,j,x[10],l,g;
	//char str[10];
	if(d == n+1)
	{
		l = Adp(n,dp);
		for(i=0;i<s;i++)
		{
			for(j=1;j<=n;j++)
				x[j] = dp[j];
			for(j=0;j<way[i].n;j++)
				x[way[i].c[j]] -= way[i].k[j];
			g = Adp(n,x);
			if(g != -1 && f[g] + way[i].price < f[l])
				f[l] = f[g] + way[i].price;
		}
		//itoa(l,str,6);
		//fout << str << ' ' << f[l] << endl;
		return;
	}
	for(i=0;i<=k[d];i++)
	{
		dp[d] = i;
		work(d+1);
	}
	dp[d] = i;
}

int main()
{
	int i;
	init();
	work(1);
	
	fout << f[Adp(n,k)] << endl;
    return 0;
}

/*
It's necessary to deal with the boundary of the array, or you program might
be wrong in some test points.
*/
