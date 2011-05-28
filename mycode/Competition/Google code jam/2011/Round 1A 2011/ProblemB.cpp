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

const int maxn = 10000, maxm = 100;
int n, m;
string d[maxn], order[maxm];
bool t[maxn];
int tn;
bool u[26];

int comp(const void* p, const void* q)
{
    return *((int *)p) - *((int *)q);
}

int main( )
{
	int i, j, k, l, tt, ttt;
    char s[100],sl;

	freopen( "ProblemB.in", "r", stdin );
	freopen( "ProblemB.out", "w", stdout );

	scanf( "%d\n", &tt );
	for( ttt = 1; ttt <= tt; ++ ttt )
	{
		printf( "Case #%d:", ttt );

        int n = ni();
        int m = ni();
        fi(n) {
            cin >> d[i];
        }
        fi(m) {
            cin >> order[i];
        }

        fi(m)
        {
            int mj = 0,mans = -1;
            fj(n)
            {
                _(s,0);
                _(t,0);
                sl = d[j].size();
                tn = n;
                int ans = 0;
                int oi = -1;

                fk(n)
                {
                    if(d[k].size() != sl)
                        t[k] = 1,tn --;
                    else
                        fo(l,0,sl)
                            u[d[k][l]] = 1;
                }

                while(tn > 1)
                {
                    oi ++;
                    bool wr = 1;
                    while(!u[order[i][oi]]) oi ++;

                    fk(sl)
                        if(d[j][k] == order[i][oi])
                            s[k] = order[i][oi], wr = 0;
                    if(wr)
                        ans ++;
                    cout << ans << ' ' << order[i][oi];
                    cout << u[order[i][oi]] << endl;

                    _(u,0);
                    fk(n)
                    {
                        if(!t[k])
                        {
                            fo(l,0,sl)
                            {
                                if(s[l] > 0 && s[l] != d[k][l])
                                    break;
                            }
                            if(l < sl)
                                t[k] = 1, tn --;
                            else
                                fo(l,0,sl)
                                {

                                    u[d[k][l]] = 1;
                                    //if(d[k][l] == 'b')
                                        //cout << k;
                                }
                        }
                    }

                    cout << ' ' << tn << endl;

                    //return 0;
                }
                if(ans > mans)
                {
                    mans = ans;
                    mj = j;
                }
                cout << ans << endl;
            }
            cout << ' ' << d[mj];
        }
        cout << endl;
	}

	return 0;
}
