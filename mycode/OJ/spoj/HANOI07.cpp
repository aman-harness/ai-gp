/*
Problem:    681. Building the Tower
Judge:      spoj
Author:     Alchemist
Data:       2011/7/11
Category:   SEARCH
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
const int maxn = 3000 + 1, maxh = 60 + 1, maxm = 70 + 1;
ll f[maxn][maxh][maxm] = {0};
int n, m, h;

void expand(int n, int h, int m)
{
    if(m > n)
    {
        f[n][h][m] = 0;
        return ;
    }
    if(m == 0)
    {
        f[n][h][m] = 0;
        return ;
    }
    if(h == 1)
    {
        if(n >= m)
            f[n][h][m] = 1;
        else
            f[n][h][m] = 0;
        return ;
    }
    if(f[n-m][h-1][m+1] == -1)
        expand(n - m, h - 1, m + 1);
    if(f[n-m][h-1][m-1] == -1)
        expand(n - m, h - 1, m - 1);
    f[n][h][m] = f[n-m][h-1][m+1] + f[n-m][h-1][m-1];
    return ;
}

int main()
{
    //freopen("HANOI07.in", "r", stdin);
    //freopen("HANOI07.out", "w", stdout);
    int i, t;
    cin >> t;
    _(f,0xff);
    fi(t)
    {
        cin >> n >> h >> m;
        if(n > maxn) n = maxn - 1;
        if(f[n][h][m] == -1)
            expand(n, h, m);
        cout << f[n][h][m] << endl;
    }
    return 0;
}

