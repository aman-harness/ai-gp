/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
/*
Author:		Alchemist
Data:		2011.1.30
Problem:	Prime Generator
*/
#include <iostream>
#include <cmath>
using namespace std;
const int maxN = 1000000000;
int m,n;
int s,ans;
bool p[32000]={0};
int pm[32000]={0},pn = 0;

void init()
{
	int i,j;
	for(i=2;i<32000;i++)
	{
		if(p[i] == 0)
		{
			for(j = i * 2; j < 32000; j += i)
				p[j] = 1;
			pm[pn ++] = i;
		}
	}
}

bool isP(int p)
{
	int i,j,l;
	l = sqrt(p);
	for(i = 0; pm[i] <= l; i ++)
		if(!(p % pm[i]))
			return false;
	if(p < 2)
		return false;
	return true;
}

int main()
{
	init();
		
	int i,j;
	cin >> s;
	for(i=1;i<=s;i++)
	{
		cin >> m >> n;
		ans = 0;
		for(j=m;j<=n;j++)
		{
			if(isP(j))
				cout << j << endl;
		}
		cout << endl;
	}
	return 0;
}
