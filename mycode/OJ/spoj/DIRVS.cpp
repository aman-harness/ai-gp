/*
Problem:    Direct Visibility
Judge:      spoj
Author:     Alchemist
Data:       2011/5/28
Category:   BFS
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


void bfs()
{
    int i, newx, newy, step;
    qs = 0;
    qe = 1;
    q[qs] = s;
    q[qe].x = -1;
    q[qe].y = -1;
    step = 0;
    do
    {
        if(q[qs].x == e.x && q[qs].y == e.y)
        {
            ans = step;
            break;
        }
        if(q[qs].x == -1)
        {
            step ++;
            q[++qe].x = -1;
            q[qe].y = -1;
        }
        fi(4)
        {
            newx = dir[i].x + q[qs].x;
            newy = dir[i].y + q[qs].y;
            if(newx >= 0 && newx < n && newy >= 0 && newy < m && !vis[newx][newy] && f[newx][newy] >= f[q[qs].x][q[qs].y] - 3 && f[newx][newy] <= f[q[qs].x][q[qs].y] + 1)
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
    freopen("DIRVS.in","r");
    freopen("DIRVS.out","w");
    int i,t;
    t = ni();
    fi(t)
    {
        init();
        bfs();
        output();
    }
}
