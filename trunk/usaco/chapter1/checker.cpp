/*
ID: interne4
PROG: checker
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("checker.in");
ofstream fout("checker.out");
bool cow[20],diaL[40],diaR[40];
int N=6,ansN=0,queen[20];

void expand(int n)
{
	int i;
	if(n>N)
	{
		if(ansN<3)
		{
			for(i=1;i<N;i++)
				fout << queen[i] << ' ';
			fout << queen[N] << endl;
		}
		ansN++;
		return;
	}
	for(i=1;i<=N;i++)
		if(cow[i] & diaL[i+n-1] & diaR[i-n+N])
		{
			cow[i] = false;
			diaL[i+n-1] = false;
			diaR[i-n+N] = false;
			queen[n] = i;
			expand(n+1);
			cow[i] = true;
			diaL[i+n-1] = true;
			diaR[i-n+N] = true;
			queen[n] = 0;
		}
}

void init()
{
	int i;
	for(i=0;i<=N;i++) cow[i] = true;
	for(i=0;i<=N*2;i++) diaL[i] = diaR[i] = true;
}

int main()
{
	fin >> N;
	init();
	expand(1);
	fout << ansN << endl;
    return 0;
}
/*
dfs深度搜索 注意搜索后赋值数组还原。
*/
