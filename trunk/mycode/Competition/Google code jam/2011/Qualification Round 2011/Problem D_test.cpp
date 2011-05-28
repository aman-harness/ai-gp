#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
using namespace std;

int main()
{
    int i,j;
    long double x,d,e;
    e = 0.33333333333;
    d = 1.66666666667;
    //cin >> t;
    x = 0.0;
    for(i = 1; i <= 100; i ++)
    {
        x = x * e + d;
        cout << fixed << setprecision(6) << x << endl;
    }
    cout << fixed << setprecision(6) << x << endl;
    return 0;
}
