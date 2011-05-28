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
//ifstream cin("live.in");
//ofstream cout("live.out");
const int maxN = 100000 + 1;
int n,m;
int a[maxN] = {0};

int comp(const void* p,const void* q)
{
	return *(int*)p - *(int*)q;
}

inline int divide(int x1,int x2)
{
	int mid,l,r;
	l = 0;
	r = n-1;
	while(l < r)
	{
		mid = (l + r) / 2;
		if(a[mid] < x1)
			l = mid + 1;
		else if(a[mid] > x2)
			r = mid - 1;
		else
			return mid;
	}
	return mid;
}

int main()
{
	int i,j,k,x1,x2,y1,y2,y,ax;
	cin >> n;
	for(i=0;i<n;i++)
		cin >> a[i];
	qsort(a,n,sizeof(int),comp);
	
	cin >> m;
	for(i=0;i<m;i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		y = abs(y1 - y2);
		if(x1 - x2 > 0)
		{
			x2 += x1;
			x1 = x2 - x1;
			x2 -= x1;
		}
		
		if((y1 > 0 && y2 < 0) || (y1 < 0 && y2 > 0))
		{
			 
			j = divide(x1,x2);
			if(x1 <= a[j] && a[j] <= x2)
			{
				cout << x2 - x1 + y;
			}
			else if(a[j] < x1)
			{
				ax = a[j+1] - x2;
				if(ax > x1 - a[j])
					ax = x1 - a[j];
				cout << ax * 2 + y + x2 - x1;
			}
			else if(a[j] > x2)
			{
				ax = x1 - a[j-1];
				if(ax > a[j] - x2)
					ax = a[j] - x2;
				cout << ax * 2 + y + x2 - x1;
			}
		}
		else if(y1 == 0 && y2 == 0)
		{
			if(x2 - x1 == 1)
				cout << x2 - x1;
			else
			{
				j = divide(x1,x1);
				while(a[j] <= x1) j ++;
				k = divide(x2,x2);
				while(a[k] >= x2) k --;
				
				if(x2 - x1 == k - j + 2)
				{
					cout << x2 - x1;
				}
				else
				{
					cout << x2 - x1 + 2;
				}
			}
		}
		else
		{
			cout << x2 - x1 + y;
		}
		cout << endl;
	}
	return 0;
}
