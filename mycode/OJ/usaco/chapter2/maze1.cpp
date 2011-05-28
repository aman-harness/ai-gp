/*
ID: interne4
PROG: maze1
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
ifstream fin("maze1.in");
ofstream fout("maze1.out");

const int maxN = 200;
int w,h;
bool map[maxN][maxN][4]={0};
const short dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int door[10][2]={0},doorN = 0;
//bool gone[maxN][maxN]={0};
int minStep[maxN][maxN]={0};

void dfs(int x,int y,int n)
{
	if(n < minStep[x][y])
		minStep[x][y] = n;
	else
		return;
	
	for(int i=0;i<4;i++)
	{
		if(map[x][y][i])
			dfs(x + dir[i][0],y + dir[i][1],n+1);
	}
}

void init();

int main()
{
	int i,j,k;
	int maxX,ans;
	ans = maxN*maxN;
	init();
	memset(minStep,maxN*maxN,sizeof(minStep));
	
	for(k=0;k<doorN;k++)
	{
		dfs(door[k][0],door[k][1],1);
		maxX = 0;
		for(i=1;i<=h;i++)
			for(j=1;j<=w;j++)
			{
				if(minStep[i][j] > maxX)
					maxX = minStep[i][j];
			}
		if(maxX < ans)
			ans = maxX;
	}
	fout << ans << endl;
    return 0;
}

void init()
{
	int i,j;
	char ch;
	fin >> w >> h;
	fin.get(ch);
	for(i=1;i<=h;i++)
	{
		for(j=1;j<=w;j++)
		{
			fin.get(ch);
			fin.get(ch);
			if(ch == ' ')
			{
				map[i-1][j][2] = 1;
				map[i][j][0] = 1;
			}
		}
		fin.get(ch);
		fin.get(ch);
		for(j=1;j<=w;j++)
		{
			fin.get(ch);
			if(ch == ' ')
			{
				map[i][j-1][1] = 1;
				map[i][j][3] = 1;
			}
			fin.get(ch);
		}
		fin.get(ch);
		if(ch == ' ')
		{
			map[i][w][1] = 1;
		}
		fin.get(ch);
	}
	for(j=1;j<=w;j++)
	{
		fin.get(ch);
		fin.get(ch);
		if(ch == ' ')
		{
			map[h][j][2] = 1;
		}
	}
	fin.get(ch);
	fin.get(ch);
	// Search Door
	for(i=1;i<=w;i++)
	{
		if(map[1][i][0])
		{
			door[doorN][0] = 1;
			door[doorN++][1] = i;
		}
		if(map[h][i][2])
		{
			door[doorN][0] = h;
			door[doorN++][1] = i;
		}
	}
	for(i=1;i<=h;i++)
	{
		if(map[i][1][3])
		{
			door[doorN][0] = i;
			door[doorN++][1] = 1;
		}
		if(map[i][w][1])
		{
			door[doorN][0] = i;
			door[doorN++][1] = w;
		}
	}
	/*
	for(i=1;i<=h;i++)
	{
		for(j=1;j<=w;j++)
			fout << map[i][j][0] << ' ';
		fout << endl;
	}
	fout << endl;
	for(i=1;i<=h;i++)
	{
		for(j=1;j<=w;j++)
			fout << map[i][j][1] << ' ';
		fout << endl;
	}
	fout << endl;
	for(i=1;i<=h;i++)
	{
		for(j=1;j<=w;j++)
			fout << map[i][j][2] << ' ';
		fout << endl;
	}
	fout << endl;
	for(i=1;i<=h;i++)
	{
		for(j=1;j<=w;j++)
			fout << map[i][j][3] << ' ';
		fout << endl;
	}
	fout << endl;
	*/
}






