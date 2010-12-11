/*
ID: interne4
PROG: milk2
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("milk2.in");
ofstream fout("milk2.out");
int x[5000][2]={0},n;

int comp(const void *p, const void *q)
{
    return (((int *)p)[0] - ((int *)q)[0]);
}

int main()
{
	int i,j,maxs,maxl,s,l,f;
	fin >> n;
	for(i=0;i<n;i++)
	    fin >> x[i][0] >> x[i][1];
	qsort(x,n,sizeof(x[0]),comp);
	
	f=x[0][0];
	l=x[0][1];
	maxl = 0;
	maxs = x[0][1] - x[0][0];
	for (i=0;i<n;i++)
	{
		if (x[i][1] <= l)
		    continue;
	    if (x[i][1] > l)
	    {
	        if (x[i][0] > l)
	        {
	            if (l - f > maxs)
		            maxs = l - f;
		        if (x[i][0] - l > maxl)
		            maxl = x[i][0] - l;
		        f = x[i][0];
		        l = x[i][1];
	        }
	        else l = x[i][1];
	    }
	}
	fout << maxs <<' ' << maxl <<endl;
	
    return 0;
}
