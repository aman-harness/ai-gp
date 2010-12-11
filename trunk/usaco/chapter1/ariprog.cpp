/*
ID: interne4
PROG: ariprog
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("ariprog.in");
ofstream fout("ariprog.out");
bool sp[2000000]={0};
int ans[10001][2]={0};
int n,m,maxM,ansN=0;


int comp(const void *p, const void *q)
{
    if((((int *)p)[1] - ((int *)q)[1]) == 0)
	    return (((int *)p)[0] - ((int *)q)[0]);
	else
		return (((int *)p)[1] - ((int *)q)[1]);
}


int main()
{
	int i,j,k;
	bool t;
	fin >> n >> m;
	for(i=0;i<=m;i++)
		for(j=0;j<=m;j++)
			sp[i*i+j*j]=1;
	maxM = m*m*2;
	for(i=0;i <= maxM - n + 1;i++)
	{
		for(j=1;j <= (maxM-i+1)/(n-1); j++)
		{
			t = 0;
			for(k=0;k<n;k++)
			if(!sp[i+k*j])
			{
				t=1;
				break;
			}
			if(!t)
			{
				ans[ansN][0]=i;
				ans[ansN++][1]=j;
			}
		}
	}
	if(ansN==0)
	{
		fout << "NONE" << endl;
		return 0;
	}
	qsort(ans,ansN,sizeof(ans[0]),comp);
    for(i=0;i<ansN;i++)
    {
	    fout << ans[i][0] << ' ' << ans[i][1] << endl;
    }
    return 0;
}
