#include <iostream>
#include <cmath>
using namespace std;
double h,v,l,k,s; //n���� h��� v�ٶ� l���� k���� s���� 
int n;
int main(){
    int i,j,t = 0,all = 0;
    cin>>h>>s>>v>>l>>k>>n;
    for(i= ((n>s)?s:n) ; i >= 0; i--)
           if( ( sqrt(h/5)>(s-i)/v+0.000001 || sqrt(h/5)>(s-i)/v-0.000001) && (sqrt((h-l)/5) + 0.000001<(s+k-i)/v || sqrt((h-l)/5) - 0.000001<(s+k-i)/v)&& sqrt(h/5)>0)
               all++;
    cout<<all;
    while(1);
    return 0;
}
