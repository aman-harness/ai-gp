/*
ID: interne4
PROG: nocows
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
const int M = 9901;
int store[500][500];
int f(int N, int K)
{
     int res = 0;
     if (N <= 0 || K <= 0)
     {
         return 0;
     }
     if (1 == N)
     {
         return 1;
     }
     if (-1 != store[N][K])
     {
         return store[N][K];
     }
     for (int i=1; i<=N-2; i+=2)
     {
         res = (res + f(i, K-1) * f(N-i-1, K-1)) % M;
     }
     return store[N][K] = res;
}

int main()
{
     ifstream fin("nocows.in");
     ofstream fout("nocows.out");
     int N, K;
     memset(store, -1, sizeof(store));
     while (fin >> N >> K)
     {
         fout << (f(N, K) - f(N, K-1) + M) % M << endl;
     }     
     return 0;
}
/*
#include <fstream>
using namespace std;
ifstream fin("nocows.in");
ofstream fout("nocows.out");

int treedp[100][2000]={0}; //高i树j个子叶的方案
int treeMax[100]={0}; //高i树的最多叶节点
int n,k;

int main()
{
	int i,j,l,f,r,p,s,gccSB;
	fin >> n >> k;
	treeMax[1] = 1;
	treedp[1][1] = 1;
	for(i = 2; i <= 10; i ++)
	{
		treeMax[i] = (treeMax[i-1] + 1) * 2 - 1;
		treedp[i][treeMax[i]] = 1;
	}
	for(i = 10; i < 100; i ++)
		treeMax[i] = 1000;
	for(i = 2; i <= k; i ++)
	{
		if(treeMax[i]-1 > n)gccSB = n;
		else gccSB = treeMax[i]-1;
		for(j = i/2*2+1; j <= gccSB; j += 2)
		{
			f = (j-1)/2;
			l = j - 1;
			if(l > treeMax[i-1])
				l = treeMax[i-1];
			if(l%2 == 0)
				l--;
			for(; l > f; l -=2)
			{
				r = j - 1 - l;
				if(r==l)
					treedp[i][j] += (treedp[i-1][l];
				s = 0;
				
				if(r != 0)
				{			
				    for(p = 1; p <= i - 1; p++)
					    s += treedp[p][r];
				}
				else s = 1;
				treedp[i][j] += (treedp[i-1][l] * s) * 2%9901;
			}
			//fout << j << ' '<< treedp[i][j] << '.';
		}
		//fout << endl;
	}
	fout << treedp[k][n]%9901 << endl;
    return 0;
}
*/
