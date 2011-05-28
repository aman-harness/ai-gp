/*
from http://hi.baidu.com/xiszishu/blog/
*/
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
long long int ans,i,j,n,a[5001],f[5001];
void solve()
{
     long long i,j;
     cin>>n;
     f[1]=1;
     for (i=1;i<=n;i++)
     {
         cin>>a[i];
         f[i]=1;
     }
     ans=0;
     for (i=1;i<=n;i++)
     {
         for (j=1;j<=i-1;j++)
         if ((a[i]>=a[j])&&(f[i]<=f[j]+1))
         f[i]=f[j]+1;
         if (f[i]>ans) ans=f[i];
     }
     cout<<ans<<endl;
}
int main(int argc, char *argv[])
{
    solve();
    return 0;
}