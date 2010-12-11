/*
ID: interne4
PROG: milk6
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("milk6.in");
ofstream fout("milk6.out");
int n,m;
const int maxN =32 + 1;
int s[maxN] = {0},e[maxN] = {0};
int c[maxN][maxN] = {0};
int main()
{
	fin >> n >> m;
	int i,a,b,t;
	for(i=1;i<=m;i++0)
	{
		fin >> a >> b;
		fin >> t;
		c[a][b] += t;
	}
    return 0;
}
