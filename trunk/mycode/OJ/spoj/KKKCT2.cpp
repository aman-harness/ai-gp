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
const int maxn = 10000 + 1,seg = 100 + 1;
unsigned long long f[seg][seg] = {0}, fx[seg][maxn] = {0}, fy[seg][maxn] = {0};
unsigned long long ans[seg][seg] = {0}, ansx[seg][maxn] = {0}, ansy[seg][maxn] = {0};
int x ,y;

void init()
{
    int i,j,k,l,x,y;
    int im;
    im = (maxn - 1)/(seg - 1) + 1;
    fo(i,0,im)
    fo(j,0,im)
    {
        fo(k,0,seg)
        {
            f[0][k] = fx[i][j*(seg-1)+k];
            f[k][0] = fy[i*(seg-1)+k][j];
            ans[0][k] = ansx[i][j*(seg-1)+k];
            ans[k][0] = ansy[i*(seg-1)+k][j];
        }
        fo(k,1,seg)
        fo(l,1,seg)
        {
            f[k][l] = f[k-1][l] + f[k][l-1] - f[k-1][l-1];
            if(k * 2 == l || l * 2 == k)
                f[k][l] += 2;
            else if(!(k * 2 < l || l * 2 < k))
                f[k][l] += 4;
            ans[k][l] = ans[k-1][l] + ans[k][l-1] - ans[k-1][l-1] + f[k][l];
        }
        fo(k,0,seg)
        {
            fx[i+1][j*(seg-1)+k] = f[seg-1][k];
            fy[i*(seg-1)+k][j+1] = f[k][(seg-1)];
            ansx[i+1][j*(seg-1)+k] = ans[(seg-1)][k];
            ansy[i*(seg-1)+k][j+1] = ans[k][(seg-1)];
        }
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

