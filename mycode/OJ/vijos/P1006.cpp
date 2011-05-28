#include <iostream>
using namespace std;
int hill[100][100]={0},n;
int ArrayMin(int a[]){
    int i,minNum=1000;
    for(i=0;a[i]!=-1;i++){
        if(a[i]<minNum)
            minNum=a[i];
        a[i]=0;
    }
    return minNum;
}
int main(){
    int i,j,way[8]={5,2,2,3,4,5,-1,1};
    cout<<ArrayMin(way);
    cin>>n;
    for(i=0;i<n;i++)
        for(j=0;j<=i;j++)
            cin>>hill[i][j];
    for(i=n-2;i>=1;i--){
        for(j=0;j<=i;j++){
            if(j==i){
            way[0]=hill[i+1][j];
            way[1]=hill[i+1][j+1];
            way[2]=hill[i][j-1];
            way[3]=hill[i][0];
            way[4]=hill[i+1][0];
            way[5]=-1;
            }
            else if(j==0)
            {
            way[0]=hill[i+1][j];
            way[1]=hill[i+1][j+1];
            way[2]=hill[i+1][i+1];
            way[3]=hill[i][i];
            way[4]=hill[i][j+1];
            way[5]=-1;
            }
            else{
            way[0]=hill[i+1][j];
            way[1]=hill[i+1][j+1];
            way[2]=hill[i][j-1];
            way[3]=hill[i][j+1];
            way[4]=-1;
            }
            hill[i][j]+=ArrayMin(way);
            cout<<hill[i][j]<<' ';
        }
        cout<<endl;
    }
    if(hill[1][0]<hill[1][1])
    cout<<hill[1][0]+hill[0][0];
    else cout<<hill[1][1]+hill[0][0];
    while(1);
    return 0;
}
    
