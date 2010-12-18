/*
ID: interne4
PROG: latin
LANG: C++
DATA: 2010.12.17
ALGO: Depth First Search
*/
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
int n,s;

void init()
{
	fin >> n;
	for(int i=1;i<=n;i++)
	{
		isY[i][i] = 1;
	}
}

void dfs(int x,int y)
{
	int i;
	if(x == n)
	{
		s ++;
		return ;
	}
	/*
	1 2 3 4 5
	1 2 3 4 5
	1 2 3 4 5
	1 2 3 4 5
	*/
	for(i=1;i<=n;i++)
	{
		if(!isX[i][x] && !isY[i][y])
		{
			isX[i][x] = 1;
			isY[i][y] = 1;
			if(y < n)
				dfs(x, y + 1);
			else
				dfs(x + 1, 1);
			isX[i][x] = 0;
			isY[i][y] = 0;
		}
	}
}

int main()
{
	int i,j,x,y;
	
	init();
	
	s = 0;
	dfs(1,1);
	fout << s << endl;
	return 0;
}
