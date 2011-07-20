/*
Problem:    202. Rockets
Judge:      spoj
Author:     Alchemist
Data:       2011/7/12
Category:   Graph Matching
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
const int maxn = 6 + 1;
int n;
int x[maxn] = {0};
bool is[maxn] = {0};

struct point
{
    double x,y,z;
}p[maxn],s,e;
double r[maxn] = {0};

double mv;

int expand(int step)
{
    int i, j;
    if(step == n)
    {
        double d, md, v;
        _(r,0);
        v = 0;
        fi(n)
        {
            md = abs(p[x[i]].x - s.x);
            md = min(abs(p[x[i]].x - e.x), md);
            md = min(abs(p[x[i]].y - s.y), md);
            md = min(abs(p[x[i]].y - e.y), md);
            md = min(abs(p[x[i]].z - s.z), md);
            md = min(abs(p[x[i]].z - e.z), md);
            fj(n)
            {
                if(j == x[i] || r[j] == 0) continue;
                d = sqrt((p[x[i]].x - p[j].x) * (p[x[i]].x - p[j].x) +
                         (p[x[i]].y - p[j].y) * (p[x[i]].y - p[j].y) +
                         (p[x[i]].z - p[j].z) * (p[x[i]].z - p[j].z)) - r[j];
                if(d > 0)
                    md = min(d, md);
                else
                    md = 0;
            }
            r[x[i]] = md;
            v += md * md * md * 4 / 3 * PI;
            //cout << x[i] << ' ';
        }
        //cout << endl;
        //cout << r[0] << ' ' << r[1] << ' ' << r[2] << endl;
        mv = max(v, mv);
        //cout << v << endl;
    }
    fi(n)
        if(!is[i])
        {
            is[i] = true;
            x[step] = i;
            expand(step + 1);
            is[i] = false;
        }
    return 0;
}

int main()
{
    //freopen("BALLOON.in", "r", stdin);
    //freopen("BALLOON.out", "w", stdout);
    int i, j, k, t;
    t = 1;
    cout << fixed << setprecision(0);
    while(1)
    {
        mv = 0;
        cin >> n;
        if(n == 0)
            break;
        cin >> s.x >> s.y >> s.z;
        cin >> e.x >> e.y >> e.z;
        fi(n)
        {
            cin >> p[i].x >> p[i].y >> p[i].z;
            if(p[i].x < min(s.x, e.x) || p[i].x > max(s.x, e.x) ||
               p[i].y < min(s.y, e.y) || p[i].y > max(s.y, e.y) ||
               p[i].z < min(s.z, e.z) || p[i].z > max(s.z, e.z))
                i --, n --;
        }
        expand(0);
        cout << "Box " << t ++ << ": " << abs(s.x - e.x) * abs(s.y - e.y) * abs(s.z - e.z) - mv << endl;
    }
    return 0;
}

