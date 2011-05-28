#include <iostream>
using namespace std;

const int maxN = 40 + 1, maxM = 350 + 1;
int f[maxN][maxN][maxN][maxN] = {0};
int cn[4] = {0};
int s[maxM] = {0};
int n,m;

void init()
{
    int i,a;
    cin >> n >> m;
    for(i = 0; i < n; i ++)
        cin >> s[i];
    for(i = 0; i < m; i ++)
    {
        cin >> a;
        cn[a - 1] ++;
    }
}

int main()
{
    int i,j,k,l;
    init();
    for(i = 0; i <= cn[0]; i ++)
    for(j = 0; j <= cn[1]; j ++)
    for(k = 0; k <= cn[2]; k ++)
    for(l = 0; l <= cn[3]; l ++)
    {
        if(i > 0)
            f[i][j][k][l] = max(f[i][j][k][l], f[i - 1][j][k][l]);
        if(j > 0)
            f[i][j][k][l] = max(f[i][j][k][l], f[i][j - 1][k][l]);
        if(k > 0)
            f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k - 1][l]);
        if(l > 0)
            f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k][l - 1]);
        f[i][j][k][l] += s[i + j * 2 + k * 3 + l * 4];
    }
    cout << f[cn[0]][cn[1]][cn[2]][cn[3]] << endl;
    return 0;
}
