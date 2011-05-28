#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int i,j,s,w,all=0;
    bool l[100001]={0};
    int a,b;
    cin>>a>>b;
    for(j=a;j<=b;j++)
    {
    //if(l[j - a]==1)continue;
    s=1;
    for(i=2;i<sqrt(j);i++)
    {
        if(j%i==0)
            s+=i+j/i;
        if( s > b ) break;
    }
    if(i==sqrt(j))
    s+=i;
    if( s!=j ){
        if(s>=a)
        if(l[s-a]==1)continue;
        w=1;
        for(i=2;i<sqrt(s);i++)
        {
        if(s%i==0)
            w+=i+s/i;
        if( w > b ) break;
        }
        if(i==sqrt(w))
        w+=i;
        if( w <= b )
        if(w == j)all++;
    }
    l[j-a]=1;
    }
    if(all==1)cout<<0;
    else cout << all;
    //while(1);
    return 0;
}
