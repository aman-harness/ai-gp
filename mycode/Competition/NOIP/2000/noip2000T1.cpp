/*
Problem:    noip 2000 tg
Judge:      tyvj
Author:
Date:
Category:
Difficulty:
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
const int maxn = 1000;
string str = "0123456789ABCDEFGHIJKLMN";



int main()
{
    int a[maxn] = {0};
    int n, r, i, temp, k;
    cin >> n >> r;
    cout << n << "=";

    i = 0;
    do
    {
        temp = n / r;
        a[i] = n % r;
        if(a[i] < 0)
        {
            a[i] -= r;
            temp ++;
        }
        n = temp;
        i ++;
    }while(n != 0);

    for(k = i - 1; k >= 0 ; k --)
        cout << str[a[k]];
    cout << "(base" << r << ")" << endl;
    return 0;
}

/*
不要死想一条路。
*/
