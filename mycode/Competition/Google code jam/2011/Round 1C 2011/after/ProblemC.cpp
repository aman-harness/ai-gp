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
#define fod(a,b,c) for( a = ( b ) - 1; a >= ( c ); -- a )

#define fr(a,b) fo( a, 0, ( b ) )
#define frd(a,b) fod( a, ( b ), 0 )
#define fi(a) fr( i, ( a ) )
#define fid(a) frd( i, ( a ) )
#define fj(a) fr( j, ( a ) )
#define fjd(a) frd( j, ( a ) )
#define fk(a) fr( k, ( a ) )
#define fkd(a) frd( k, ( a ) )
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

const int maxn = 10010;
const ll maxe = 1e16;
ll n, nn, l, h;
ll num[maxn] = {0};
ll gcd[maxn] = {0};
ll lcm[maxn] = {0};


ll fgcd(ll a, ll b)
{
    while(1)
    {
        a = a % b;
		if( a == 0 )
			return b;
		b = b % a;
        if( b == 0 )
			return a;
    }
}

ll flcm(ll a, ll b)
{
    return a / fgcd(a,b) * b;
}

ll yu(ll mul,ll l, ll h)
{
    ll j;
    bool isa = 0;
    for(j = 1; j * j <= mul; j ++)
    {
        if(mul % j == 0)
        {
            if((mul/j) >= l  && (mul/j) <= h)
            {
                h = mul/j;
                isa = 1;
            }
            if(j >= l  && j <= h)
            {
                h = j;
                isa = 1;
            }
        }
    }
    if(isa)
        return h;
    else
        return -1;
}

int main( )
{
	ll i, j, k, tt, ttt,a;

	freopen( "ProblemC.in", "r", stdin );
	freopen( "ProblemC.out", "w", stdout );

	cin >> tt;
	for( ttt = 1; ttt <= tt; ++ ttt )
	{
		printf( "Case #%d: ", ttt );

        cin >> n >> l >> h;

        //_(num,0);
        fi(n)
        {
            cin >> num[i];
        }
        nn = n;
        sort(&num[0],&num[n]);
        lcm[0] = num[0];
        for(i = 1; i < n; i ++)
        {
            lcm[i] = flcm(lcm[i-1], num[i]);
            if(lcm[i] >= maxe || lcm[i] < lcm[i - 1])
            {
                nn = i;
                break;
            }
        }

        gcd[n] = num[n-1];
        fid(n)
        {
            gcd[i] = fgcd(gcd[i+1], num[i]);
        }/*
        cout << endl;
        fi(n)
        {
            cout << lcm[i] << ' ' << gcd[i+1] << endl;
        }
        cout << endl;*/

        ll mul, ans;
        bool isa = 0;

        ans = maxe;

        if(l == 1)
        {
            isa = 1;
            ans = 1;
        }
        if(!isa)
        {
            if(gcd[0] >= l)
            {
                mul = gcd[0];
                ans = yu(mul, l, h);
                if(ans != -1)
                    isa = 1;
            }
        }
        if(!isa)
        fi(nn)
        {
            if(gcd[i+1] % lcm[i] == 0 && gcd[i+1] >= l && lcm[i] <= h)
            {
                mul = gcd[i+1] / lcm[i];
                ans = yu(mul, (l - 1)/lcm[i] + 1, h/lcm[i]);
                if(ans != -1)
                {
                    isa = 1;
                    ans *= lcm[i];
                    break;
                }
            }
        }

        if(!isa && nn == n)
        {
            ans = ((l - 1) / lcm[n-1] + 1) * lcm[n-1];
            if(ans >= l && ans <= h)
            {
                isa = 1;
            }
        }

        if(isa)
            cout << ans << endl;
        else
            cout << "NO" << endl;
        //cout << tt <<  endl;
	}

	return 0;
}
