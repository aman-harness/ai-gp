#include <iostream>
#define MIN(x,y) (x>y)?y:x
#define DP_N 2
using namespace std;
int n,a[1001][1001],b[1001][1001],minNum,minI;
int main(){
    int i,j,k;
    cin>>n;
    for(i=1;i<=n;i++)
    for(j=1;j<=i;j++)
    {
    cin>>a[i][j];
    b[i][j]=a[i][j];
    }
    
    for(i=2;i<=n;i++)
    {
        a[i][1]+=MIN(a[i-1][1],a[i-1][i-1]);
        minNum = a[i][1];
        minI = 1;
        for(j=2;j<=i-1;j++)
        {
            if((a[i][j]+=MIN(a[i-1][j],a[i-1][j-1]))<minNum)
            {
                minNum=a[i][j];
                minI=j;
            }
        }
        if((a[i][i]+=MIN(a[i-1][1],a[i-1][i-1]))<minNum)
        {
            minNum=a[i][j];
            minI=i;
        }
        //2 DP
        for(k=1;k<=DP_N;k++){
        for(j=minI+1;j<=i;j++)
        {
            a[i][j]=MIN(b[i][j]+a[i][j-1],a[i][j]);
        }
        a[i][1]=MIN(b[i][1]+a[i][i],a[i][1]);
        for(j=2;j<=minI;j++)
        {
            a[i][j]=MIN(b[i][j]+a[i][j-1],a[i][j]);
        }
        }
        for(k=1;k<=DP_N;k++){
        for(j=minI-1;j>=1;j--)
        {
            a[i][j]=MIN(b[i][j]+a[i][j+1],a[i][j]);
        }
        a[i][i]=MIN(b[i][i]+a[i][1],a[i][i]);
        for(j=i-1;j>=minI;j--)
        {
            a[i][j]=MIN(b[i][j]+a[i][j+1],a[i][j]);
        }
        }
    }
    /*
    minNum = 2100000000;
    for(i=1;i<=n;i++)
    if(a[n][i]<minNum)
    minNum=a[n][i];
    */
    cout<<a[n][1];
    return 0;
    //while(1);
}
        
