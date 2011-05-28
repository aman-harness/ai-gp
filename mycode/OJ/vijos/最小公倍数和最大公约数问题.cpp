#include<stdio.h>
#include<math.h>
long gcd(long a,long b)
{
if(a==0)return b;
if(b==0)return a;
else if(a%2==0&&b%2==0)return 2*gcd(a/2,b/2);
else if(a%2==0)return gcd(a/2,b);
else if(b%2==0)return gcd(a,b/2);
else return gcd(a-b>0?a-b:b-a,a<b?a:b);
}
int main()
{
long x0,y0,sum=2,i,j,m;
scanf("%ld %ld",&x0,&y0);
if(y0%x0!=0){printf("0\n");return 0;}
j=y0/x0;m=sqrt(j);
for(i=2;i<=m;++i)
{
if(j%i==0)
{
if((j/i)%i==0);
else if(gcd(j/i,i)==1)
sum+=2;
}
}
printf("%ld\n",sum);
return 0;
}
