/*
Problem:    2001 noip tg
Judge:      tyvj
Author:     Alchemist
Date:       2011.8.23
Category:   Graph & Geometry
Difficulty: ****
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
#include <queue>
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
const int maxs = 100 + 10;
int s,t,A,B,n;

struct point
{
    double x,y;
    friend double dist(point p1, point p2)
    {
        return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    }

    friend istream& operator >> (istream& input, point& p)
    {
        input >> p.x >> p.y;
        return input;
    }

    friend ostream& operator << (ostream& output, point& p)
    {
        output << '(' << p.x << ',' << p.y << ')';
        return output;
    }
};

struct city
{
    point p[4];
    double t;
}c[maxs];

const double E = 0.0001;
double adj[maxs * 4][maxs * 4];

void init()
{
    int i,j;
    double d1, d2 ,d3;
    point *pc, *p1, *p2;
    cin >> s >> t >> A >> B;
    fi(s)
    {
        cin >> c[i].p[0] >> c[i].p[1] >> c[i].p[2] >> c[i].t;
        d1 = dist(c[i].p[0], c[i].p[1]);
        d2 = dist(c[i].p[1], c[i].p[2]);
        d3 = dist(c[i].p[2], c[i].p[0]);
        if(d1 * d1 + d2 * d2 < d3 * d3 + E && d1 * d1 + d2 * d2 > d3 * d3 - E)
        {
            pc = &c[i].p[1];
            p1 = &c[i].p[0];
            p2 = &c[i].p[2];
        }
        else if(d1 * d1 + d3 * d3 < d2 * d2 + E && d1 * d1 + d3 * d3 > d2 * d2 - E)
        {
            pc = &c[i].p[0];
            p1 = &c[i].p[1];
            p2 = &c[i].p[2];
        }
        else if(d3 * d3 + d2 * d2 < d1 * d1 + E && d3 * d3 + d2 * d2 > d1 * d1 - E)
        {
            pc = &c[i].p[2];
            p1 = &c[i].p[1];
            p2 = &c[i].p[0];
        }

        c[i].p[3].x = p1 -> x - pc -> x + p2 -> x;
        c[i].p[3].y = p1 -> y - pc -> y + p2 -> y;

        //cout << c[i].p[3] << endl;
    }
    n = s * 4;
    fi(n)
        fj(n)
            adj[i][j] = dist(c[i/4].p[i%4], c[j/4].p[j%4]) * t;
    fi(s)
    {
        adj[i * 4 + 1][i * 4] = adj[i * 4][i * 4 + 1] = dist(c[i].p[0], c[i].p[1]) * c[i].t;
        adj[i * 4 + 2][i * 4 + 1] = adj[i * 4 + 1][i * 4 + 2] = dist(c[i].p[1], c[i].p[2]) * c[i].t;
        adj[i * 4 + 3][i * 4 + 2] = adj[i * 4 + 2][i * 4 + 3] = dist(c[i].p[2], c[i].p[3]) * c[i].t;
        adj[i * 4][i * 4 + 3] = adj[i * 4 + 3][i * 4] = dist(c[i].p[3], c[i].p[0]) * c[i].t;
        adj[i * 4 + 2][i * 4] = adj[i * 4][i * 4 + 2] = dist(c[i].p[0], c[i].p[2]) * c[i].t;
        adj[i * 4 + 3][i * 4 + 1] = adj[i * 4 + 1][i * 4 + 3] = dist(c[i].p[1], c[i].p[3]) * c[i].t;
    }

}
double INF = 100000000;

double ans;
double dis[maxs * 4];

void dijstra()
{
    double cost;
    int i,at;
    fi(n)
        dis[i] = INF;
    dis[(A - 1) * 4] = dis[(A - 1) * 4 + 1] = dis[(A - 1) * 4 + 2] = dis[(A - 1) * 4 + 3] = 0;
    ans = INF;

    priority_queue<pair<double, int> > q;
    q.push(mp(0, (A - 1) * 4));
    q.push(mp(0, (A - 1) * 4 + 1));
    q.push(mp(0, (A - 1) * 4 + 2));
    q.push(mp(0, (A - 1) * 4 + 3));
    while(!q.empty())
    {
        pair<double,int> pp = q.top();
        q.pop();
        cost = -pp.first;
        at = pp.second;
        if(dis[at] < cost)
            continue;
        fi(n)
            if(dis[i] > cost + adj[at][i])
                q.push( mp(-(dis[i] = cost + adj[at][i]) , i) );
    }
    ans = min(ans, dis[(B - 1) * 4]);
    ans = min(ans, dis[(B - 1) * 4 + 1]);
    ans = min(ans, dis[(B - 1) * 4 + 2]);
    ans = min(ans, dis[(B - 1) * 4 + 3]);
}

int main()
{
    int i,j,k,tti,tt;
    cin >> tt;
    cout << setprecision(1) << fixed;
    fo(tti,0,tt)
    {
        init();
        dijstra();
        cout << ans << endl;
    }
    return 0;
}
