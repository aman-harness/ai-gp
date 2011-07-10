/*
Problem:    8. Complete the Sequence!
Judge:      spoj
Author:     Alchemist
Data:       2011/7/10
Category:   Math
Difficulty: **
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
const int maxn = 100 + 1;
int n,m;
int f[maxn][maxn] = {0};

int main()
{
    //freopen("CMPLS.in", "r", stdin);
    //freopen("CMPLS.out", "w", stdout);
    int i, j, k, t;
    t = ni();
    fi(t)
    {
        _(f,0);
        cin >> n >> m;
        fj(n)
            cin >> f[0][j];
        fj(n)
        {
            if(j == 0) continue;
            fk(n-j)
                f[j][k] = f[j-1][k+1] - f[j-1][k];
        }

        fj(n)
        {
            fk(m)
                f[n-j-1][j+k+1] = f[n-j-1][j+k] + f[n-j][j+k];
        }


        fo(j, n, n + m - 1)
        {
            cout << f[0][j] << ' ';
        }
        cout << f[0][n + m - 1] << endl;
    }
}

