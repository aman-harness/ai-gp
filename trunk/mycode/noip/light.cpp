#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int n;

int main()
{
    freopen("light.in","r",stdin);
    freopen("light.out","w",stdout);
    int i,j;
    double a;
    int t;
    int yh = 0;
    cin >> n;
    for(i = 0; i < n; i ++)
    {
        cin >> a >> t;
        for(j = 1; j <= t; j ++)
            yh ^= int(a * j);
    }
    cout << yh << endl;
    return 0;
}
