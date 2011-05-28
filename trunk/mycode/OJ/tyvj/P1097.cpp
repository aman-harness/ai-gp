/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int f[1010][1010][2] = {0};	//1ÐÝÏ¢×´Ì¬£¬0×ÔÓÉ×´Ì¬
int n,p;
int d[1010] = {0};
int w[1010] = {0};

int l[1010] = {0};
int r[1010] = {0};

int main()
{
	int i,j;
	int b;
		
	cin >> n >> p;
	for(i = 1; i <= n; i ++)
		cin >> d[i] >> w[i];
	
	for(i = 1; i <= p; i ++)
		l[i] = l[i - 1] + w[i];
	for(i = n; i >= p; i --)
		r[i] = r[i + 1] + w[i];
	
	for(i = 1; i <= n; i ++)
	{
		for(j = 0; j <= i; j ++)
		{
			if(p-i+j < 1)
				continue;
			if(p+j > n)
				break;
			b = l[p-i+j] + r[p+j+1];
			if(-i+j < 0)
			f[p-i+j][p+j][0] = 
			min(b * (d[p-i+j+1] - d[p-i+j]) + f[p-i+j+1][p+j][0],
				b * (d[p+j] - d[p-i+j]) + f[p-i+j+1][p+j][1]
				);
			else f[p-i+j][p+j][0] = 1000000001;
			
			b = l[p-i+j-1] + r[p+j];
			if(j > 0)
			f[p-i+j][p+j][1] = 
			min(b * (d[p+j] - d[p-i+j]) + f[p-i+j][p+j-1][0],
				b * (d[p+j] - d[p+j-1]) + f[p-i+j][p+j-1][1]
				);
			else f[p-i+j][p+j][1] = 1000000001;
			//cout <<  p-i+j << ' ' << p + j << endl;
			//cout << f[p-i+j][p+j][0] << ' ' << f[p-i+j][p+j][1] << endl;
		}
	}
	cout << min(f[1][n][0],f[1][n][1]) << endl;
	while(1);
    return 0;
}
