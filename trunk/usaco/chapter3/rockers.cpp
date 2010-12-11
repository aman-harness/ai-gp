/*
ID: interne4
PROG: rockers
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("rockers.in");
ofstream fout("rockers.out");
const int MaxN = 20 + 1;
int f[MaxN][MaxN][MaxN]={0}; // number i CD j pos pre k.
int N,M,T,v[MaxN]={0};

int main()
{
	int i,j,k,t;
	fin >> N >> T >> M;
	for(i=1;i<=N;i++)
		fin >> v[i];
	for(k=1;k<=N;k++)
		for(i=1;i<=M;i++)
			for(j=0;j<=T;j++)
			{
				if(j >= v[k] && f[k-1][i][j-v[k]] + 1 > f[k-1][i][j])
					t = f[k-1][i][j-v[k]] + 1;
				else
					t = f[k-1][i][j];
				if(t > f[k][i-1][T])
					f[k][i][j] = t;
				else
					f[k][i][j] = f[k][i-1][T];
			}
	fout << f[N][M][T] << endl;
    return 0;
}
