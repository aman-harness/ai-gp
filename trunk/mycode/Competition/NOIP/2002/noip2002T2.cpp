/*
Problem:    2002 noip tg
Judge:      tyvj
Author:     Alchemist
Date:       2011.8.25
Category:   Search
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
const int maxn = 10;
string A,B,a[maxn],b[maxn];
char ac[maxn][30],bc[maxn][30];
int n;

void init()
{
    int i = 0;
    cin >> A >> B;
    fi(6)
    {
        ac[i][0] = '\0';
        if(scanf("%s",ac[i])==EOF) break;
        if(strlen(ac[i]) == 0) break;
        a[i] = string(ac[i]);
        bc[i][0] = '\0';
        if(scanf("%s",bc[i])==EOF) break;
        if(strlen(bc[i]) == 0) break;
        b[i] = string(bc[i]);
    }
    n = i;
}

bool is_ans = 0;
/*
void dfs(string str, int step)
{
    if(is_ans)
        return;
    if(str == B)
    {
        is_ans = 1;
        cout << step << endl;
        return ;
    }
    cout << str << endl;
    if(step == 10)
        return;
    int i, pos;
    fi(n)
    {
        pos = -1;
        while((pos = str.find(a[i], pos + 1)) != -1)
        {
            string s = str;
            s.replace(pos, a[i].length(), b[i]);
            //cout << s << endl;
            dfs(s, step + 1);
        }
    }
}*/

const int maxq = 100000;
bool hash[13200000] = {0};
string q[maxq];

// BKDR Hash Function
unsigned int BKDRHash(const char *str)
{
	unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
	unsigned int hash = 0;

	while (*str)
	{
		hash = hash * seed + (*str++);
	}

	return (hash & 0x7FFFFFFF);
}

void bfs()
{
    int i;
    int h, t;
    int step;
    int pos;
    string str;
    t = h = 0;
    q[t ++] = A;
    q[t ++] = "[]";
    step = 0;
    while(h < t)
    {
        str = q[h];
        if(str == B)
        {
            is_ans = true;
            cout << step << endl;
            break;
        }
        else if(str == "[]")
        {
            step ++;
            if(step == 11)
                break;
            q[t ++] = "[]";
        }
        else fi(n)
        {
            pos = -1;
            while((pos = str.find(a[i], pos + 1)) != -1)
            {
                string s = str;
                s.replace(pos, a[i].length(), b[i]);
                //cout << s << endl;
                int x = BKDRHash(s.c_str()) % 13131313;
                if(!hash[x])
                {
                    q[t ++] = s;
                    hash[x] = 1;
                }
            }
        }
        h ++;
    }
}

int main()
{
    init();
    //dfs(A,0);
    bfs();
    if(!is_ans)
        cout << "NO ANSWER!" << endl;
    return 0;
}
