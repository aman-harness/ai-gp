#include <iostream>
using namespace std;
int a[200][100][100]={0},b[100][100]={0},n,m;

/*
0 3 9
2 8 5
5 7 0
*/
int main(){
    int i,j,k,s;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            cin>>b[i][j];
    for(k=1;k<n+m;k++)
        for(i=1; i<=n;i++)
            for(j=1; j<=n;j++)
                if(i!=j && k-i>0 && k-i>0){
                a[k][i][j]=a[k-1][i-1][j-1];
                if(a[k-1][i][j-1]>a[k][i][j])
                a[k][i][j]=a[k-1][i][j-1];
                if(a[k-1][i-1][j]>a[k][i][j])
                a[k][i][j]=a[k-1][i-1][j];
                if(a[k-1][i][j]>a[k][i][j])
                a[k][i][j]=a[k-1][i][j];
                a[k][i][j]+=b[i][k-i]+b[j][k-j];
                }
    cout<<a[n+m-1][n][n-1];
    return 0;
}

