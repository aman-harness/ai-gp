#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double a,b,p;
    int i;
    cin>>a>>b;
    for(i=1;1;i++){
        p = b-(100.0 / i)* int(b / (100.0 / i));
        if(p > 0 && (b - a - p > 0) ){
            cout<<i;
            return 0;
        }
    }
    return 0;
}

