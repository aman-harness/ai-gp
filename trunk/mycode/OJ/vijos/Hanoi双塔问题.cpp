#include<iostream>
using namespace std;
int shu[300],t,n=1;
int main(){
    int a,i,j,t,b;
    cin>>a;
    shu[0]=1;
    for(i=2;i<=a;i++){
        t=0;
        for(j=0;j<n;j++){
            b=(shu[j]*2+t)/10;
            shu[j]=(shu[j]*2+t)%10;
            t=b;
        }
        shu[0]++;
        j=0;
        while(shu[j]>9){shu[j]=0;shu[j+1]++;}
        shu[n]=t;
        if(t==1)
        n++;
    } 
    t=0;
    for(j=0;j<n;j++){
            b=(shu[j]*2+t)/10;
            shu[j]=(shu[j]*2+t)%10;
            t=b;
        }
    shu[n]=t;
    if(t==1)
    n++;
    for(i=n-1;i>=0;i--)
    cout<<shu[i];
    system("pause");
    return 0;
}
