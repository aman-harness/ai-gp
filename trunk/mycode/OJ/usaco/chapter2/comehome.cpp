/*
ID: interne4
PROG: comehome
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <memory.h>
using namespace std;
ifstream fin("comehome.in");
ofstream fout("comehome.out");

const int maxD = 100000000,maxRows = 52;
int n;
int adj[maxRows + 1][maxRows + 1]={0};				//a symmetric "adjacency" matrix 
int ans,ansI;

void init();

void work()
{
	int i,j,k;
	for(k=1;k<=maxRows;k++)
		for(i=1;i<=maxRows;i++)
			for(j=1;j<=maxRows;j++)
				if (adj[i][j] > adj[i][k] + adj[k][j])
					adj[i][j] = adj[i][k] + adj[k][j];
	
	ans = maxD;
	for(j=27;j<=maxRows-1;j++)
		if (adj[maxRows][j] < ans)
		{
			ans = adj[maxRows][j];
			ansI = j;
		}
}

int main()
{
	init();
	work();
	char ch;
	
	if(1 <= ansI && ansI <= 26)
		ch = ansI + 'a' - 1;
	else if(27 <= ansI && ansI <= 52)
		ch = ansI + 'A' - 27;
	fout << ch << ' ' << ans << endl;
	
    return 0;
}

void init()
{
	int i,j,l,r,rd;
	char ch;
	
	fin >> n;
	//input
	for(i=1;i<=maxRows;i++)
	for(j=1;j<=maxRows;j++)
	adj[i][j] = maxD;
	
	for(i=1;i<=n;i++)
	{
		fin >> ch;
		if('a' <= ch && ch <= 'z')
			l = ch - 'a' + 1;
		else if('A' <= ch && ch <= 'Z')
			l = ch - 'A' + 27;
		fin >> ch;
		if('a' <= ch && ch <= 'z')
			r = ch - 'a' + 1;
		else if('A' <= ch && ch <= 'Z')
			r = ch - 'A' + 27;
		fin >> rd;
		if(rd < adj[l][r])
			adj[r][l] = adj[l][r] = rd;
	}
	//init
}

