#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxn = 1000 + 1;
int n, m;
int a[maxn][maxn] = {0};

int comp(const void* p, const void* q)
{
    return *((int*)p) - *((int*)q);
}

int main()
{
    freopen("matrix.in","r",stdin);
    freopen("matrix.out","w",stdout);
    int i,j,k;
    unsigned long long s = 0;
    cin >> n >> m;
    for(i = 1; i <= n; i ++)
    {
        for(j = 1; j <= n; j ++)
            scanf("%d",&a[i][j]);
        qsort(a[i] + 1, n , sizeof(a[0][0]),comp);
        for(j = 1; j <= n; j ++)
            cout << a[i][j] << ' ';
        cout << endl;
    }/*
    for(i = 0; i < n - 2; i ++)
    {
        k = n - 1;
        for(j = i + 1; j < n - 1; j ++)
        {
            while(a[k] + a[j] <= a[i] && k > j)
                k --;
            s += k - j;
        }
    }
    cout << s << endl;*/
    return 0;
}
