/*
ID: interne4
PROG: barn1
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("barn1.in");
ofstream fout("barn1.out");

int a[201]={0};
int b[201]={0};
int n,s,m;
int compZ(const void* q, const void* p)
{
	return *(int *)q - *(int *)p;
}
int comp(const void* q, const void* p)
{
	return *(int *)p - *(int *)q;
}

int main()
{
	int i,j,v;
	fin >> m >> s >> n;
	for(i=0;i<n;i++)
		fin >> a[i];
	qsort(a,n,sizeof(int),compZ);
	for(i=0;i<n-1;i++)
		b[i] = a[i+1] - a[i];
	qsort(b,n-1,sizeof(int),comp);
	v = a[n-1] - a[0] + 1;
	if(m>n)
		m = n;
	for(i=0;i<m-1;i++)
		v -= b[i] - 1;
	fout << v <<endl;
    return 0;
}

