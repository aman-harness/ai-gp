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

const int maxn = 1000001;
long long l, t, n ,c;
long long dis[maxn];
long long d[maxn],dn;
long long ans = 0;
int comp(const void* p, const void* q)
{
    return *((long long *)q) - *((long long *)p);
}

int main( )
{

	long long i, j, k, a, tt, ttt;
    char s[100],sl;

	freopen( "ProblemC.in", "r", stdin );
	freopen( "ProblemC.out", "w", stdout );

	scanf( "%d\n", &tt );
	for( ttt = 1; ttt <= tt; ++ ttt )
	{
		printf( "Case #%d: ", ttt );

        ans = 0;
        cin >> l >> t >> n >> c;
        fi(c) {
            cin >> a;
            for(k = 0; k*c+i < n; k ++)
            {
                dis[k*c+i] = a;
                ans += a*2;
            }
        }
        dn = 0;
        long long tdis = 0;
        fi(n)
        {
            tdis += dis[i];
            if(tdis > t/2)
            {
                if(tdis - t/2 > dis[i])
                    d[dn ++] = dis[i];
                else
                    d[dn ++] = tdis - t/2;
            }
        }
        qsort(d,dn,sizeof(d[0]),comp);

        if(l < dn) dn = l;
        fi(dn)
            ans -= d[i];
        cout << ans << endl;
	}

	return 0;
}
