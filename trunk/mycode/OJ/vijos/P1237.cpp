#include <iostream>
#include <cmath>
#define MAX 100000
#define N 30000
#define GOLD 0.6180339887498949
using namespace std;
int a[N+10]={0},minl,minr;
long double minc=1,dl,dr;
bool t[MAX]={0};
int n;

int main(){
    int i,j;
    int l,r;
    long double x;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        t[a[i]]=1;
    }
    n=1;
    memset(a,0,sizeof(a));
    for(i=1;i<=MAX;i++)
        if( t[i]==1 )
        a[n++]=i;
    n--;
    for(i=1;i<=n-1;i++)
    {
        l=i+1;
        r=n;
        x=a[i]/GOLD;
        while(l<r)
        {
            if( a[ (l+r)/2 ] > x )
            r = (l+r)/2-1;
            else
            l = (l+r)/2+1;
            
        }
        dl=a[i];
        dr=a[r];
        if(abs(dl/dr-GOLD)<minc)
        {
            minc = abs(dl/dr-GOLD);
            minl = a[i];
            minr = a[r];
        }
        dl=a[i];
        dr=a[l];
        if(abs(dl/dr-GOLD)<minc)
        {
            minc = abs(dl/dr-GOLD);
            minl = a[i];
            minr = a[l];
        }
    }
    cout<<minl<<endl<<minr;
    //while(1);
    return 0;
}
/*
10
1 2 3 4 5 6 7 8 9 10
*/
