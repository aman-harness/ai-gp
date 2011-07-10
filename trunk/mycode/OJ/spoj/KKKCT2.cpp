/*
Problem:    6408. Counting Triangles 2
Judge:      spoj
Author:     Alchemist
Data:       2011/7/2
Category:   Math
Difficulty: ****
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
unsigned long long f[seg][seg] = {0}, fx[seg][maxn] = {0}, fy[maxn][seg] = {0};
unsigned long long ans[seg][seg] = {0}, ansx[seg][maxn] = {0}, ansy[maxn][seg] = {0};
int x ,y;

void init()
{
    int i,j,k,l,kk,ll,x,y;
    int im;
    im = (maxn - 1)/(seg - 1);
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
            kk = i*(seg-1) + k;
            ll = j*(seg-1) + l;
            f[k][l] = f[k-1][l] + f[k][l-1] - f[k-1][l-1];
            if(kk * 2 == ll || ll * 2 == kk)
                f[k][l] += 2;
            else if(!(kk * 2 < ll || ll * 2 < kk))
                f[k][l] += 4;
            ans[k][l] = ans[k-1][l] + ans[k][l-1] - ans[k-1][l-1] + f[k][l];
            //cout << k << ' ' << l << ' ' << ans[k][l] << endl;
        }
        //while(1);
        fo(k,0,seg)
        {
            fx[i+1][j*(seg-1)+k] = f[seg-1][k];
            fy[i*(seg-1)+k][j+1] = f[k][(seg-1)];
            ansx[i+1][j*(seg-1)+k] = ans[(seg-1)][k];
            ansy[i*(seg-1)+k][j+1] = ans[k][(seg-1)];
        }
    }
}

unsigned long long calc(int x,int y)
{
    int i,j,k,l,kk,ll;
    i = x / (seg - 1);
    j = y / (seg - 1);
    if(x == 10000 && y == 10000)
        return ansx[i][j*(seg-1)];
    fo(k,0,seg)
    {
        f[0][k] = fx[i][j*(seg-1)+k];
        f[k][0] = fy[i*(seg-1)+k][j];
        ans[0][k] = ansx[i][j*(seg-1)+k];
        ans[k][0] = ansy[i*(seg-1)+k][j];
    }
    int xn,yn;
    xn = x%(seg - 1) + 1;
    yn = y%(seg - 1) + 1;
    fo(k,1,xn)
    fo(l,1,yn)
    {
        kk = i * (seg - 1) + k;
        ll = j * (seg - 1) + l;
        f[k][l] = f[k - 1][l] + f[k][l - 1] - f[k - 1][l - 1];
        if(kk * 2 == ll || ll * 2 == kk)
            f[k][l] += 2;
        else if(!(kk * 2 < ll || ll * 2 < kk))
            f[k][l] += 4;
        ans[k][l] = ans[k - 1][l] + ans[k][l - 1] - ans[k - 1][l - 1] + f[k][l];
    }
    return ans[x%(seg - 1)][y%(seg - 1)];
}

int main()
{
    //freopen("KKKCT2.in", "r", stdin);
    //freopen("KKKCT2.out", "w", stdout);
    int i,t;
    init();
    t = ni();
    fi(t)
    {
        cin >> x >> y;
        cout << calc(x,y) << endl;
    }
}

