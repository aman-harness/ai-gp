/*
Problem:    5464. Counting triangles
Judge:      spoj
Author:     Alchemist
Data:       2011/6/12
Category:   Math
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
const int maxn = 1000 + 1;
unsigned long long f[maxn][maxn] = {0}, ans[maxn][maxn] = {0};
int x ,y;

void init()
{
    int i,j;
    fo(i,1,maxn)
    fo(j,1,maxn)
    {
        f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1];
        if(i * 2 == j || j * 2 == i)
            f[i][j] += 2;
        else if(!(i * 2 < j || j * 2 < i))
            f[i][j] += 4;
        ans[i][j] = ans[i-1][j] + ans[i][j-1] - ans[i-1][j-1] + f[i][j];
    }
}

int main()
{
    //freopen("CT.in", "r", stdin);
    //freopen("CT.out", "w", stdout);
    int i,t;
    init();
    t = ni();
    fi(t)
    {
        cin >> x >> y;
        cout << ans[x][y] << endl;
    }
}
