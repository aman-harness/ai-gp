#include <iostream>
#include <iomanip>
using namespace std;
unsigned long long a,b;
int main(){
    int i=0;
    a=2;b=1;
    long double x1,x2;
    while(i<=50){
    a+=b;
    b=a-b;
    x1=a;x2=b;
    cout<<a<<' '<<b<<' '<<setprecision(20)<<x1/x2<<endl;
    i++; 
    }
    while(1);
    return 0;
}
