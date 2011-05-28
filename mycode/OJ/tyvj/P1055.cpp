#include <cstdlib>
#include <iostream>
#include <stdio.h>
using namespace std;
int n,t[1001],f[1001][1001],sum[1001];
void readdata()
{
     int i,j;
     scanf("%d\n",&n);
     for (i=1;i<=n;i++)
     scanf("%d",&t[i]);
     for (i=1;i<=n;i++)
     for (j=i;j<=n;j++)
     f[i][j]=-1;
     for (i=1;i<=n;i++)
     {
         sum[i]=sum[i-1]+t[i];
         f[i][i]=0;
     }

}
int dp(int l,int r)
{
    int i,ans,t;
    if (f[l][r]>=0) return f[l][r];
    ans=0x7fffffff;
    for (i=l;i<=r-1;i++)
    {
        t=dp(l,i)+dp(i+1,r)+sum[r]-sum[l-1];
        if (ans>t) ans=t;
    }
    f[l][r]=ans;
    return f[l][r];
}
void solve()
{
     int i,j;
     dp(1,n);
     printf("%d\n",f[1][n]);
}
int main(int argc, char *argv[])
{
    readdata();
    solve();
    return 0;
}
