/*
ID: interne4
PROG: stamps
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("stamps.in");
ofstream fout("stamps.out");
const int maxN=2000000;
short f[maxN + 10001]={0};
short p[50]={0};
int n,m;

int comp(const void* q,const void* p)
{
	return *(short*)q - *(short*)p;
}
int main()
{
	int i,j,mins,s;
	fin >> m >> n;
	for(i=0;i<n;i++)
		fin >> p[i];
	f[0] = 1;
	s = 0;
	mins = m + 1;
	qsort(p,n,sizeof(p[0]),comp);
	int end = p[n-1]*m;
	for(i=0;i<=end;i++)
	{
		if(f[i] == 0) break;
		s++;
		if(f[i] > m) continue;
		for(j=0;j<n;j++)
			if(f[i+p[j]] == 0 || f[i+p[j]] > f[i] + 1 )
				f[i+p[j]] = f[i] + 1;
	}
	fout << s - 1 << endl;
	/*
	for(i=p[n-1];i<=end;i++)
	{
		for(j=0;j<n;j++)
		{
			if(f[i-p[j]] > 0 && f[i-p[j]] < mins)
				mins = f[i-p[j]];
			if(mins < m + 1)
				f[i] = mins + 1;
		}*/
    return 0;
}
