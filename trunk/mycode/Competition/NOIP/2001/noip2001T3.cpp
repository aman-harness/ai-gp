/*
Problem:    2001 noip tg
Judge:      tyvj
Author:     Alchemist
Date:       2011.8.23
Category:   Dynamic Programming
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
const int maxn = 200 + 10;
const int maxm = 50;

int g[maxn][maxn] = {0};
int d[maxn] = {0};
int f[maxm][maxn];
string str = "";
string word[10];
int n, m, s;

void init()
{

    int i,j,p;
    string rs;
    cin >> p >> m;
    fi(p)
    {
        cin >> rs;
        str += rs;
    }
    n = str.length();

    cin >> s;
    fi(s)
    {
        cin >> word[i];
    }
}

int main()
{
    /*
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    */
    int i, j, k;

    init();

    fi(n)
    {
        fj(s)
        {
            int len = word[j].length();
            if(len >= d[i] && d[i] != 0)
                continue;
            fk(len)
                if(word[j][k] != str[i + k])
                    break;
            if(k == len)
                d[i] = len;
        }
    }
    fi(n)
        fj(n)
        {
            fo(k, i, j + 1)
            {
                if(d[k] + k - 1 <= j && d[k] != 0)
                {

                    g[i][j] ++;
                }
            }
        }
    _(f,0xff);

    fo(i,1,m + 1)
        fj(n)
        {
            if(i == 1)
            {
                f[i][j] = g[0][j];
                continue;
            }
            fk(j)
            {
                if(f[i - 1][k] >= 0)
                    f[i][j] = max(f[i - 1][k] + g[k + 1][j], f[i][j]);
            }
        }
    cout << f[m][n-1] << endl;
    return 0;
}
