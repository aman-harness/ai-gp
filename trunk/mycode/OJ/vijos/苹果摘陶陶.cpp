#include<stdio.h>

main()
{
int i,j,m1,n,m,max=0,k,x=0,s=0;
scanf("%d %d",&n,&m);
m1=m;
int a[n+1],t[m+1];
for(i=1;i<=n;i++)
scanf("%d",&a[i]);
for(j=1;j<=m;j++)
scanf("%d",&t[j]);
for(i=1;i<=n;i++){
for(j=1;j<=m;j++)
if(a[i]>t[j]&&t[j]>max) {max=t[j];k=j;x=1;}
t[k]=9999;max=0;if(x==1) s++; x=0;}
printf("%d",m-s);
}
