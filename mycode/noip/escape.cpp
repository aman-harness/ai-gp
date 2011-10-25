/*
Problem:    脱险
Assemble:   NOIP_moni_8
Anthor:     Alchemist
Date:       2011.10.21
Tag:        Search, Graph
Difficulty: ****
Description:
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxn = 13, maxt = 50;
int r,c,t;
int p[maxn * maxn][maxn * 4] = {0}, pn;
int o[maxn * 4] = {0}, on;
char ma[13][13] = {0};

void bfs()
{

}


int comp(const void* p, const void* q)
{
    return *((int*)q) - *((int*)p);
}

int main()
{
    freopen("escape.in","r",stdin);
    freopen("escape.out","w",stdout);
    int i,j,k;
    unsigned long long s = 0;
    cin >> r >> c >> t;
    for(i = 1; i <= r; i ++)
    for(j = 1; j <= c; j ++)
        cin >> ma[i][j];
    for(i = 0; i < n - 2; i ++)
    {
        k = n - 1;
        for(j = i + 1; j < n - 1; j ++)
        {
            while(a[k] + a[j] <= a[i] && k > j)
                k --;
            s += k - j;
        }
    }
    cout << s << endl;
    return 0;
}
