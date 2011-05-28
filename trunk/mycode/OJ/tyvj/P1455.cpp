#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int maxN = 100 + 2;
double a[maxN][maxN] = {0};
double ans[maxN] = {0};
int ele[maxN] = {0};
int n;

void init()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
        ele[i] = i;
    for(int i = 1; i <= n; i ++)
    for(int j = 1; j <= n + 1; j ++)
        cin >> a[i][j];
}

void exchange(int x, int y)
{
    swap(ele[x],ele[y]);
    for(int i = 1; i <= n + 1; i ++)
        swap(a[x][i],a[y][i]);
}


int main()
{
    init();
    double d;
    //cout << fixed << setprecision(0);
    for(int i = 1; i < n; i ++)
    {
        if(a[i][i] == 0)
            for(int j = i + 1; j <= n; j ++)
                if(abs(a[j][i]) > 0.00001)
                {
                    exchange(i,j);
                    break;
                }
        for(int j = i + 1; j <= n; j ++)
        {
            if(a[j][i] == 0)
                continue;
            d = a[i][i]/a[j][i];
            for(int k = i; k <= n + 1; k ++)
            {
                a[j][k] *= d;
                a[j][k] -= a[i][k];
            }
        }
    }

    for(int i = n; i > 0; i --)
    {
        ans[i] = a[i][n+1] / a[i][i];
        for(int j = 1; j < i; j ++)
            a[j][n+1] -= a[j][i] * ans[i];
    }

    for(int i = 1; i < n; i ++)
        cout << int(round(ans[i])) << ' ';
    cout << int(round(ans[n])) << endl;
    return 0;
}
