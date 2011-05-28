#include <stdio.h>

main()
{
 char c[100];
 char p;
 int i,j;
 int l;
 int k,tmp;
 int a,b;
 int flag;
 double ans;
 
 scanf("%s",&c);
 for(i=0;i<100;i++)
 {
if((c[i]>='a' && c[i]<='z') || (c[i]>='A' && c[i]<='Z'))
  p=c[i];
if(c[i]=='\0')
  break;
 }
 l=i+1;
 //ax+b=0
 a=0;b=0;k=0;flag=1;
 for(i=0;i<l;i++)
 {
if(c[i] == '+')
{
  b+=k*flag;
  k=0;
  flag=1;
}
if(c[i] == '-')
{
  b+=k*flag;
  k=0;
  flag=flag*(-1);
}
if(c[i] >= '0' && c[i] <= '9')
{
  k=k*10+(c[i]-'0');
}
if(c[i] == p)
{
  if(k==0)
  {
k=1;
  }
  a+=k*flag;
  k=0;
  flag=1;
}
if(c[i]=='=')
{
  b+=k*flag;
  k=0;
  flag=1;
  a=-a;
  b=-b;
}
 }
 b+=k*flag;
 ans=(double)b*(-1)/(double)a;
 printf("%c=%.3f",p,ans);
 return 0;
}
