/*
Problem:    2003 noip tg
Judge:      tyvj
Author:     Alchemist
Date:       2011.8.29
Category:   Graph, Search
Difficulty: **
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
const int maxn = 200 + 10;
int w[maxn][maxn] = {0};
bool wt[maxn][maxn] = {0};
int c[maxn] = {0};
int u[maxn] = {0};
bool v[maxn] = {0};
bool isq[maxn] = {0};
int q[maxn] = {0}, h, t;
int n, p;

void init()
{
    int i, a, b;
    h = t = 0;
    cin >> n >> p;
    fi(n)
    {
        cin >> c[i + 1] >> u[i + 1];
        if(c[i + 1] > 0)
            q[t ++] = i + 1;
        else
            c[i + 1] = -u[i + 1];
    }
    fi(p)
    {
        cin >> a >> b;
        cin >> w[b][a];
        w[a][b] = w[b][a];
        wt[a][b] = wt[b][a] = 1;
    }
}

int main()
{
    int i, j, th;
    int yh, yt;
    init();
    do
    {
        yt = t;
        yh = h;
        //cout << h << ' ' << t << endl;
        do
        {
            th = q[h];
            if(c[th] <= 0)
                c[th] = 0;
            fo(i, 1, n+1)
                if(wt[th][i] && !v[i])
                {
                    c[i] += w[th][i] * c[th];
                    if(!isq[i])
                    {
                        q[t ++] = i;
                        isq[i] = 1;
                    }
                }
            v[th] = 1;
            h ++;
        }while(h < yt);
        if(t == yt)
            break;
    }while(1);

    bool  ans = 0;
    fo(i, 1, n + 1)
    {
        fo(j, yh, yt)
        {
            if(q[j] == i && c[i] > 0)
            {
                cout << i << ' ' << c[i] << endl;
                ans = 1;
            }
        }
    }
    if(!ans)
        cout << "NULL" << endl;
    return 0;
}
