/*
Problem:    2003 noip tg
Judge:      tyvj
Author:     Alchemist
Date:       2011.8.29
Category:   Simulation
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
const int maxM = 20 + 1, maxP = 100 + 1;
string name[maxM];
string day[7] = {"Monday.","Tuesday.","Wednesday.","Thursday.","Friday.","Saturday.","Sunday."};
struct Sentence
{
	int c;
	int p;
}s[maxM][maxP] = {0};
int sn[maxM] = {0};
int n,m,p;

int search(string str)
{
	for(int j=1;j<=m;j++)
		if(str == name[j])
			return j;
	return 0;
}

int wday(string str)
{
	for(int j=0;j<7;j++)
		if(str == day[j])
			return j;
	return -1;
}

void init()
{
	cin >> m >> n >> p;
	string word[10000];
	string sen;
	int i,j,wn,pz;
	for(i=1;i<=m;i++)
		cin >> name[i];
	getline(cin,sen);
	for(i=1;i<=p;i++)
	{
		getline(cin,sen);
		j = 0;
		wn = 0;
		while(sen.find(' ',j) != -1)
		{
			word[wn ++] = sen.substr(j , sen.find(' ',j) - j);
			j = sen.find(' ',j);
			while(sen[j] == ' ') j ++;
		}
		word[wn ++] = sen.substr(j , sen.size() - j);
		pz = search(word[0].erase(word[0].size() - 1, 1));
		if(wn == 4 && word[1] == "I" && word[2] == "am" && word[3] == "guilty." )
		{
			s[pz][++ sn[pz]].c = 0;
			s[pz][sn[pz]].p = pz;
		}
		else
		if(wn == 5 && word[1] == "I" && word[2] == "am" && word[3] == "not" && word[4] == "guilty.")
		{
			s[pz][++ sn[pz]].c = 1;
			s[pz][sn[pz]].p = pz;
		}
		else
		if(wn == 4 && word[2] == "is" && word[3] == "guilty.")
		{
			s[pz][++ sn[pz]].c = 0;
			s[pz][sn[pz]].p = search(word[1]);
			if(s[pz][sn[pz]].p == 0)
				-- sn[pz];
		}
		else
		if(wn == 5 && word[2] == "is" && word[3] == "not" && word[4] == "guilty.")
		{
			s[pz][++ sn[pz]].c = 1;
			s[pz][sn[pz]].p = search(word[1]);
			if(s[pz][sn[pz]].p == 0)
				-- sn[pz];
		}
		else
		if(wn == 4 && word[1] == "Today" && word[2] == "is")
		{
			s[pz][++ sn[pz]].c = 2;
			s[pz][sn[pz]].p = wday(word[3]);
			if(s[pz][sn[pz]].p == -1)
				-- sn[pz];
		}
	}
}


int main()
{
	int i,j,k,l,ns,nss;
	bool t,tt,tf,w;
	int ansname;
	bool ans = 0;
    init();
	for(i=1;i<=m;i++)
	{
		for(j=0;j<7;j++)
		{
			w = 0;
			ns = 0;
			nss = 0;
			for(k=1;k<=m;k++)
			{
				tt = 1;
				tf = 0;
				//cout << name[k] << ":";
				for(l=1;l<=sn[k];l++)
				{
					switch(s[k][l].c)
					{
						case 0:
							if(s[k][l].p == i)
								t = 1;
							else
								t = 0;
							break;

						case 1:
							if(s[k][l].p == i)
								t = 0;
							else
								t = 1;
							break;

						case 2:
							if(s[k][l].p == j)
								t = 1;
							else
								t = 0;
							break;
					}
					tt = tt && t;
					tf = tf || t;
					//cout << t << ' ';
				}
				if(sn[k] == 0)
				{
				    nss ++;
                    continue;
				}
				if(tf == 0)
					ns ++;
				else if(tt == 1);
				else{
					w = 1;
					break;
				}
			}
			//cout << endl;
			if(w)
				continue;
			if(ns <= n && n <= ns + nss)
			{
			    //cout << name[i] << endl;
			    if(ans && ansname != i)
			    {
                    cout << "Cannot Determine" << endl;
                    return 0;
			    }
				else
				{
					ansname = i;
				    ans = 1;
				}
			}
		}
	}
	if(ans)
        cout << name[ansname] << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}
