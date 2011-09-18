/*
Problem:    2011/road
Judge:      NOI
Author:     Alchemist
Date:       2011.8.18
Category:   Graph
Difficulty: ***
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
const int maxn = 10000000 + 1;
vector<int> state[maxn];
int vis_rn[maxn] = {0};
int road[maxn][3];
int side_rn[maxn];
bool vis_r[maxn] = {0};
int n;

int q[maxn],h,t;
long long ans;

void bfs()
{
    int i;
    int ns, tr, t_rn;
    ans = 0;
    while(h > t)
    {
        tr = q[t];
        //cout << tr << ' ' << side_rn[tr] << endl;
        ans += ll(abs(n - side_rn[tr] * 2)) * road[tr][2];

        if(vis_rn[road[tr][0]])
            ns = road[tr][0];
        else if(vis_rn[road[tr][1]])
            ns = road[tr][1];
        else
            ns = -1;
        if(ns >= 0)
        {
            if(vis_rn[ns] == 1)
            {
                int rn = state[ns].size();
                int n_vis;
                t_rn = 0;
                fi(rn)
                    if(vis_r[state[ns][i]])
                    {
                        t_rn += side_rn[state[ns][i]];
                    }
                    else
                        n_vis = state[ns][i];
                vis_r[n_vis] = true;
                side_rn[n_vis] = t_rn + 1;
                vis_rn[road[n_vis][0]] --;
                vis_rn[road[n_vis][1]] --;
                q[h ++] = n_vis;
            }
        }
        t ++;
    }
}

void init()
{
    int i;
    n = ni();
    fi(n - 1)
    {
        scanf("%d%d%d", &road[i][0], &road[i][1], &road[i][2]);
        state[road[i][0]].pb(i);
        state[road[i][1]].pb(i);
        vis_rn[road[i][0]] ++;
        vis_rn[road[i][1]] ++;
    }
    h = 0;
    t = 0;
    fo(i,1,n+1)
    {
        if(vis_rn[i] == 1)
        {
            q[h++] = state[i][0];
            vis_r[state[i][0]] = true;
            side_rn[state[i][0]] = 1;

            vis_rn[road[state[i][0]][0]] --;
            vis_rn[road[state[i][0]][1]] --;
        }
    }
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    init();
    bfs();
    cout << ans << endl;
    return 0;
}
