#include <iostream>
#include <ctime>
using namespace std;
int main(){
    clock_t a,b;
    register int i;
    a=clock();
    for(i=1;i<=100000000;i++){i++;}
    b=clock();
    cout<<b-a;
    while(1);
    return 0;
}
     
