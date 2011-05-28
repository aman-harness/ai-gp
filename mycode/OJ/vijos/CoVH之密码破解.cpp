#include <iostream>

using namespace std;

int a[8];
main()
{
int i=0,n;
cin>>n;
a[0]=1;
for (i=1;i<=8;i++) a[i]=a[i-1]*10;
int s=0,t=0;
i=0;
while (i<n)
{
s++;
if (s==a[t+1]) t++;
i=i+t+1;
}
while (i>=n)
{
int k=s%10;
s=s/10;
if (i==n) 
{
cout<<k;break;
}
i--;
}
}

