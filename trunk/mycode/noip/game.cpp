/*
Problem:    连线游戏
Assemble:   NOIP_moni_9
Anthor:     Alchemist
Date:       2011.10.21
Tag:        Geometry
Difficulty: *
Description:
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int maxn = 200 + 1;
const double INF = 1e20;
struct point
{
    double x,y;
}p[maxn];
int n;

void init()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> p[i].x >> p[i].y;
}

double a[maxn * maxn] = {0};
int an = 0;

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    init();

    for(int i = 0; i < n; i ++)
        for(int j = i + 1; j < n; j ++)
        {
            if(p[i].x - p[j].x == 0)
                a[an ++] = INF;
            else
                a[an ++] = (p[i].y - p[j].y) / (p[i].x - p[j].x);
        }

    sort(&a[0],&a[an]);
    int s = 0;
    for(int i = 0; i < an; i ++)
        if(a[i] != a[i + 1])
          s ++;
    cout << s << endl;
    return 0;
}
