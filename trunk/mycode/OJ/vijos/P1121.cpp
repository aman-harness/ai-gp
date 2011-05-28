#include <iostream>
using namespace std;
long long a[16][16];
int n,m,x,y;       
int main(){
    int i,j,ii,jj;
    cin>>n>>m>>x>>y;
    for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)
            a[i][j] = -1;
    a[0][0]=1;
    //for(i=0;i<=n;i++)a[i][0]=1;
    //for(i=0;i<=m;i++)a[0][i]=1;
    a[x][y]=0;
    if( x+2<=n && y+1<=m ) a[x+2][y+1]=0;
    if( x+1<=n && y+2<=m ) a[x+1][y+2]=0;
    if( x+2<=n && y-1>=0 ) a[x+2][y-1]=0;
    if( x+1<=n && y-2>=0 ) a[x+1][y-2]=0;
    if( x-2>=0 && y+1<=m ) a[x-2][y+1]=0;
    if( x-1>=0 && y+2<=m ) a[x-1][y+2]=0;
    if( x-2>=0 && y-1>=0 ) a[x-2][y-1]=0;
    if( x-1>=0 && y-2>=0 ) a[x-1][y-2]=0;
    
    for(ii=1;ii<=m+n+1;ii++)
        for(jj=0;jj<=ii;jj++){
            i=ii-jj;
            j=jj;
            
            if(i<=n && j<=m && a[i][j]==-1){
                    if(i-1<0)a[i][j]=a[i][j-1];
                    else if(j-1<0)a[i][j]=a[i-1][j];
                    else a[i][j]=a[i-1][j]+a[i][j-1];
            }
            //else a[i][j]=0;
        }
    /*
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    */
    if(a[n][m]==-1)
    cout<<0;
    else
    cout<<a[n][m];
    //while(1);
    return 0;
}
