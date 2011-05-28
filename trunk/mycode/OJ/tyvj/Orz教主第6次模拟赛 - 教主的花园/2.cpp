/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
//#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
using namespace std;
//ifstream cin("2.in");
//ofstream cout("2.out");
const int maxN = 10000 + 1;
int n,m;
long long ans = 2000000000 * 100000;
int a[maxN * 2] = {0};
int b[maxN * 2] = {0};
long long f[maxN * 2][2] = {0};

void init()
{
	int i,j;
	cin >> n >> m;
	for(i=1;i<=n;i++)
		cin >> a[i];
	for(i=n+1;i<=n*2+1;i++)
		a[i] = a[i-n];
}

int main()
{
	int i,j;
	long long ax;
	init();
	for(j=1;j<=n;j++)
	{
		f[j][0] = 0;
		f[j][1] = 0;
	for(i=1+j;i<=j+n;i++)
	{
		if(a[i - 1] < a[i])
		{
			ax = a[i] - a[i-1];
			f[i][0] = min(f[i-1][1] + m + ax * ax, f[i-1][0] + ax * ax);
			f[i][1] = min(f[i-1][1] + ax, f[i-1][0] + m + ax);
		}
		else if(a[i - 1] >= a[i])
		{
			ax = a[i - 1] - a[i];
			f[i][0] = min(f[i-1][1] + m + ax, f[i-1][0] + ax);
			f[i][1] = min(f[i-1][1] + ax * ax, f[i-1][0] + m + ax * ax);
		}
	}
		ans = min(ans,f[j+n][0]);
		ans = min(ans,f[j+n][1]);
			
	}
	for(i=1;i<=n;i++)
		b[i] = a[n-i+1];
	for(i=1;i<=n;i++)
		a[i] = b[i];
	for(i=n+1;i<=n*2+1;i++)
	{
		a[i] = a[i-n];
	}
	for(j=1;j<=n;j++)
	{
		f[j][0] = 0;
		f[j][1] = 0;
	for(i=1+j;i<=j+n;i++)
	{
		if(a[i - 1] < a[i])
		{
			ax = a[i] - a[i-1];
			f[i][0] = min(f[i-1][1] + m + ax * ax, f[i-1][0] + ax * ax);
			f[i][1] = min(f[i-1][1] + ax, f[i-1][0] + m + ax);
		}
		else if(a[i - 1] >= a[i])
		{
			ax = a[i - 1] - a[i];
			f[i][0] = min(f[i-1][1] + m + ax, f[i-1][0] + ax);
			f[i][1] = min(f[i-1][1] + ax * ax, f[i-1][0] + m + ax * ax);
		}
	}
		ans = min(ans,f[j+n][0]);
		ans = min(ans,f[j+n][1]);
			
	}
	cout << ans << endl;
	return 0;
}
