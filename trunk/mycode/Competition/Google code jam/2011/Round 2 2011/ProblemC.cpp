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

const int maxn = 1001;

int prime[maxn] = {0}, pn = 0;
int p[maxn] = {0}, n;
int px[maxn] = {0};

void init()
{
    int i,j;
    for(i=2;i<=1000;i++)
    {
        for(j = 2;j <= sqrt(i); j++)
            if(i % j == 0)
                break;
        if(j > sqrt(i))
            prime[pn ++] = i;
    }
}

int main( )
{
	int i, j, k, tt, ttt, s ,a ,b;
	bool t;
	freopen( "ProblemC.in", "r", stdin );
	freopen( "ProblemC.out", "w", stdout );

    init();
	scanf( "%d\n", &tt );
	for( ttt = 1; ttt <= tt; ++ ttt )
	{
		printf( "Case #%d: ", ttt );
        n = ni();
        a = b = 0;
        _(p,0);
        if(n != 1)
            a = 1;
        for(i=1;i<=n;i++)
        {
            k = i;
            j = 0;
            s = 0;
            //_(px,0);
            t = 0;
            while(k > 1)
            {
                s = 0;
                while(k % prime[j] == 0 )
                {
                    k /= prime[j];
                    s ++;
                }
                if(p[j] < s)
                {
                    p[j] = s;
                    t = 1;
                }
                j ++;
            }
            if(t)
            {
                //cout << i << endl;
                a ++;
            }
        }

        _(p,0);
        for(i=n;i>=1;i--)
        {
            k = i;
            j = 0;
            s = 0;
            //_(px,0);
            t = 0;
            while(k > 1)
            {
                s = 0;
                while(k % prime[j] == 0 )
                {
                    k /= prime[j];
                    s ++;
                }
                if(p[j] < s)
                {
                    p[j] = s;
                    t = 1;
                }
                j ++;
            }
            if(t)
            {
                //cout << i << endl;
                b ++;
            }
        }

        cout << (a - b) << endl;
	}
	return 0;
}
