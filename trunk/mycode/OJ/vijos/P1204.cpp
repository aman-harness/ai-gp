#include <iostream>
using namespace std;
bool a[100][100];
int n,m,all=0;
int main(){
    int i,j,s,maxN=0,maxI=-1,maxJ=-1;
    cin>>n>>m;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            cin>>a[i][j];
    while(1){
    for(i=0;i<n;i++)
    {
        s = 0;
        for(j=0;j<m;j++)
            s+=a[i][j];
        if(s>maxN)
        {
            maxN = s;
            maxI = i;
            maxJ = -1;
        }
    }
    for(j=0;j<m;j++)
    {
        s = 0;
        for(i=0;i<n;i++)
            s+=a[i][j];
        if(s>maxN)
        {
            maxN = s;
            maxJ = j; 
            maxI = -1;
        }   
    }
    if(maxJ == -1){
        for(i=0;i<m;i++)
            a[maxI][i]=0;
    }
    else if(maxI == -1){
        for(i=0;i<n;i++)
            a[i][maxJ]=0;
    }
    all++;
    maxN=maxI=maxJ=0;
    if(maxN == 0)
    break;
    }
    cout<<all;
    while(1);
    return 0;
}
