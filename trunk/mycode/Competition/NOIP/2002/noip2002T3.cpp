/*
Problem:    2002 noip tg
Judge:      tyvj
Author:     Alchemist
Date:       2011.8.26
Category:   Search
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

int main()
{
    double h,s1,v,l,k;
    int n;
    cin >> h >> s1 >> v >> l >> k >> n;

    double t1,t2,x1,x2;
    t1 = sqrt((h - k) / 5);
    t2 = sqrt(h / 5);
    x2 = s1 - v * t1 + l;
    x1 = s1 - v * t2;

    int xi1 = x1;
    int xi2 = x2;
    if(double(xi1) < x1 - 0.00001 || double(xi1) > x1 + 0.00001)
        xi1 ++;
    if(xi2 > n - 1)
        xi2 = n - 1;
    if(xi1 < 0)
        xi1 = 0;
    if(xi2 < xi1)
        xi1 = xi2 + 1;
    //100 500 10 10 1 1000
    cout << xi2 - xi1 + 1 << endl;
    return 0;
}
