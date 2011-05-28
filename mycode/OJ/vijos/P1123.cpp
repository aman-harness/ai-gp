#include <iostream>
using namespace std;
int a[101]={0},out=0;
int sl[102]={0},sr[102]={0};
void work(int l,int r)
{
     if(l>=r)return;
     int i,j;
     bool t=1;
     if(a[l]>0){a[l+1]+=a[l];a[l++]=0;t=0;out++;}
     if(a[r]>0){a[r-1]+=a[r];a[r--]=0;t=0;out++;}
     if(t==0)work(l,r);
     else
     {
         memset(sl,0,sizeof(sl));
         memset(sr,0,sizeof(sr));
         
         for(i=l;i<=r;i++)sl[i]=sl[i-1]+a[i];
         for(i=l;i<=r;i++)sr[i]=sr[i+1]+a[i];
         for(i=l;i<=r;i++)
         {
             if(a[i]>0)
             {
             if(sl[i-1]+a[i]>=0)
             {
                 if(sl[i-1]+a[i]==0)out++;
                 else out+=2;
                 a[i]+=sl[i-1];
                 a[i-1]-=sl[i-1];
                 a[i+1]+=a[i];
                 a[i]=0;
                 work(l,i-1);
                 work(i+1,r);
                 return ;
             }
             else if(sr[i+1]+a[i]>=0)
             {
                 if(sr[i+1]+a[i]==0)out++;
                 else out+=2;
                 a[i]+=sr[i+1];
                 a[i+1]-=sr[i+1];
                 a[i-1]+=a[i];
                 a[i]=0;
                 work(l,i-1);
                 work(i+1,r);
                 return ;
             }
             }
         }
     }
             
}
/*0  16 4 0 29 15 0 0
  -8 8  -4-8 21 7 -8-8
*/

int main()
{
    int i,j,n,m,s,p;
    cin>>n;
    s=0;
    for(i=1;i<=n;i++){
                      cin>>a[i];
                      s+=a[i];
    }
    p = s/n;
    for(i=1;i<=n;i++)
    if(a[i]!=p){
                m=p-a[i];
                a[i+1]-=m;
                out++;
    }
    
    cout<<out;
    while(1);
    return 0;
}
