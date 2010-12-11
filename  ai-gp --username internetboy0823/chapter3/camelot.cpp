/*
ID: interne4
PROG: camelot
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <memory.h>
#include <queue>
#define Abs(x) ((x)>0?(x):(-(x))) 
using namespace std;
ifstream fin("camelot.in");
ofstream fout("camelot.out");


struct point
{
	int x,y;
};

const int MaxR = 30 + 1,MaxC = 26 + 1;
const point pos[8]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
const int posN = 8;
int R,C,N;
unsigned char dist[MaxR][MaxC][MaxR][MaxC] = {0};

point king, knight[MaxR*MaxC];
int KToP[MaxR*MaxC][MaxR][MaxC] = {0};

inline int kingpath(int r,int c){ 
       return max(Abs(r-king.x),Abs(c-king.y)); 
} 
int ans;

void work()
{
	int i,j,k,n,m,sum;
	for(i=1;i<=R;i++)
	for(j=1;j<=C;j++)
	{
		k = 0;
		if(N > 0)
			sum = kingpath(i,j) + dist[i][j][knight[k].x][knight[k].y] + KToP[k][i][j];
		else
			sum = kingpath(i,j);
		if(sum < ans)
			ans = sum;
		for(n= max(king.x-2,0); n <= min(king.x+2,R); n++)
		{
			for(m= max(king.y-2,0); m <= min(king.y+2,R);m++)
			{
				for(k=0;k<N;k++)
				{
					sum = kingpath(n,m) + dist[n][m][knight[k].x][knight[k].y] + dist[n][m][i][j] + KToP[k][i][j];
					if(sum < ans)
						ans = sum;
				}
			}
		}
	}
}
	

void dis()
{
	int i,j,k;
	memset(dist,0xff,sizeof(dist));
	for(i=1;i<=R;i++)
	for(j=1;j<=C;j++)
	{
		queue<point> q;
		point start,newP;
		dist[i][j][i][j] = 0;
		start.x = i;start.y = j;
		q.push(start);
		do
		{
			start = q.front();
			q.pop();
			int l = dist[i][j][start.x][start.y];
			for(k=0;k<posN;k++)
			{
				newP.x = start.x + pos[k].x;
				newP.y = start.y + pos[k].y;
				if(newP.x > 0 && newP.y > 0 && newP.x <= R && newP.y <= C && dist[i][j][newP.x][newP.y] == 0xff)
				{
					dist[i][j][newP.x][newP.y] = l + 1;
					q.push(newP);
				}
			}
		}while(!q.empty());
	}
}

void init()
{
	int i,j;
	char ch;
	fin >> R >> C;
	fin >> ch >> king.x;
	king.y = ch - 'A' + 1;
	i = 0;
	while(!fin.eof())
	{
		fin >> ch;
		if(fin.eof())
			break;
		fin >> knight[i].x;
		knight[i++].y = ch - 'A' + 1;
	}
	N = i;
	
	dis();
	int k,sum;
	for(i=1;i<=R;i++)
	for(j=1;j<=C;j++)
	{
		sum = 0;
		for(k=0;k<N;k++)
		{
			sum += dist[i][j][knight[k].x][knight[k].y];
		}
		for(k=0;k<N;k++)
		{
			KToP[k][i][j] = sum - dist[i][j][knight[k].x][knight[k].y];
		}
	}
	ans = 10000000;
}

int main()
{
	init();
	work();
	fout << ans << endl;
    return 0;
}
