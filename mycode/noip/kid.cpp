/*
Problem:    Kid
Assemble:   NOIP_moni_7
Anthor:     Alchemist
Date:       2011.10.21
Tag:        Dynamic Programme
Difficulty: ***
Description:
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxn = 1000 + 2;
int n;
int a[maxn] = {0};
int f[maxn][maxn] = {0};

int main()
{
    freopen("kid.in","r",stdin);
    freopen("kid.out","w",stdout);
    int i,j,l,r;
    cin >> n;
    for(i = 1; i <= n; i ++)
        scanf("%d",&a[i]);
    for(i = 1; i <= n; i ++)
        f[i][i] -= a[i];

    for(i = 2; i <= n; i ++)
    for(j = 1; j <= n - i + 1; j ++)
    {
        l = j;
        r = i + j - 1;
        if(i % 2 == 1)
        {
            f[l][r] = 0x80000000;
            //cout << f[l][r] << endl;
            //cout << f[l + 1][r] - a[l] << 's' << f[l][r - 1] - a[r] << endl;
            if(a[l] > a[r + 1])
                f[l][r] = max(f[l + 1][r] - a[l],f[l][r]);
            if(a[r] > a[l - 1])
                f[l][r] = max(f[l][r - 1] - a[r],f[l][r]);
        }
        else
        {
            f[l][r] = max(f[l + 1][r] + a[l], f[l][r - 1] + a[r]);
        }
        //cout << l << ' ' << r << ' ' << f[l][r] << endl;
    }
    cout << f[1][n] << endl;
    return 0;
}
