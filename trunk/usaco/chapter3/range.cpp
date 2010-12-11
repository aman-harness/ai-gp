/*
ID: interne4
PROG: range
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("range.in");
ofstream fout("range.out");
const int MaxN = 250 + 1;
int map[MaxN][MaxN] = {0};
int n;
int ans[MaxN] = {0};

void init()
{
	int i,j;
	char ch;
	fin >> n;
	for(i=1;i<=n;i++)
	{
		fin.get();
		for(j=1;j<=n;j++)
		{
			ch = fin.get();
			map[i][j] = ch - '0';
		}
	}
}

int main()
{
	init();
	
	int i,j,k;
	
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		if(!map[i][j])
			continue;
		k = map[i-1][j-1];
		if(k > map[i][j-1])
			k = map[i][j-1];
		if(k > map[i-1][j])
			k = map[i-1][j];
		map[i][j] = k + 1;
	}
	int maxA = 0;
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		if(map[i][j] > maxA)
			maxA = map[i][j];
		for(k=2;k<=map[i][j];k++)
			ans[k] ++;
	}
	for(i=2;i<=maxA;i++)
		fout << i << ' ' << ans[i] << endl;
    return 0;
}
