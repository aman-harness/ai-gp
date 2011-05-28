#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
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
//typedef map<string,int> msi;

const int maxn = 50 + 1, maxm = 50 + 1;
int n, m;
char map[maxn][maxm] = {0};
char a[maxn][maxm] = {0};

bool test1()
{
    int i,j;
        memset(a,0,sizeof(a));
        fi(n)
        {
            fj(m)
            {
                if(map[i][j] == '#' && a[i][j] == 0)
                {
                    a[i][j] = '/';
                    if(map[i+1][j] != '#' || a[i+1][j] || i+1 >= n)
                        return false;
                    a[i+1][j] = '\\';
                    if(map[i][j+1] != '#' || a[i][j+1] || j+1 >= m)
                        return false;
                    a[i][j+1] = '\\';
                    if(map[i+1][j+1] != '#' || a[i+1][j+1] || i+1 >= n || j+1 >= m)
                        return false;
                    a[i+1][j+1] = '/';
                }
                else if(map[i][j] == '.')
                    a[i][j] = '.';
            }
        }
    return true;
}

int main( )
{
	int i, j, k, l, tt, ttt;
    char s[100],sl;

	freopen( "ProblemA.in", "r", stdin );
	freopen( "ProblemA.out", "w", stdout );

	scanf( "%d\n", &tt );
	for( ttt = 1; ttt <= tt; ++ ttt )
	{
		printf( "Case #%d:", ttt );

        cin >> n >> m;
        fi(n)
        fj(m)
        {
            cin >> map[i][j];
        }

        if(!test1())
            cout << endl << "Impossible" << endl;
        else
        {
            cout << endl;
            fi(n)
            {
                fj(m)
                {
                    cout << a[i][j];
                }
                cout << endl;
            }

        }
	}

	return 0;
}
