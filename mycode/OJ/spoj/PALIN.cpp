/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
/*
Author:		Alchemist
Data:		2011.1.31
Problem:	Prime Generator
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxN = 10000000 + 10;
int t;
int s,ans;
char str[maxN]={0};
int sn;

void addOne(int p)
{
	int i;
	str[i = p] += 1;
	while(str[i] > '9')
	{
		str[i --] = '0';
		str[i] ++;
	}
	//if(str[0] == '1')
	//	sn ++;
}

int main()
{
	int i,j,k;
	int l,r;
	int st;
	scanf("%d",&t);
	for(k = 1; k <= t; k ++)
	{
		str[0] = '0';
		scanf("%s",&str[1]);
		sn = strlen(str) - 1;
		r = sn / 2 + 1;
		l = (sn - 1) / 2 + 1;
		addOne(sn);
		//cout << sn << endl;
		//cout << l << ' ' << r << ' ' << sn << endl;
		if(str[0] > '0')
		{
			if(sn % 2)
				r --;
			else
				l --;
			st = 0;
		}
		else
			st = 1;
		//cout << l << ' ' << r << ' ' << sn << endl;
		j = 0;
		while(str[l - j] == str[r + j] && l - j >= 0 && r + j <= sn) j ++;
		if(l - j < 0 || r + j > sn)
		{
			for(i = st; i <= l; i ++)
				printf("%c",str[i]);
			for(i = r - 1; i >= st; i --)
				printf("%c",str[i]);
		}
		else
		{
			if(str[l - j] > str[r + j])
			{
				for(i = st; i <= l; i ++)
					printf("%c",str[i]);
				for(i = r - 1; i >= st; i --)
					printf("%c",str[i]);
				}
			else
			{	
				addOne(l);
				for(i = st; i <= l; i ++)
					printf("%c",str[i]);
				for(i = r - 1; i >= st; i --)
					printf("%c",str[i]);
			}
		}
		printf("\n");
	}
	return 0;
}

