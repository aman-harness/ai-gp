/*
Problem:    208. Store-keeper
Judge:      spoj
Author:     Alchemist
Date:       2011/8/4
Category:   BFS
Difficulty: **
Desc:       It's just like the game Sokoban.
*/
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <cmath>

#define fo(a,b,c) for( a = ( b ); a < ( c ); ++ a )
#define fr(a,b) fo( a, 0, ( b ) )
#define fi(a) fr( i, ( a ) )
#define fj(a) fr( j, ( a ) )
#define fk(a) fr( k, ( a ) )
#define mp make_pair
#define pb push_back
#define all(v) (v).begin( ), (v).end( )
#define _(a,b) memset( a, b, sizeof( a ) )
#define PI 3.1415926
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
const int maxn = 100 + 2;
const int dir[4][2] = {0,1,1,0,-1,0,0,-1};
const int cdir[4][2] = {0,-1,-1,0,1,0,0,1};
bool vis[maxn][maxn][4] = {0};
struct node
{
    int x,y;
    int d,step;
}q[maxn * maxn * 4] = {0};
char mymap[maxn][maxn] = {0};
int head, tail;
int n, m;
int px, py;
int mx, my;

void init()
{
    _(vis,0);
    _(mymap,'S');
    head = 0;
    tail = 0;
}


bool cvis[maxn][maxn];

void floodfill(int x, int y, int mx, int my)
{
    int i;
    cvis[x][y] = true;
    fi(4)
    {
        int nx, ny;
        nx = x + dir[i][0];
        ny = y + dir[i][1];
        if(mymap[nx][ny] != 'S' && !cvis[nx][ny] && !(nx == mx && ny == my))
            floodfill(nx, ny, mx, my);
    }
}

int ans;

void bfs()
{
    int i, npx, npy, nmx, nmy, x, y, cx, cy;

    _(cvis,0);
    floodfill(mx, my, px, py);

    fi(4)
    {
        if(cvis[px + dir[i][0]][py + dir[i][1]])
        {
            q[head].x = px;
            q[head].y = py;
            q[head].step = 0;
            q[head ++].d = i;
            vis[px][py][i] = true;
            break;
        }
    }

    while(head > tail)
    {
        npx = q[tail].x;
        npy = q[tail].y;
        nmx = npx + dir[q[tail].d][0];
        nmy = npy + dir[q[tail].d][1];

        //cout << npx << ',' << npy << ' ' << nmx << ',' << nmy << endl;

        if(mymap[npx][npy] == 'K')
        {
            ans = q[tail].step;
            break;
        }

        _(cvis,0);
        floodfill(nmx, nmy, npx, npy);

        fi(4)
        {
            x = npx + dir[i][0];
            y = npy + dir[i][1];
            cx = npx + cdir[i][0];
            cy = npy + cdir[i][1];
            if(cvis[x][y] && !vis[cx][cy][i] && mymap[cx][cy] != 'S' )
            {
                q[head].x = cx;
                q[head].y = cy;
                q[head].step = q[tail].step + 1;
                q[head ++].d = i;
                vis[npx][npy][i] = true;
                vis[cx][cy][i] = true;
            }
        }
        tail ++;
    }
}

int main()
{
    int i, j, k, tt;
    tt = ni();
    while(tt > 0)
    {
        init();
        cin >> n >> m;
        fi(n)
        fj(m)
        {
            cin >> mymap[i + 1][j + 1];
            if(mymap[i + 1][j + 1] == 'P')
            {
                px = i + 1;
                py = j + 1;
                mymap[i + 1][j + 1] = 'w';
            }
            else if(mymap[i + 1][j + 1] == 'M')
            {
                mx = i + 1;
                my = j + 1;
                mymap[i + 1][j + 1] = 'w';
            }
        }
        ans = -1;

        bfs();

        if(ans >= 0)
            cout << ans << endl;
        else
            cout << "NO" << endl;
        tt--;
    }
    return 0;
}
