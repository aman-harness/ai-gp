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

const int maxn = 1001;
double x,s,r,t,n;
struct WalkWay
{
    double b,e;
    double w;
};
vector<WalkWay> v;

bool myComp(WalkWay a, WalkWay b)
{
    return (a.w < b.w);
}

int main( )
{
	int i, j, k, tt, ttt;
	double le;
	WalkWay w,w1;
	freopen( "ProblemA.in", "r", stdin );
	freopen( "ProblemA.out", "w", stdout );

	scanf( "%d\n", &tt );

	cout << setprecision(6) << fixed;
	for( ttt = 1; ttt <= tt; ++ ttt )
	{
		printf( "Case #%d: ", ttt );

        v.clear();
        cin >> x >> s >> r >> t >> n;
        le = 0;
        fi(n)
        {
            cin >> w.b >> w.e >> w.w;
            w1.b = le;
            w1.e = w.b;
            w1.w = 0;
            if(w1.b < w1.e)
                v.pb(w1);
            le = w.e;
            v.pb(w);
        }
        if(le < x)
        {
            w1.b = le;
            w1.e = x;
            w1.w = 0;
            v.pb(w1);
        }

        sort(v.begin(),v.end(),myComp);

        double ans = 0, ti;
        fi(v.size())
        {
            ti = (v[i].e - v[i].b) / (v[i].w + r);
            if( ti < t)
            {
                t -= ti;
                ans += ti;
            }
            else if(t > 0)
            {
                ans += ((v[i].e - v[i].b) - t * (v[i].w + r))/(v[i].w + s) + t;
                t = 0;
            }
            else
            {
                ans += (v[i].e - v[i].b)/(v[i].w + s);
            }
        }

        cout << ans << endl;

	}
	return 0;
}
