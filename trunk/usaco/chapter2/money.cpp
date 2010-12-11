/*
ID: interne4
PROG: money
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("money.in");
ofstream fout("money.out");
int n,v;
int value[30]={0};
long long f[30][10001]={0};

int main()
{
	int i,j;
	fin >> v >> n;
	for(i = 1; i <= v; i ++)
	{
		fin >> value[i];
		f[i][0] = 1;
	}
	for(j=1;j<=v;j++)
	{
		for(i = 1; i <= n; i++)
		{
			f[j][i] = f[j-1][i];
			if(i >= value[j])
			f[j][i] += f[j][i-value[j]];
		}
		/*
		for(i=0;i<=n;i++)
		{
			fout << f[j][i] << ' ';
		}
		fout << endl;*/
	}
	fout << f[v][n] << endl;
    return 0;
}
/* 数组从1开始的声明时要加1*/

