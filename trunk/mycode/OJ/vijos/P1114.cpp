#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int n,m;
string in,out; 
string expand(int x,int y){
       string a,b;
       if(y-x<=0){
           if(in[x]=='1')
           return "I";
           if(in[x]=='0')
           return "B";
       }
       a=expand(x,y-(y-x+1)/2);//0,7  0,3
       b=expand(x+(y-x+1)/2,y);//0,7  4,7
       
       //while(1);
       
       if(a[a.size()-1]=='I' && b[b.size()-1]=='I')
       return a+b+'I';
       else if(a[a.size()-1]=='B' && b[b.size()-1]=='B')
       return a+b+'B';
       else return a+b+'F';
}
       
int main(){
    int i,j;
    cin>>n;
    m = pow( 2.0 , n );
    cin>>in;
    out = expand( 0 , m-1 );
    cout<<out;
    return 0;
}
