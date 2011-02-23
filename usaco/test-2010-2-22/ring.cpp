/*
ID: Alchemist
PROG: ring
LANG: C++
DATA: 2011.02.22
ALGO: 
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <cmath>
#include <cstdio>
#include <queue>
#include <memory.h>
const int N=201000;
int a[N],sum[N];
int Q[N],I[N];//最小单调队列

int main()
{
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	int i, j, k;
    int t, n, m;
	scanf("%d", &t);
	for(i = 1; i <= t; i ++)
	{
		scanf("%d%d", &n, &m);
		for(j = 1; j <= n; j ++)
		{
			scanf("%d",&a[j]);
			sum[j] = sum[j-1] + a[j];
		}
		for(j = n + 1; j <= n + m; j ++)
		{
			a[j] = a[j - n];
			sum[j] = sum[j-1] + a[j];
		}
		
        int head=0,tail=-1;
        int _max=(1<<31);
        int maxH, maxL;
        for(j = 1; j <= n + m; j ++)//sum[j]-sum[i-1]的最大值
        {
            int k = j - 1;//sum[j-1]入队
            while(head <= tail && Q[tail] >= sum[k]) tail--;
            tail ++;
            Q[tail] = sum[k];
			I[tail] = k;
            k = j - m - 1;//sum[i]出队
            while(head <= tail && I[head] <= k) head ++;
            int _res = sum[j] - Q[head];
            if(_res > _max)
			{
				_max = _res;
				maxH = I[head] + 1;
				maxL = j;
			}
            else if(_res == _max)
            {
				if(I[head] + 1 < maxH)
				{
					maxH = I[head] + 1;
					maxL = j;
				}
				else if(I[head] + 1 == maxH)
				{
					if(j < maxL)
					{
						maxL = j;
					}
				}
			}
        }
        if(maxL > n)
        	maxL -= n;
		printf("%d %d %d\n",_max,maxH,maxL);
	}
    return 0;
}



