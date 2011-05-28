#include<iostream>
#include<stdlib.h>
#define maxn 10007
using namespace std;

void Qsort(long *a,long l,long r)
{
    long i=l,j=r,m=a[(l+r)/2];
    do{
        while(a[i]<m) i++;
        while(a[j]>m) j--;
        if(i<=j)
        {
            long t=a[i];a[i]=a[j];a[j]=t;
            i++;j--;
        }
    }while(i<=j);
    if(l<j) Qsort(a,l,j);
    if(i<r) Qsort(a,i,r);
}

long n,ans,a[maxn],b[maxn];

int main()
{
    cin>>n;
    for(long i=1;i<=n;i++)
        cin>>a[i];
    for(long i=1;i<=n;i++)
        cin>>b[i];
    Qsort(a,1,n);
    Qsort(b,1,n);
    
    ans=0;
    for(long i=1;i<=n;i++)
        ans+=abs(a[i]-b[n-i+1]);
    
    cout<<ans<<endl;
return 0;
}
