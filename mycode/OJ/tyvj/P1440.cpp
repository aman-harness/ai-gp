#include<stdio.h>
#include<iostream>
using namespace std;
int n,len=1,s[2000]={0},sum[2000]={0};
void fbi(int begin,int end)
{
    int mid=(begin+end)/2;
    if(begin<end)
    {
       fbi(begin,mid);
       fbi(mid+1,end);
    }
    if(sum[end]-sum[begin-1]==end-begin+1)
       printf("%c",'I');
    else if(sum[end]-sum[begin-1]==0)
       printf("%c",'B');
 else
       printf("%c",'F');
}
int main()
{
 int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      len*=2;
    for(i=1;i<=len;i++)
      scanf("%1d",&s[i]);
    for(i=1;i<=len;i++)
      sum[i]=sum[i-1]+s[i];
    fbi(1,len);
return 0;
}
