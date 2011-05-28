/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
/*
Author:		Alchemist
Data:		2011.2.1
Problem:	Simple Arithmetics
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxN = 1000 + 10;
int t;
int s;
char c[maxN] = {0};
char be[maxN] = {0};
int cn;
char ans[maxN] = {0};
int ansn;
int sn;

void add(char* a,char* b,int an,int bn)
{
	int i,k;
	k = max(an, bn);
	memset(c,0,sizeof(c));
	for(i=0;i<k;i++)
	{
		c[i] += a[i] + b[i];
		if(c[i] > 9)
		{
			c[i + 1] += 1;
			c[i] -= 10;
		}
	}
	if(c[k] > 0)
		cn = k + 1;
	else
		cn = k;
}

void minu(char* a,char* b,int an,int bn)
{
	int i,k;
	k = max(an, bn);
	memset(c,0,sizeof(c));
	for(i=0;i<k;i++)
	{
		c[i] += a[i] - b[i];
		if(c[i] < 0)
		{
			c[i + 1] -= 1;
			c[i] += 10;
		}
	}
	k --;
	while(c[k] == 0 && k > 0) k --;
	cn = k + 1;
}

void mult(char* a, int an, int b)
{
	int i,k;
	memset(c,0,sizeof(c));
	k = an + 1;
	for(i=0;i<an;i++)
	{
		c[i] += (a[i] * b)%10;
		c[i + 1] += (a[i] * b)/10;
		if(c[i] > 9)
		{
			c[i + 1] += 1;
			c[i] -= 10;
		}
	}
	while(c[k - 1] == 0 && k > 1) k --;
	cn = k;
}

int main()
{
	int i,j,k;
	string a,b;
	char as[maxN],bs[maxN];
	int an,bn;
	string end;
	int st;
	char op;
	int lw,lwab;
	cin >> t;
	for(k = 1; k <= t; k ++)
	{
		cin >> a;
		for(i = 0; i < a.size(); i ++)
			if(a[i] == '+' || a[i] == '-' || a[i] == '*')
			{
				op = a[i];
				break;
			}
		b = a.substr(i + 1, a.size() - i - 1);
		a = a.substr(0, i);
		
		memset(as,0,sizeof(as));
		memset(bs,0,sizeof(bs));
		
		an = a.size();
		bn = b.size();
		for(i=0;i<an;i++)
			as[an-i - 1] = a[i] - '0';
		for(i=0;i<bn;i++)
			bs[bn-i - 1] = b[i] - '0';
		
		lw = a.size();
		if (b.size() + 1 > lw)
			lw = b.size() + 1;
		lwab = lw;
		
		if(op == '+')
		{
			add(as,bs,an,bn);
			lw = max(cn, lw);
			for(i=1;i<=lw-an;i++)
				printf(" ");
			printf("%s\n",a.c_str());
			
			for(i=1;i<=lw-bn - 1;i++)
				printf(" ");
			printf("+");
			printf("%s\n",b.c_str());
			
			
			for(i=1;i<=lw;i++)
				printf("-");
			printf("\n");
			
			for(i=1;i<=lw-cn;i++)
				printf(" ");
			for(i=0;i<cn;i++)
				printf("%c",c[cn - i - 1] + '0');
			printf("\n");
		}
		else if(op == '-')
		{
			minu(as,bs,an,bn);
			lw = max(cn, lw);
			for(i=1;i<=lw-an;i++)
				printf(" ");
			printf("%s\n",a.c_str());
			
			for(i=1;i<=lw-bn - 1;i++)
				printf(" ");
			printf("-");
			printf("%s\n",b.c_str());
			
			
			for(i=1;i<=lw;i++)
				printf("-");
			printf("\n");
			
			for(i=1;i<=lw-cn;i++)
				printf(" ");
			for(i=0;i<cn;i++)
				printf("%c",c[cn - i - 1] + '0');
			printf("\n");
		}
		else
		{
			ansn = 1;
			memset(ans,0,sizeof(ans));
			for(i=0;i<bn;i++)
			{
				mult(as,an,bs[i]);
				if(cn == 1 && c[0] == 0)
					continue;
				memcpy(be,c,cn);
				memcpy(&c[i],be,cn);
				memset(c,0,i);
				memset(be,0,sizeof(be));
				memcpy(be,c,cn+i);
				add(ans,be,ansn,cn+i);
				/*for(j = 0;j < cn;j++)
					printf("%d",c[j]);
				printf("\n");
				printf("%d\n",cn);*/
				memcpy(ans,c,cn);
				ansn = cn;
			}
			lw = max(ansn, lw);
			
			for(i=1;i<=lw-an;i++)
				printf(" ");
			printf("%s\n",a.c_str());
			
			for(i=1;i<=lw-bn - 1;i++)
				printf(" ");
			printf("*");
			printf("%s\n",b.c_str());
			
			int ll = ansn;
			if(bn > 1)
			{
				
				for(i=1;i<=lw-lwab;i++)
					printf(" ");
				for(i=1;i<=lwab;i++)
					printf("-");
				printf("\n");
				
				for(i=0;i<bn;i++)
				{
					mult(as,an,bs[i]);
					for(j=1;j<=lw - cn - i;j++)
						printf(" ");
					for(j=0;j<cn;j++)
						printf("%c",c[cn - j - 1] + '0');
					printf("\n");
					
					ll = max(ll, cn+i);
				}
			}
			for(i=1;i<=lw - ll;i++)
				printf(" ");
			for(i=1;i<=ll;i++)
				printf("-");
			printf("\n");
			
			for(i=1;i<=lw-ansn;i++)
				printf(" ");
			for(i=0;i<ansn;i++)
				printf("%c",ans[ansn - i - 1] + '0');
			printf("\n");
			
		}
		if(k < t)
			printf("\n");
	}
	//while(1);
	return 0;
}

