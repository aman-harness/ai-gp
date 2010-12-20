/*
ID: interne4
PROG: tour
LANG: C++
DATA: 2010.12.17
ALGO: Dynamic Programming
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("tour.in");
ofstream fout("tour.out");

const int maxN = 7 + 1;
int latin[maxN][maxN] = {0};
int isX[maxN][maxN] = {0};
int isY[maxN][maxN] = {0};
int sx[maxN * maxN] = {0};
int sy[maxN * maxN] = {0};
int sc[maxN * maxN] = {0};
int n,sn,s;

void init()
{
	fin >> n;
	for(int i=1;i<=n;i++)
	{
		isY[i][i] = 1;
	}
}

int main()
{
	int i,j,x,y;
	
	init();
	
	s = 0;
	
	sn = 1;
	sx[1] = 1;
	sy[1] = 1;
	sc[1] = 2;
	while(sn > 0)
	{
		x = sx[sn];
		y = sy[sn];
		
		if(x >= n)
		{
			s ++;/*
			for(i=1;i<n;i++)
			{
				for(j=1;j<=n;j++)
					fout << latin[i][j] << ' ';
				fout << endl;
			}
				fout << endl;
					*/
			sn --;
		}
		else
		{
			isX[sc[sn] - 1][sx[sn]] = 0;
			isY[sc[sn] - 1][sy[sn]] = 0;
			
			while((isX[sc[sn]][x] || isY[sc[sn]][y])&& sc[sn] <= n) sc[sn] ++;
			
			if(sc[sn] > n)
			{
				sn --;
			}
			else
			{
				isX[sc[sn]][x] = 1;
				isY[sc[sn]][y] = 1;
				latin[x][y] = sc[sn];
				sc[sn] ++;
				
				if(y < n)
				{
					sx[++ sn] = x;
					sy[sn] = y + 1;
				}
				else
				{
					sx[++ sn] = x + 1;
					sy[sn] = 1;
				}
				sc[sn] = 1;
				
			}
		}
	}
	
	fout << s << endl;
	return 0;
}
