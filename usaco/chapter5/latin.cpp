/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("latin.in");
ofstream fout("latin.out");

const int maxN = 7 + 1;
int latin[maxN][maxN] = {0};
int isX[maxN][maxN] = {0};
int isY[maxN][maxN] = {0};
int sx[maxM] = {0};
int sy[maxM] = {0};
int sc[maxM] = {0};
int n,sn;



void init()
{
	fin >> n;
}

int main()
{
	int i,j,x,y;
	
	init(0);
	
	sn = 1;
	sx[1] = 2;
	sy[1] = 1;
	sc[1] = 1;
	while(1)
	{
		x = sx[sn];
		y = sy[sn];
		
		if(sc[sn] > n)
			sn --;
		else
		{
			if(!isX[sc[sn]][x] && !isX[sc[sn]][y])
			{
				isX[sc[sn] - 1][x] = 0;
				isX[sc[sn] - 1][y] = 0;
				isX[sc[sn]][x] = 1;
				isX[sc[sn]][y] = 1;
				latin[x][y] = sc[sn];
				if(x < n)
				{
					sx[++ sn] = x + 1;
					sy[sn] = y;
				}
				else
				{
					sx[++ sn] = 1;
					sy[sn] = y + 1;
				}
				sc[sn] = 1;
				sc[sn - 1] ++;
				
			}
		}
	}
	
	return 0;
}
