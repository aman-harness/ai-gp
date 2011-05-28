#include <iostream>
using namespace std;
int n,m,l[50001],r[50001],d[50001];
struct lion{
       int a;
       int qy;
}a[100001];

int compare( const void* p, const void* q)
{
    return ((lion*)p)->a - ((lion*)q)->a;
}   
int main(){
    int i,j,s;
    cin>>n>>m;
    for ( i = 1 ;i <= n ; i++){
        cin>>a[i].a;
        a[i].qy = i;
    }
    qsort( a , n+1, sizeof(lion) , compare);
    //for( j = 1 ;j <= n ;j++)cout<<a[j].a<<' '<<a[j].qy <<endl;
    for( i = 1 ;i <= m ;i++)cin>>l[i]>>r[i]>>d[i];
    for( i = 1 ;i <= m ; i++)
    {
         s = 0;
         for( j = 1 ;j <= n && s < d[i] ;j++)
         {
              if( l[i] <= a[j].qy && a[j].qy <= r[i])
                  s++;
         }
         cout<<a[j-1].a<<endl;
    }
    //while(1);
    return 0;
}
