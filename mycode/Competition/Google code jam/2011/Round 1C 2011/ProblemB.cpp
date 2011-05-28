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
#include <math.h>

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

const int maxn = 100010;
int n, l, h;
int p[maxn];


int main( )
{
	int i, j, k, tt, ttt,a;
    char s[100],sl;

	freopen( "ProblemB.in", "r", stdin );
	freopen( "ProblemB.out", "w", stdout );

	scanf( "%d\n", &tt );
	for( ttt = 1; ttt <= tt; ++ ttt )
	{
		printf( "Case #%d: ", ttt );

        cin >> n >> l >> h;

        _(p,0);
        fi(n)
        {
            cin >> a;
            j = 0;
            while(j <= h)
            {

                p[j += a] += 1;
            }
            j = 1;
            while(j < a)
            {
                if(a%j == 0)
                {

                    p[j] ++;
                }
                j ++;
            }
        }

        fo(i,l,h+1)
        {
            if(p[i] == n)
            {
                cout << i << endl;
                break;
            }
        }
        if(i > h)
            cout << "NO" << endl;
	}

	return 0;
}
