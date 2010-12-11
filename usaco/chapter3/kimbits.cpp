/*
ID: interne4
PROG: kimbits
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <cmath>
#include <memory.h>
using namespace std;
ifstream fin("kimbits.in");
ofstream fout("kimbits.out");

long long n,l,k;

long long C(int m,int n)
{
	int i,j;
	long long s = 1;
	for(i = m + 1,j = 1; i <= n && j <= n - m; i ++ ,j ++)
	{
		if(i <= n) s *= i;
		if(j <= n - m) s /= j;
	}
	return s;
}

int main()
{
	long long i,j,ls;
	long long s,last;
	char str[100];
	memset(str,'0',sizeof(str));
	
	fin >> n >> l >> k;
	
	if(k == 0)
	fout << 0 <<endl;
	k--;
	ls = l;
	
	while(1)
	{
		s = 1;
		last = s;
		for(i=1;i<=n;i++)
		{
			if(s <= k)
				last = s;
			else
				break;
			for(j=1;j<=(i>ls?ls:i);j++)
				s += C(j-1,i-1);
		}
		str[i-1] = '1';
		k -= last;
		ls --;
		if(k < 1)
			break;
		
	}
	//fout << n << endl;
	for(i = n; i >= 1; i --)
	{
		fout << str[i];
	}
	
	fout << endl;
	return 0;
}

/*
1 0
10 11
100 101 110 111
1000 1001 1010 1011 1100 1101 1110
10000 10001 10010 10011
*/


