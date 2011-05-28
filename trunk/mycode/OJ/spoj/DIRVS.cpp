/*
Problem:    Direct Visibility
Judge:      spoj
Author:     Alchemist
Data:       2011/5/28
Category:   BFS
Difficulty: ***
*/
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <math.h>

#define fo(a,b,c) for( a = ( b ); a < ( c ); ++ a )
#define fr(a,b) fo( a, 0, ( b ) )
#define fi(a) fr( i, ( a ) )
#define fj(a) fr( j, ( a ) )
#define fk(a) fr( k, ( a ) )
#define mp make_pair
#define pb push_back
#define all(v) (v).begin( ), (v).end( )
#define _(a,b) memset( a, b, sizeof( a ) )
using namespace std;
int ni() { int a; scanf( "%d", &a ); return a; }
double nf() { double a; scanf( "%lf", &a ); return a; }
char sbuf[100005]; string ns() { scanf( "%s", sbuf ); return sbuf; }
long long nll() { long long a; scanf( "%lld", &a ); return a; }

template <class T> void out( T a, T b ) { bool first = true; for( T i = a; i != b; ++ i ) { if( !first ) printf( " " ); first = false; cout << * i; } printf( "\n" ); }
template <class T> void outl( T a, T b ) { for( T i = a; i != b; ++ i ) { cout << * i << "\n"; } }
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef map<string,int> msi;

/* main */

struct point
{
    int x, y;
}s,e;

const int maxn = 200;
const point dir[4] = {0,1,1,0,-1,0,0,-1};

int f[maxn][maxn] = {0};
bool vis[maxn][maxn] = {0};
point q[maxn * maxn] = {0};
int qs, qe;
int n, m;
int ans;

bool visible(point p, point o)
{

    double x1, y1, z1, x2, y2, z2, ys, xs, zs, newx, newy, newz;
    x1 = p.x + 0.5;
    y1 = p.y + 0.5;
    z1 = f[p.x][p.y] + 0.5;
    x2 = o.x + 0.5;
    y2 = o.y + 0.5;
    z2 = f[o.x][o.y] + 0.5;

    //x
    if(x2 - x1 != 0)
    {
        ys = (y2 - y1)/(x2 - x1);
        zs = (z2 - z1)/(x2 - x1);

        int i,l,r;
        if(p.x < o.x)
        {
            l = p.x;
            r = o.x;
        }
        else
        {
            l = o.x;
            r = p.x;
        }
        fo(i, l, r)
        {
            newy = (0.5 + i - x1)*ys + y1;
            newz = (0.5 + i - x1)*zs + z1;
            if(!((f[i][int(newy)] <= newz && f[i+1][int(newy)] <= newz) || newy == double(int(newy))))
            {
                return 0;
            }
        }
    }

    if(y2 - y1 != 0)
    {
        xs = (x2 - x1)/(y2 - y1);
        zs = (z2 - z1)/(y2 - y1);

        int i,l,r;
        if(p.y < o.y)
        {
            l = p.y;
            r = o.y;
        }
        else
        {
            l = o.y;
            r = p.y;
        }
        fo(i, l, r)
        {
            newx = (0.5 + i - y1) * xs + x1;
            newz = (0.5 + i - y1) * zs + z1;
            if(!((f[int(newx)][i] <= newz && f[int(newx)][i+1] <= newz) || newx == double(int(newx))))
            {
                return 0;
            }
        }
    }
    return 1;
}

bool visible(point p)
{
    if(visible(p, s) || visible(p, e))
        return true;
    else
    {
        vis[p.x][p.y] = 1;
        return false;
    }
}

void bfs()
{
    int i, newx, newy, step;
    point newp;
    qs = 0;
    qe = 1;
    q[qs] = s;
    q[qe].x = -1;
    q[qe].y = -1;
    step = 0;
    do
    {
        if(q[qs].x == -1)
        {
            step ++;
            q[++qe].x = -1;
            q[qe].y = -1;
            qs ++;
        }
        cout << q[qs].x << ' ' << q[qs].y << endl;
        if(q[qs].x == e.x && q[qs].y == e.y)
        {
            ans = step;
            break;
        }
        fi(4)
        {
            newx = dir[i].x + q[qs].x;
            newy = dir[i].y + q[qs].y;
            newp.x = newx;
            newp.y = newy;
            if(newx >= 0 && newx < n && newy >= 0 && newy < m && !vis[newx][newy] && f[newx][newy] >= f[q[qs].x][q[qs].y] - 3 && f[newx][newy] <= f[q[qs].x][q[qs].y] + 1 && visible(newp))
            {
                q[++qe].x = newx;
                q[qe].y = newy;
                vis[newx][newy] = true;
            }
        }
        qs ++;
    }while(qs <= qe);
}

void init()
{
    int i, j;
    n = ni();
    m = ni();

    fi(n)
        fj(m)
            f[i][j] = ni();

    s.x = ni() - 1;
    s.y = ni() - 1;
    e.x = ni() - 1;
    e.y = ni() - 1;

    _(vis, 0);
    ans = -1;
}

void output()
{
    if(ans > 0)
        printf("The shortest path is %d steps long.\n", ans);
    else
        printf("Mission impossible!\n");
}

int main()
{
    freopen("DIRVS.in", "r", stdin);
    freopen("DIRVS.out", "w", stdout);
    int i,t;
    t = ni();
    fi(t)
    {
        init();
        bfs();
        output();
    }
}
