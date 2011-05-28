#include<stdio.h>
main()
{
int n,i;
int f[1000]={1,1};
scanf("%d",&n);
for(i=1;i<=n;i++)
{
if(i%2==1)
f[i]=f[i-1];
else
f[i]=f[i/2]+f[i-1];
}
printf("%d",f[n]);
}
