#include <iostream>
using namespace std;
int s[100000]={0};
int main(){
    int n,i,j,x,y;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>x;
        if(i==1)y=x;
        s[x+i]=1;
    }
    x=x+n;
    i=y+1;
    while(i<=x){
        if(s[i]==1){
            j=i-1;
            while(s[j]!=0)j--;
            cout<<(i-j+1)/2<<' ';
            s[j]=-1;
        }
        i++;
    }
    while(1);
    return 0;
}
/*
1 2 3 4 5 6
111121212222
*/
