#include <cstdio>
int main()
{
double ans=0;
int i=0,n=0;
scanf("%d",&n);
for(i=1;i<=n;i++) ans=ans+i*i;
printf("%.0lf",ans);
return 0;
}
