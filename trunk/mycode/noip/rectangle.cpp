#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int maxn = 1000 + 1;
char ma[maxn][maxn] = {0};
int f[maxn][maxn] = {0};
int d[maxn][maxn] = {0};
int n,m;

int main()
{
    freopen("rectangle.in","r",stdin);
    freopen("rectangle.out","w",stdout);
    int i,j;

    cin >> n >> m;
    for(i = 1; i <= n; i ++)
    for(j = 1; j <= m; j ++)
    {
        scanf("%c", &ma[i][j]);
    }
    for(i = 1; i <= n; i ++)
    {
    for(j = 1; j <= m; j ++)
    {
        if(ma[i][j] == '.')
        {
            d[i][j] = d[i][j - 1] + 1;
            f[i][j] = d[i][j - 1] + f[i - 1][j] - f[i - 1][j - min(d[i-1][j] + 1, d[i][j-1]) - 1];
        }
        else
            d[i][j] = 0;
        cout << d[i][j] << ' ';
    }
     cout << endl;
    }

    long long s = 0;
    for(i = 1; i <= n; i ++)
    for(j = 1; j <= m; j ++)
        if(ma[i][j] == '.')
            s += f[i][j];
    cout << s << endl;
    return 0;
}
