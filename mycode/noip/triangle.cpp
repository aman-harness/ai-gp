/*
Problem:    Triangle
Assemble:   NOIP_moni_7
Anthor:     Alchemist
Date:       2011.10.20
Tag:        Simulation, Math
Difficulty: **
Description:
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxn = 7000 + 1;
int n;
int a[maxn] = {0};

int comp(const void* p, const void* q)
{
    return *((int*)q) - *((int*)p);
}

int main()
{
    freopen("triangle.in","r",stdin);
    freopen("triangle.out","w",stdout);
    int i,j,k;
    unsigned long long s;
    cin >> n;
    for(i = 0; i < n; i ++)
        scanf("%d",&a[i]);
    qsort(a,n,sizeof(a[0]),comp);
    s = 0;
    for(i = 0; i < n - 2; i ++)
    {
        k = n - 1;
        for(j = i + 1; j < k; j ++)
        {
            while(a[k] + a[j] <= a[i] && k > j)
                k --;
            s += k - j;
            //cout << i << ' ' << j << ' ' << k << ' ' << s << endl;
        }
    }
    cout << s << endl;
    return 0;
}
