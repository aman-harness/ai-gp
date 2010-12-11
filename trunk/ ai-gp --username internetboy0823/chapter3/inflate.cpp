/*
ID: interne4
PROG: inflate
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("inflate.in");
ofstream fout("inflate.out");

const int maxN = 10000;
int n,m;
int f[maxN+1]={0};
int p[maxN+1]={0};
int t[maxN+1]={0};

int main()
{
	int i,j,x;
	fin >> m >> n;
	for(i=1;i<=n;i++)
		fin >> p[i] >> t[i];
	for(i=1;i<=n;i++)
		for(j=t[i];j<=m;j++)
			if((x = f[j - t[i]] + p[i]) > f[j])
				f[j] = x;
	fout << f[m] << endl;
    return 0;
}
