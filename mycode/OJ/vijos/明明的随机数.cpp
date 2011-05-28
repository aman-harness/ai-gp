#include <stdio.h>
#include <conio.h>
main()
{
 int pd[1001]={0};
 int i,t,n,ans=0;
 scanf("%d",&n);
 for(i=1;i<=n;i++)
{
   scanf("%d",&t);
   if(!pd[t]) ans++;
pd[t]=1;
}
printf("%d\n",ans);
for(i=1;i<=1000;i++)
 if(pd[i])
printf("%d ",i);
}
