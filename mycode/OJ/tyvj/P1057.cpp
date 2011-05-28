#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 3200 + 1, maxm = 60 + 1;

int f[maxm][maxn] = {0};
int v[maxm][3] = {0};
int w[maxm][3] = {0};
int n, m;

void init()
{
    cin >> n >> m;
    n /= 10;
    int a, b, c, i, sm;
    for (i = 1; i <= m; i ++)
    {
        cin >> a >> b >> c;
        a /= 10;
        if(c == 0)
        {
            v[i][0] = a;
            w[i][0] = b;
        }
        else
        {
            if(w[c][1] == 0)
            {
                v[c][1] = a;
                w[c][1] = b;
            }
            else
            {
                v[c][2] = a;
                w[c][2] = b;
            }
        }
    }
    sm = 1;
    for(i = 1; i <= m; i ++)
    {
        if(w[i][0] > 0)
        {
            memcpy(v[sm], v[i], sizeof(v[i]));
            memcpy(w[sm ++], w[i], sizeof(w[i]));
        }
    }
    m = sm - 1;
}

int main()
{
	int i,j,k;
    init();

    for (i = 1; i <= m; i ++)
    {
        for (j = 1; j <= n; j ++)
        {
            f[i][j] = f[i][j - 1];
            if(v[i][0] <= j)
            {
                f[i][j] = max(f[i - 1][j - v[i][0]] + w[i][0] * v[i][0], f[i][j]);
                if(v[i][0] + v[i][1] <= j)
                    f[i][j] = max(f[i - 1][j - v[i][0] - v[i][1]] + w[i][0] * v[i][0] + w[i][1] * v[i][1], f[i][j]);
                if(v[i][0] + v[i][2] <= j)
                    f[i][j] = max(f[i - 1][j - v[i][0] - v[i][2]] + w[i][0] * v[i][0] + w[i][2] * v[i][2], f[i][j]);
                if(v[i][0] + v[i][1] + v[i][2] <= j)
                    f[i][j] = max(f[i - 1][j - v[i][0] - v[i][1] - v[i][2]] + w[i][0] * v[i][0] + w[i][1] * v[i][1] + w[i][2] * v[i][2], f[i][j]);
            }
        }
    }
    cout << f[m][n] * 10 << endl;
	return 0;
}
